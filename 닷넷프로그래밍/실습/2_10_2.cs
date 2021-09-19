using System;
enum Color { Red,Green,Blue,Max=Blue};
class ExerciseCh2_10_2
{
    public static void Main()
    {
        Color c = Color.Red;
        int i = (int)++c;
        Console.WriteLine(" Color = " + (Color)i);
        c = Color.Blue;
        Console.WriteLine("Cardinality of " + c + " = " + (int)c);
        c = Color.Max;
        Console.WriteLine("Cardinality of " + c + " = " + (int)c);
        short j = 0;
        Console.WriteLine("j = " + (j + 1) * (j = 1));
    }
}
/*
 Color = Green
Cardinality of Blue = 2
Cardinality of Blue = 2
*/