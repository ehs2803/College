using System;
class FinallyClause
{
    public void MethodA()
    {
        try
        {
            Console.WriteLine("1");
        }
        catch(Exception e)
        {
            Console.WriteLine("2");
        }
    }
    public void MethodB()
    {
        try
        {
            Console.WriteLine("3");
        }
        finally
        {
            Console.WriteLine("4");
        }
    }
}
class ExerciseCh6_10_3
{
    public static void Main()
    {
        FinallyClause fc = new FinallyClause();
        fc.MethodA();
        fc.MethodB();
    }
}
/*
1
3
4
*/