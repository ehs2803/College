using System;

class MethodOverloadingApp
{
    void SomeThing()
    {
        Console.WriteLine("SomeThing() is called.");
    }
    void SomeThing(int i)
    {
        Console.WriteLine("SomeThing(int) is called.");
    }
    void SomeThing(int i, int j)
    {
        Console.WriteLine("SoneThing(int,int) is called.");
    }
    void SomeThing(double d)
    {
        Console.WriteLine("SomeThing(double) is called.");
    }
    public static void Main()
    {
        MethodOverloadingApp obj = new MethodOverloadingApp();
        obj.SomeThing();
        obj.SomeThing(526);
        obj.SomeThing(54, 526);
        obj.SomeThing(5.26);
    }
}