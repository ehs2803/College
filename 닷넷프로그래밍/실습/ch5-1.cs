using System;
class BaseClass
{
    public static int supNum = 100;
    public bool Equal(object obj)
    {
        if (GetType() == obj.GetType()) return true;
        else return false;
    }
}
class DerivedClass : BaseClass { public static int subNum = 200; }
class Exercise5_1{
    public static void Main()
    {
        Console.Write(BaseClass.supNum + ", " + DerivedClass.supNum);
        Console.WriteLine(", " + DerivedClass.subNum);

        BaseClass b1 = new BaseClass();
        BaseClass b2 = new BaseClass();
        DerivedClass d1 = new DerivedClass();
        DerivedClass d2 = new DerivedClass();
        if (b1.Equal(d1)) Console.WriteLine("1Derived equals Base");
        if (d1.Equal(b1)) Console.WriteLine("2Base equals Derived");
        if (b1.Equal(b2)) Console.WriteLine("3Base equals Base");
        if (d1.Equal(d2)) Console.WriteLine("4Derived equals Derived");
    }
}