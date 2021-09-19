using System;
class Stack
{
    private int[] stack;
    int sp = -1;
    int size = 0;
    public int Size
    {
        get { return size; }
    }
    public Stack(int size = 100)
    {
        stack = new int[size];
    }
    public void Push(int data)
    {
        stack[++sp] = data;
        size++;
    }
    public int Pop()
    {
        size--;
        return stack[sp--];
    }
}
class EX2
{
    public static void Main()
    {
        Stack st = new Stack(10);

        Console.WriteLine("[STACK PUSH]");
        while (true)
        {
            string buffer = Console.ReadLine();
            int inputNum = int.Parse(buffer);
            if (inputNum == 0) break;
            st.Push(inputNum);
        }

        Console.WriteLine("\n[STACK POP]");
        while (st.Size != 0)
        {
            Console.Write("{0} ", st.Pop());
        }
        Console.WriteLine();
    }
}
/*
string buffer1 = Console.ReadLine(); 
        string[] bufferArray = buffer1.Split(" "); 
        int[] intArr = new int[bufferArray.Length];
        for (int i = 0; i < bufferArray.Length; i++)
        {
            intArr[i] = int.Parse(bufferArray[i]);
        }
*/