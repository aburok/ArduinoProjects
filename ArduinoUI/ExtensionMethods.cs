namespace ArduinoUI
{
    public static class ExtensionMethods
    {
        public static decimal Map(this decimal value, decimal fromSource, decimal toSource, decimal fromTarget, decimal toTarget)
        {
            return (value - fromSource) / (toSource - fromSource) * (toTarget - fromTarget) + fromTarget;
        }
        public static int Map(this int value, decimal fromSource, decimal toSource, decimal fromTarget, decimal toTarget)
        {
            return (int)((decimal)value).Map(fromSource, toSource, fromTarget, toTarget);
        }

        //public static int Map(this int value, int fromSource, int toSource, int fromTarget, int toTarget)
        //{
        //    return (value - fromSource) / (toSource - fromSource) * (toTarget - fromTarget) + fromTarget;
        //}
    }
}