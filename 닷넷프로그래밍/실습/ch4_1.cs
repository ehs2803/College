using System;
delegate string mydelegate(int i);
class Dummy
{
    public const int MIN = 200 - 100;
    const int MAX = MIN + 100;
    public static readonly int NORMAL = 1000;
    public int instanceVariable;
    public static int staticVariable;
    public string MethodA(int i)
    {
        return string.Format("int value = {0}", i);
    }
}
class ExerciseCh4_6
{
    public static void Main()
    {
        Dummy d = new Dummy();
        Console.WriteLine(Dummy.NORMAL);
        Console.WriteLine(Dummy.MIN);
        Dummy.staticVariable = 10;
        d.instanceVariable = 10;
        Dummy.staticVariable = 10;

        mydelegate m = new mydelegate(d.MethodA);
        string temp_str = m(5);
        Console.WriteLine(temp_str);
    }
}
/*
1000
100
int value = 5
*/