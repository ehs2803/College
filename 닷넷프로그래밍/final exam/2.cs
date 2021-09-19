using System;
using System.Threading;
class Fork
{
    int num = 5;
    public void get()
    {
        
    }
    public void put()
    {

    }
    
}
class Philosophe
{
    string name;
    Fork fork;
    public bool b = false;
    public Philosophe(string name, Fork fork)
    {
        this.name = name;
        this.fork = fork;
    }
    public void Task()
    {
        lock (this)
        {
            fork.get();
            fork.put();
        }
    }
}

class prob2
{
    public static void Main()
    {
        Fork fork = new Fork();
        Philosophe p1 = new Philosophe("a", fork);
        Philosophe p2 = new Philosophe("b", fork);
        Philosophe p3 = new Philosophe("c", fork);
        Philosophe p4 = new Philosophe("d", fork);
        Philosophe p5 = new Philosophe("e", fork);


        ThreadStart ts1 = new ThreadStart(p1.Task);
        ThreadStart ts2 = new ThreadStart(p2.Task);
        ThreadStart ts3 = new ThreadStart(p3.Task);
        ThreadStart ts4 = new ThreadStart(p4.Task);
        ThreadStart ts5 = new ThreadStart(p5.Task);

        Thread t1 = new Thread(ts1);
        Thread t2 = new Thread(ts2);
        Thread t3 = new Thread(ts3);
        Thread t4 = new Thread(ts4);
        Thread t5 = new Thread(ts5);

        while (true)
        {
            if (p1.b == true && p2.b == true && p3.b == true && p4.b == true && p5.b == true) break;
            if (p1.b == false) t1.Start();
            if (p2.b == false) t2.Start();
            if (p3.b == false) t3.Start();
            if (p4.b == false) t4.Start();
            if (p5.b == false) t5.Start();
        }

    }
}