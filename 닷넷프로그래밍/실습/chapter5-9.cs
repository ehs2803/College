using System;
interface IOperation
{
    void Insert(string str);
    string Delete();
    bool Search(string str);
    string GetCurrentElt();
    int NumOfElements();
}
class Stack : IOperation
{
    string[] stack;
    int sp = -1;
    int size = 0;
    public Stack(int size = 20)
    {
        stack = new string[size];
    }
    public void Insert(string str)
    {
        stack[++sp] = str;
        size++;
    }
    public string Delete()
    {
        size--;
        return stack[sp--];
    }
    public bool Search(string str)
    {
        for(int i = 0; i < size; i++)
        {
            if (stack[i] == str) return true;
        }
        return false;
    }
    public string GetCurrentElt()
    {
        return stack[sp];
    }
    public int NumOfElements()
    {
        return size;
    }
    public void printStack()
    {
        for(int i = 0; i < size; i++)
        {
            Console.Write("{0} ", stack[i]);
        }
        Console.WriteLine();
    }
}
class Queue : IOperation
{
    string[] queue;
    int front = 0;
    int rear = -1;
    int size = 0;
    public Queue(int size)
    {
        queue = new string[size];
    }
    public void Insert(string str)
    {
        queue[++rear] = str;
        size++;
    }
    public string Delete()
    {
        size--;
        return queue[front++];
    }
    public bool Search(string str)
    {
        for (int i = front; i <= rear; i++)
        {
            if (queue[i] == str) return true;
        }
        return false;
    }
    public string GetCurrentElt()
    {
        return queue[front];
    }
    public int NumOfElements()
    {
        return size;
    }
    public void printQueue()
    {
        for(int i = front; i <= rear; i++)
        {
            Console.Write("{0} ", queue[i]);
        }
        Console.WriteLine();
    }
}
class EXercise5_9
{
    public static void Main()
    {
        Console.WriteLine("[스택 테스트]");
        Stack s = new Stack(10);
        s.Insert("a"); s.Insert("b"); s.Insert("c"); s.Insert("d"); s.Insert("e"); s.Insert("f");
        s.printStack();
        Console.WriteLine("스택 원소 삭제 : {0}", s.Delete());
        s.printStack();
        if (s.Search("b")) Console.WriteLine("스택에 원소 \"b\"가 존재 합니다.");
        if (!s.Search("z")) Console.WriteLine("스택에 원소 \"z\"가 존재하지 않습니다.");
        Console.WriteLine("스택 탑에 있는 원소는 {0}", s.GetCurrentElt());
        Console.WriteLine("스택에 존재하는 원소 개수 {0}개\n", s.NumOfElements());

        Console.WriteLine("[큐 테스트]");
        Queue q = new Queue(10);
        q.Insert("a"); q.Insert("b"); q.Insert("c");q.Insert("d"); q.Insert("e"); q.Insert("f");
        q.printQueue();
        Console.WriteLine("큐 원소 삭제 : {0}", q.Delete());
        q.printQueue();
        if (q.Search("b")) Console.WriteLine("큐에 원소 \"b\"가 존재 합니다.");
        if (!q.Search("z")) Console.WriteLine("큐에 원소 \"z\"가 존재하지 않습니다.");
        Console.WriteLine("큐 front에 있는 원소는 {0}", q.GetCurrentElt());
        Console.WriteLine("큐에 존재하는 원소 개수 {0}개", q.NumOfElements());
    }
}