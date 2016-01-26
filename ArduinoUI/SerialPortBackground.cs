using System;
using System.ComponentModel;
using System.IO.Ports;
using System.Threading;
using Newtonsoft.Json;

namespace ArduinoUI
{
    public class SerialPortBackground : IDisposable
    {
        private readonly Action<SerialPortFrame> _onFrameReadAction;
        private readonly BackgroundWorker _worker = new BackgroundWorker();

        public SerialPortBackground(Action<SerialPortFrame> onFrameReadAction)
        {
            _onFrameReadAction = onFrameReadAction;
            _worker.DoWork += worker_DoWork;
            _worker.WorkerSupportsCancellation = true;
        }

        public void OpenPort()
        {
            _port = new SerialPort("COM3", 9600);
            _port.Open();

            _worker.RunWorkerAsync();
        }

        void worker_DoWork(object sender, DoWorkEventArgs e)
        {
            while (true)
            {
                try
                {
                    if (e.Cancel)
                        return;

                    var frame = _port.ReadLine();

                    if (!string.IsNullOrWhiteSpace(frame) && frame != _oldFrame)
                    {
                        HandleFrame(frame);
                    }
                }
                catch (Exception)
                {
                    // ignored
                }

                Thread.Sleep(100);
            }
        }

        private void HandleFrame(string frameText)
        {
            var frame = JsonConvert.DeserializeObject<SerialPortFrame>(frameText);

            _onFrameReadAction(frame);

            _oldFrame = frameText;
        }

        public void SendFrame()
        {
            //port.WriteLine(e.NewValue.ToString());
        }

        private string _oldFrame;

        private SerialPort _port;

        public void Dispose()
        {
            _worker.CancelAsync();
            _port.Dispose();
        }
    }
}