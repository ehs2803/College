using System;
using System.Threading;

delegate void SampleDelegate();

class PropertyClass
{
    private int privateValue;
    public int pri
    {
        get { return privateValue; }
        set { privateValue = value; }
    }
    public void PrintValue()
    {
        Console.WriteLine(privateValue);
    }
}
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
class Stack<StackType>
{
    private StackType[] stack_mem = new StackType[10];
    private int sp = -1;
    public void push(StackType element)
    {
        stack_mem[++sp] = element;
    }
    public StackType pop()
    {
        return stack_mem[sp--];
    }
}
class mid_termEXE
{
    public static void Main()
    {
        PropertyClass dbj = new PropertyClass();
        dbj.pri = 1000;
        dbj.PrintValue();

        Even e = new Even(4); 
        SampleDelegate sd = new SampleDelegate(e.PrintEven);
        sd();
        ++e;   sd();
        --e;   sd();

        Stack<int> stk = new Stack<int>();
        stk.push(1); stk.push(2); stk.push(3);
        Console.WriteLine(stk.pop() + " " + stk.pop() + " " + stk.pop());
        
    }
}