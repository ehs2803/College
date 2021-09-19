using System;
using System.CodeDom.Compiler;

class Fraction
{
    public int numerator;
    public int denominator;
    public Fraction(int i)
    {
        numerator = i;
        denominator = i;
    }
    public Fraction(int numerator, int denominator)
    {
        this.numerator = numerator;
        this.denominator = denominator;
    }
    public override string ToString()
    {
        return numerator + "/" + denominator;
    }
    int gcd(int m, int n)
    {
        if (n > m)
        {
            int temp = m; m = n; n = temp;
        }
        while (n > 0)
        {
            int r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
    public void irreducibleFraction()
    {
        int temp = gcd(numerator, denominator);
        if (temp != 1)
        {
            numerator /= temp;
            denominator /= temp;
        }
    }
    static public Fraction AddFraction(Fraction f1, Fraction f2)
    {
        Fraction f = new Fraction(1, 1);
        f.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
        f.denominator = f1.denominator * f2.denominator;
        return f;
    }
    static public Fraction SubFraction(Fraction f1, Fraction f2)
    {
        Fraction f = new Fraction(1, 1);
        f.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
        f.denominator = f1.denominator * f2.denominator;
        return f;
    }
    static public Fraction MulFraction(Fraction f1, Fraction f2)
    {
        Fraction f = new Fraction(1, 1);
        f.numerator = f1.numerator * f2.numerator;
        f.denominator = f1.denominator * f2.denominator;
        return f;
    }
    static public Fraction DivFraction(Fraction f1, Fraction f2)
    {
        Fraction f = new Fraction(1, 1);
        f.numerator = f1.numerator * f2.denominator;
        f.denominator = f1.denominator * f2.numerator;
        return f;
    }
    public static Fraction operator +(Fraction f1, Fraction f2)
    {
        Fraction f = new Fraction(1, 1);
        f.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
        f.denominator = f1.denominator * f2.denominator;
        return f;
    }
    public static Fraction operator -(Fraction f1, Fraction f2)
    {
        Fraction f = new Fraction(1, 1);
        f.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
        f.denominator = f1.denominator * f2.denominator;
        return f;
    }
    public static Fraction operator *(Fraction f1, Fraction f2)
    {
        Fraction f = new Fraction(1, 1);
        f.numerator = f1.numerator * f2.numerator;
        f.denominator = f1.denominator * f2.denominator;
        return f;
    }
    public static Fraction operator /(Fraction f1, Fraction f2)
    {
        Fraction f = new Fraction(1, 1);
        f.numerator = f1.numerator * f2.denominator;
        f.denominator = f1.denominator * f2.numerator;
        return f;
    }

}
class Exercise7_3
{
    public static void Main()
    {
        Fraction c, c1, c2;
        c1 = new Fraction(50, 60);
        c1.irreducibleFraction();
        c2 = new Fraction(1, 5);
        c = Fraction.AddFraction(c1, c2);
        Console.WriteLine(c.ToString());

        c = c1 - c2;
        Console.WriteLine(c.ToString());
    }
}