using System;
class ExerciseCh2_9_1
{
    public static void Main()
    {
        Console.WriteLine("Minimum integer: " + int.MinValue);
        Console.WriteLine("Maximum integer: " + Int32.MaxValue);
        Console.WriteLine("Minimum long: " + long.MinValue);
        Console.WriteLine("Maximum long: " + Int64.MaxValue);
        Console.WriteLine("Minimum float: " + float.MinValue);
        Console.WriteLine("Maximum float: " + Single.MaxValue);
        Console.WriteLine("Minimum double: " + double.MinValue);
        Console.WriteLine("Maximum double: " + Double.MaxValue);
    }
}
/*
Minimum integer: -2147483648
Maximum integer: 2147483647
Minimum long: -9223372036854775808
Maximum long: 9223372036854775807
Minimum float: -3.4028235E+38
Maximum float: 3.4028235E+38
Minimum double: -1.7976931348623157E+308
Maximum double: 1.7976931348623157E+308
*/