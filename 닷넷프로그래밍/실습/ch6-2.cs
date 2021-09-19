using System;
using System.Threading;
class SimpleThread
{
    public void simpleMethod()
    {
        Random randomNumber = new Random();
        for(int i = 0; i < 3; i++)
        {
            Console.WriteLine(i + " " + Thread.CurrentThread.Name);
            Thread.Sleep(randomNumber.Next(1, 5) * 1000);
        }
        Console.WriteLine("DONE! " + Thread.CurrentThread.Name);
    }
}
class ch6_2
{
    public static void Main()
    {
        SimpleThread obj = new SimpleThread();
        ThreadStart ts = new ThreadStart(obj.simpleMethod);
        Thread worker1 = new Thread(ts);
        Thread worker2 = new Thread(ts);
        worker1.Name = "Apple"; worker2.Name = "Orange";
        worker1.Start(); worker2.Start();
    }
}

//6.10-4