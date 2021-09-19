using System;
using System.Collections.Generic;
class GClass<T>
{
    private List<T> list;
    public GClass()
    {
        list = new List<T>();
    }
    public String getValue()
    {
        String str = "";
        foreach (T e in list) str += (e.ToString() + " ");
        return str;
    }
    public void setValue(params T[] args)
    {
        foreach (T e in args) list.Add(e);
    }
}
public class ExerciseCh6_10_1
{
    public static void Main()
    {
        GClass<int> gInteger = new GClass<int>();
        gInteger.setValue(10, 20, 30, 40, 50);
        Console.WriteLine(gInteger.getValue());
    }
}
//6.10-1