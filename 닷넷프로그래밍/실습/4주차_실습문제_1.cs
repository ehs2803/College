using System;
using System.Threading;
class ThreadApp
{
    static void ThreadBody()
    {
        Console.WriteLine("In the thread body ...");
    }
    public static void Main()
    {
        ThreadStart ts = new ThreadStart(ThreadBody);
        Thread t = new Thread(ts);
        Console.WriteLine("*** Start of Main");
        t.Start();
        Console.WriteLine("*** End of Main");
    }
}