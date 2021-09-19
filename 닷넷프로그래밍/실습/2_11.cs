using System;
class ExerciseCh2_11
{
    int i;  //int @i, i;
    int[] vector = new int[100];  //int vector[100];
    int[,] matrix = new int[10,1];  //int[,] matrix = new int[10,];
    static int get = 2;
    static int add
    {
        get { return get + 2258; }
    }
    static void set(int v)
    {
        get = v;
    }
    public static void Main()
    {
        object o = get;
        int i = (int)o; //int i = (short)o;
        Console.WriteLine("ExerciseCh2_11.get={0}", ExerciseCh2_11.get);
        Console.WriteLine("ExerciseCh2_11.add={0}", ExerciseCh2_11.add);
        ExerciseCh2_11.set(10);  //ExerciseCh2_11.set(3342++);
        Console.WriteLine("ExerciseCh2_11.get={0}", ExerciseCh2_11.get);
    }
}
/*
ExerciseCh2_11.get=2
ExerciseCh2_11.add=2260
ExerciseCh2_11.get=10
*/