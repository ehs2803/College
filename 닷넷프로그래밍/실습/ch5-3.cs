using System;
interface IPropertyCounter
{
    int Count { get; set; }
}
interface IMethodCounter
{
    int Count(int i);
}
interface ICounter:IPropertyCounter, IMethodCounter {  }
class InterfaceParamter
{
    void Test(ICounter x)
    {
        ((IMethodCounter)x).Count(1);
        ((IPropertyCounter)x).Count = 1;
    }
    public static void Main()
    {
        InterfaceParamter test = new InterfaceParamter();
        test.Test(1);
    }
}
