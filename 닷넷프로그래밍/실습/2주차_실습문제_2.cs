using System;
class AnotherBlockApp
{
    public static void Main()
    {
        int x = 1;
        {
            int y = 2;
            Console.WriteLine("Block 1: x = " + x + ", y = " + y);
        }
        {
            int y = 3;
            Console.WriteLine("Block 1: x = " + x + ", y = " + y);
        }
    }
}