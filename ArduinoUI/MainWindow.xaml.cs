using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace ArduinoUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow
    {
        private readonly SerialPortBackground _serialPortWorker;

        public MainWindow()
        {
            InitializeComponent();

            _serialPortWorker = new SerialPortBackground(WorkerReadFrameAction);
        }

        private int PointerSize = 10;
        public void WorkerReadFrameAction(SerialPortFrame frame)
        {
            Dispatcher.Invoke(() =>
            {
                MonitorOutput.Text = frame.ToString();

                var leftX = frame.LeftX.Map(0, 1023, 0, (int)LeftJoyStickCanvas.ActualWidth - PointerSize);
                var leftY = frame.LeftY.Map(0, 1023, 0, (int)LeftJoyStickCanvas.ActualHeight - PointerSize);
                Canvas.SetLeft(LeftJoyStickPointer, leftX);
                Canvas.SetTop(LeftJoyStickPointer, leftY);
                LeftJoyStickCanvas.Background = frame.LeftSwitch
                    ? Brushes.LightGreen
                    : Brushes.LightGray;

                var rightX = frame.RightX.Map(0, 1023, 0, (int)RightJoyStickCanvas.ActualWidth - PointerSize);
                var rightY = frame.RightY.Map(0, 1023, 0, (int)RightJoyStickCanvas.ActualHeight - PointerSize);
                Canvas.SetLeft(RightJoyStickPointer, rightX);
                Canvas.SetTop(RightJoyStickPointer, rightY);
                RightJoyStickCanvas.Background = frame.RightSwitch 
                    ? Brushes.LightGreen 
                    : Brushes.LightGray;
            });
        }

        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            _serialPortWorker.OpenPort();
        }

        private void MainWindow_OnClosing(object sender, CancelEventArgs e)
        {
            _serialPortWorker.Dispose();
        }

        private void Slider_OnValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
        }
    }
}
