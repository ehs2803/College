using System;

class Even
{
    int evenNumber;
    public Even(int n)
    {
        evenNumber = (n % 2 == 0) ? n : n + 1;
    }
    public static Even operator++(Even e)
    {
        e.evenNumber += 2;
        return e;
    }
    public static Even operator--(Even e)
    {
        e.evenNumber -= 2;
        return e;
    }
    public void PrintEven()
    {
        Console.WriteLine("Even Number = " + evenNumber);
    }
}

class OperatorOverloadingApp
{
    public static void Main()
    {
        Even e = new Even(4); e.PrintEven();
        ++e;                  e.PrintEven();
        --e;                  e.PrintEven();
    }
}