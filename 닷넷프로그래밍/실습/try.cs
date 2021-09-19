using System;
class userExceptions : ApplicationException
{
    int i;
    public userExceptions(int num,string a) :base(a)
    {
        i = num;
    }
    public int I
    {
        get { return i; }
    }
}
class userExceptiontwo : ApplicationException
{
    int i;
    public userExceptiontwo(int num, string a) : base(a)
    {
        i = num;
    }
    public int I
    {
        get { return i; }
    }
}
class Fraction
{
    int a, b;
    public Fraction(int a, int b)
    {
        this.a = a;
        try
        {
            if (b == 0) throw new userExceptions(0,"0 in Fraction");
            if (b == 1) throw new userExceptiontwo(1,"1 in Fraction");
            if (b == 2) throw new userExceptiontwo(2,"2 in Fraction");
            this.b = b;
            Console.WriteLine(b + "succeful");
        }
        catch(userExceptions e)
        {
            Console.WriteLine(e.Message);
            //Console.WriteLine(e.StackTrace);
            Console.WriteLine(e.I);
        }
        catch (userExceptiontwo e)
        {
            Console.WriteLine(e.Message);
            //Console.WriteLine(e.StackTrace);
            Console.WriteLine(e.I);
        }
    }
}
class ex
{
    public static void Main()
    {
        Fraction f = new Fraction(1, 0);
        Fraction f1 = new Fraction(1, 1);
        Fraction f2 = new Fraction(1, 2);
        int a;
        while (true)
        {
            try
            {
                //string b = Console.ReadLine();
                a = int.Parse(Console.ReadLine());
                if (a == 0) throw new userExceptions(0, "00000error");
                break;
            }
            catch(userExceptions e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}