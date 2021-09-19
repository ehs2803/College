using System;
class ExerciseCh6_13 :ApplicationException
{
    public static void Main(string[] args)
    {
        int mysteriousState = 5;// int.Parse(args[0]);
        while (true)
        {
            Console.Write("Who ");
            try
            {
                Console.Write("is ");
                if (mysteriousState == 1) return;
                Console.Write("that ");
                if (mysteriousState == 2) break;
                Console.Write("strange ");
                if (mysteriousState == 3) continue;
                Console.Write("but kindly ");
                if (mysteriousState == 4)
                    throw new ExerciseCh6_13();
                Console.Write("not at all ");
            }
            finally
            {
                Console.Write("amusing ");
            }
            Console.Write("yet compelling ");
            break;
        }
        Console.Write("man?");
    }
}
//6.13
//1 Who is amusing
//2 Who is that amusing man?
//3 infinity
//4 Who is that strange but kindly Unhandled exception. ExerciseCh6_13: Error in the application.
//5 Who is that strange but kindly not at all amusing yet compelling man?