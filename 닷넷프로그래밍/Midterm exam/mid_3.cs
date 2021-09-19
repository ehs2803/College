using System;
using System.Net;
class Fraction
{
    private int numerator;
    private int denominator;
    public Fraction(int num, int denom)
    {
        numerator = num;
        denominator = denom;
    }
    public void printFraction()
    {
        Console.Write(numerator + "/" + denominator);
    }
    public void fractionAdd(Fraction f1)
    {
        printFraction();
        Console.Write(" + ");
        f1.printFraction();
        Console.Write(" = ");
        Console.WriteLine((this.numerator + f1.numerator)  + "/" + (this.denominator));
    }
}
class midterm_3
{
    public static void Main()
    {
        Fraction f1 = new Fraction(1, 5);
        Fraction f2 = new Fraction(2, 5);

        f1.fractionAdd(f2);
    }
}