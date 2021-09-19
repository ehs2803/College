using System;
class ConditionalOperatorApp
{
    public static void Main()
    {
        int a, b, c;
        int m;
        Console.Write("Enter three numbers : ");
        a = Console.Read() - '0';
        b = Console.Read() - '0';
        c = Console.Read() - '0';
        m = (a > b) ? a : b;
        m = (m > c) ? m : c;
        Console.WriteLine("The largest number = " + m);
    }
}