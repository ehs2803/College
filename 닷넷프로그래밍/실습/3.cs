using System;
class Exercisech2_12_1
{
    public static void Main()
    {
        //12-1
        int a = 10, b = 5, c = 6;
        double l = (a + b + c) / 2;
        double s = Math.Sqrt(Math.Pow(l - a, 2) + Math.Pow(l - b, 2) + Math.Pow(l - c, 2));

        Console.WriteLine("s = " + s + ", l = " + l);

        //12-2
        double x = 1, y = 2, n = 3, d = 4;
        double z;
        z = Math.Log(Math.Pow(x - y, n));
        z = Math.Abs(Math.Pow(x, 2) - Math.Pow(y, 2));
        z = Math.Sqrt(Math.Pow(x, 2) + Math.Pow(y, 2));
        z = Math.Exp(d * Math.Pow(x, 2));

        //12-3
        double S, original = 50000, rate = 0.05, period = 50;
        S = original * Math.Pow(1 + rate, period);

        //12-4
        double fahrenheit, celsius = 30;
        fahrenheit = (9 / 5) * celsius + 32;

        //12-5
        double H = 170.5, W = 60;
        double SW = (H - 100) * 0.9;
        double B = (W / SW) * 100;

        //12-6
        double R1 = 5, R2 = 2, R3 = 4;
        double R;
        R = R1 + R2 + R3;
        R = 1 / ((1 / R1) + (1 / R2) + (1 / R3));

        //12-7
        double r = 4.5;
        double V = (4 / 3) * 3.141592 * Math.Pow(r, 3);
        S = 4 * 3.141592 * Math.Pow(r, 2);

        //12-8
        string buffer = Console.ReadLine();
        int year = int.Parse(buffer);

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            Console.WriteLine(year + "년은 윤년입니다.");
        else
            Console.WriteLine(year + "년은 윤년이 아닙니다.");

        //12-9
        string buffer1 = Console.ReadLine(); //buffer = "1 2 3"
        string[] bufferArray = buffer1.Split(" "); // bufferArray = {"1", "2", "3"}
                                                   //int aa = int.Parse(bufferArray[0]);
        int[] intArr = new int[bufferArray.Length];
        for (int i = 0; i < bufferArray.Length; i++)
        {
            intArr[i] = int.Parse(bufferArray[i]);
        }
        int best = intArr[0];
        for (int i = 0; i < intArr.Length; i++)
        {
            if (intArr[i] > best) best = intArr[i];
        }
        Console.WriteLine("the biggest number is " + best);

        //12-10
        Console.WriteLine("+∞ + +∞ = " + (double.PositiveInfinity + double.PositiveInfinity));
        Console.WriteLine("+∞ - +∞ = " + (double.PositiveInfinity - double.PositiveInfinity));
        Console.WriteLine("-∞ + -∞ = " + (double.NegativeInfinity + double.NegativeInfinity));
        Console.WriteLine("-∞ - -∞ = " + (double.NegativeInfinity - double.NegativeInfinity));
        Console.WriteLine("0.0 / 0.0 =" + (0.0 / 0.0));
        Console.WriteLine("double.MaxValue / +∞ = " + (double.MaxValue / double.PositiveInfinity));
    }
}
/*
+∞ + +∞ = ∞
+∞ - +∞ = NaN
-∞ + -∞ = -∞
-∞ - -∞ = NaN
0.0 / 0.0 =NaN
double.MaxValue / +∞ = 0
*/