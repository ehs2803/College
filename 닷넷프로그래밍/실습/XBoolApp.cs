using System;
class XBool
{
    public bool b;
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
}
class XBoolApp
{
    public static void Main()
    {
        XBool xb = new XBool();
        xb.b = false;
        if (xb)
        {
            Console.WriteLine("True");
        }
        else
        {
            Console.WriteLine("False");
        }
        Console.WriteLine((bool)xb);
    }
}