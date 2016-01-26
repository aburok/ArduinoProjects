using System.Runtime.Serialization;
using Newtonsoft.Json;

namespace ArduinoUI
{
    [DataContract]
    public class SerialPortFrame
    {
        [DataMember(Name = "lx")]
        public int LeftX { get; set; }
        [DataMember(Name = "ly")]
        public int LeftY { get; set; }

        [DataMember(Name = "lsw")]
        public bool LeftSwitch { get; set; }

        [DataMember(Name = "rx")]
        public int RightX { get; set; }
        [DataMember(Name = "ry")]
        public int RightY { get; set; }

        [DataMember(Name = "rsw")]
        public bool RightSwitch { get; set; }

        public override string ToString()
        {
            return string.Format("Left [{0:000},{1:000}, {2}], Right [{3:000},{4:000}, {5}]",
                LeftX, LeftY, LeftSwitch,
                RightX, RightY, RightSwitch);
        }
    }
}