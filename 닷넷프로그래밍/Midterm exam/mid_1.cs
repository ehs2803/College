using System;
enum Color { red,green,blue};
class midterm_1
{
    public static void Main()
    {
        Color color = Color.red;

        int[] arr = new int[3];

        for(int i = 0; i < arr.Length; i++)
        {
            arr[i] = (int)color++;
        }

        color = Color.red;

        foreach(int element in arr)
        {
            Console.WriteLine("{0,5} : {1}",color++, element);
        }
    }
}