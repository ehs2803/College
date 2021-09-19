using System;
public class Exercisech3_10_1
{
    static int MethodA(int x, int y)
    {
        while (x != y)
            if (x > y) x -= y;
            else y -= x;
        return x;
    }
    public static void Main()
    {
        int i, j;
        int a, b;

        Console.Write("Enter first Number: ");
        i = int.Parse(Console.ReadLine());
        Console.Write("Enter second Number: ");
        j = int.Parse(Console.ReadLine());
        a = MethodA(i, j);
        Console.WriteLine("a = " + a);
        b = (i / a) * (j / a) * a;
        Console.WriteLine("b = " + b);
    }
    
}