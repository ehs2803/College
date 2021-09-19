using System;
class midterm_2
{
    public static void Main()
    {
        Console.Write("1~500 사이의 완전수 : ");
        for (int i = 1; i <= 500; i++)
        {
            int sum = 0;
            for (int j = 1; j <= i; j++)
            {
                if (i % j == 0) sum += j;
            }
            sum -= i;
            if (sum == i) Console.Write(i + " ");
        }
        Console.WriteLine();
    }
}