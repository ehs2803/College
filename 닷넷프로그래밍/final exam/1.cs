using System;
using System.Threading;

class userException : ApplicationException
{
    public userException(string s) : base(s) { }
}
class CircularQueue<T>
{
    T[] data = new T[2];
    int count;
    int Front;
    int Rear;
    public CircularQueue()
    {
        count = 0;
        Front = 0;
        Rear = -1;
    }
    bool IsEmpty()
    {
        if (count == 0) return true;
        else return false;
    }
    public void put(T item)
    {
        try
        {
            if (count == 2) throw new userException("큐 꽉참");
            Rear = (Rear + 1) % 2;
            data[Rear] = item;
            count++;
        }
        catch (userException e)
        {
            Console.WriteLine(e.Message);
        }
    }
    public void get()
    {
        lock (this)
        {
            try
            {
                if (IsEmpty()) throw new userException("큐 비어있음");
                Console.WriteLine(data[Front]);
                Front = (Front + 1) % 2;
                count--;
            }
            catch (userException e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
class prob1
{
    public static void Main()
    {
        CircularQueue<int> test1 = new CircularQueue<int>();
        test1.put(1); test1.put(2); test1.put(3);

        ThreadStart ts = new ThreadStart(test1.get);

        Thread producer = new Thread(ts);
        Thread consumer = new Thread(ts);
        producer.Name = "apple";
        consumer.Name = "orange";
        producer.Start();
        consumer.Start();
        test1.get();

        Thread.Sleep(10);
        Console.WriteLine();
        CircularQueue<double> test2 = new CircularQueue<double>();
        test2.put(1.1); test2.put(2.2); test2.put(3.3);

        ThreadStart ts2 = new ThreadStart(test2.get);

        producer = new Thread(ts2);
        consumer = new Thread(ts2);
        producer.Start();
        consumer.Start();
        test2.get();
    }
}