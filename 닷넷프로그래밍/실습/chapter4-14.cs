using System;
class Vector
{
    public int[] v;
    public Vector()
    {
        v = new int[100];
    }
    public Vector(int size)
    {
        v = new int[size];
    }
    static void Swap(ref int x, ref int y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    public void Qsort(int left, int right)
    {
        int pe;
        int i, last;

        if (left >= right) return;
        pe = (left + right) / 2;
        Swap(ref v[left], ref v[pe]);
        last = left;
        for (i = left + 1; i <= right; i++)
            if (v[i] < v[left]) Swap(ref v[++last], ref v[i]);
        Swap(ref v[left], ref v[last]);
        Qsort(left, last - 1);
        Qsort(left + 1, right);
    }
}
class EX3
{
    public static void Main()
    {
        Vector vector = new Vector(10);

        Console.WriteLine("[vector 입력]");
        int index = 0;
        while (true)
        {
            string buffer = Console.ReadLine();
            int inputNum = int.Parse(buffer);
            if (inputNum == 0) break;
            vector.v[index++] = inputNum;
        }

        vector.Qsort(0, index - 1);

        Console.WriteLine("\n[정렬결과]");
        for (int i = 0; i < index; i++)
        {
            Console.Write("{0} ", vector.v[i]);
        }
        Console.WriteLine();
    }
}