using System;
class Temperature
{
    double degree;
    public Temperature(double degree)
    {
        this.degree = degree;
    }
    public double Degree
    { get { return degree; } }
}
class Celsius : Temperature
{
    public Celsius(double t) : base(t)
    { }
    public static explicit operator Celsius(double t)//double to Celsius
    {
        Celsius c = new Celsius(t);
        return c;
    }

    public static explicit operator Celsius(Fahrenheit f)//fahrenheit to Celsius
    {
        double d = (double)f;  // 한번만 써주면 되는데...Why
        d = (d - 32) * 5 / 9;

        Celsius c = (Celsius)d;
        return c;
    }

    public static explicit operator double(Celsius c)
    {
        return c.Degree;
    }

}
class Fahrenheit : Temperature
{
    public Fahrenheit(double t) : base(t)
    { }
    public static implicit operator Fahrenheit(double t)//double to Fahrenheit
    {
        Fahrenheit f = new Fahrenheit(t);
        return f;
    }
    public static explicit operator Fahrenheit(Celsius c)//???
    {
        double d = (double)c;
        d = 9 / 5 * d + 32;

        Fahrenheit f = (Fahrenheit)d;
        return f;
    }
    public static explicit operator double(Fahrenheit f)
    {
        return f.Degree;
    }

}
class MainApp
{
    static void Main(string[] args)
    {

        double d1, d2;
        Console.Write("온도를 입력하세요 : ");
        d1 = double.Parse(Console.ReadLine());

        Celsius T5 = (Celsius)d1;
        Console.WriteLine($"1) Double to Celsius :{T5.Degree}");

        Fahrenheit T4 = new Fahrenheit(d1);
        Celsius T6 = (Celsius)T4;
        Console.WriteLine($"2) Fahrenheit to Celsius :{T6.Degree:f2}");

        d2 = (double)T6;
        Console.WriteLine($"3) Celsius to double :{d2:f2}");


        Fahrenheit T8 = (Fahrenheit)d1;
        Console.WriteLine($"4) Double to Fahrenheit :{T8.Degree}");

        Fahrenheit T9 = (Fahrenheit)T6;
        Console.WriteLine($"5) Celsius to Fahrenheit :{T9.Degree:f2}");

        d2 = (double)T9;
        Console.WriteLine($"6) Fahrenheit to double :{d2:f2}");
    }
}