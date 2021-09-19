using System;
class ExerciseCh2_10_5
{
    public static void Main()
    {
        Console.WriteLine("number of bits = " + f(0x37));
    }
    public static int f(int n)
    {
        int c;
        for (c = 0; n != 0; n >>= 1)
        {
            if ((n & 1) == 1) c++;
        }
        return c;
    }
}
/*
number of bits = 5
*/