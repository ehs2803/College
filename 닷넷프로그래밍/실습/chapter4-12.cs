using System;
class Complex
{
    public double real;
    public double image;
    public Complex(double num)
    {
        real = num;
        image = num;
    }
    public Complex(double real, double image)
    {
        this.real = real;
        this.image = image;
    }
    override public string ToString()
    {
        return "(" + real + ", " + image + "i)";
    }
    public static Complex AddComplex(Complex x1, Complex x2)
    {
        Complex x = new Complex(0.0, 0.0);
        x.real = x1.real + x2.real;
        x.image = x1.image + x2.image;
        return x;
    }
    public static Complex SubComplex(Complex x1, Complex x2)
    {
        Complex x = new Complex(0.0, 0.0);
        x.real = x1.real - x2.real;
        x.image = x1.image - x2.image;
        return x;
    }
    public static Complex MulComplex(Complex x1, Complex x2)
    {
        Complex x = new Complex(0.0, 0.0);
        x.real = x1.real * x2.real - x1.image * x2.image;
        x.image = x1.real * x2.image + x1.image * x2.real;
        return x;
    }
    public static Complex DivComplex(Complex x1, Complex x2)
    {
        Complex x = new Complex(0.0, 0.0);
        x.real = (x1.real * x2.real + x1.image * x2.image) / (Math.Pow(x2.real, 2) + Math.Pow(x2.image, 2));
        x.image = (x1.image * x2.real - x1.real * x2.image) / (Math.Pow(x2.real, 2) + Math.Pow(x2.image, 2));
        return x;
    }
}
class EX1
{
    public static void Main()
    {
        Complex c, c1, c2;
        c1 = new Complex(1, 2);
        c2 = new Complex(3, 4);
        Console.WriteLine("c1 = {0}, c2 = {1}\n", c1.ToString(), c2.ToString());

        Console.WriteLine("[덧셈 테스트]");
        c = Complex.AddComplex(c1, c2);
        Console.WriteLine("{0} + {1} = {2}\n", c1.ToString(), c2.ToString(), c.ToString());

        Console.WriteLine("[뺄셈 테스트]");
        c = Complex.SubComplex(c1, c2);
        Console.WriteLine("{0} - {1} = {2}\n", c1.ToString(), c2.ToString(), c.ToString());

        Console.WriteLine("[곱셈 테스트]");
        c = Complex.MulComplex(c1, c2);
        Console.WriteLine("{0} * {1} = {2}\n", c1.ToString(), c2.ToString(), c.ToString());

        Console.WriteLine("[나눗셈 테스트]");
        c = Complex.DivComplex(c1, c2);
        Console.WriteLine("{0} / {1} = {2}\n", c1.ToString(), c2.ToString(), c.ToString());
    }
}