using System;
class XBool
{
    public bool b;
    public XBool(bool b)
    {
        this.b = b;
    }
    public static explicit operator bool(XBool x)
    {
        Console.WriteLine("In the explicit operator bool ...");
        return x.b;
    }
    public static bool operator true(XBool x)
    {
        Console.WriteLine("In the operator true ...");
        return x.b ? true : false;
    }
    public static bool operator false(XBool x)
    {
        Console.WriteLine("In the operator false ...");
        return x.b ? false : true;
    }
    public static XBool operator &(XBool x, XBool y)
    {
        Console.WriteLine("In the operator & ...");
        return new XBool(x.b && y.b);
    }
    public static XBool operator |(XBool x, XBool y)
    {
        Console.WriteLine("In the operator | ...");
        return new XBool(x.b || y.b);
    }
}
class XBoolApp
{
    public static void Main()
    {
        XBool b1 = new XBool(true);
        XBool b2 = new XBool(false);
        if (b1 && b2) Console.WriteLine("b1 && b2 = True");
        else Console.WriteLine("b1 && b2 = false");
        if (b1 || b2) Console.WriteLine("b1 || b2 = True");
        else Console.WriteLine("b1 || b2 = false");
        if (b2 || b1) Console.WriteLine("b2 || b1 = True");
        else Console.WriteLine("b2 || b1 = false");
        Console.WriteLine((bool)b1);
    }
}