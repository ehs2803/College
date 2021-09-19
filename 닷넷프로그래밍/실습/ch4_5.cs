using System;
using System.Reflection.Metadata.Ecma335;

class Vector
{
    private int[] v;
    public Vector(int size)
    {
        v = new int[size];
    }
    public int this[int index]
    {
        get { return v[index]; }
        set { v[index] = value; }
    }
    public static Vector operator ++(Vector v)
    {
        for (int i = 0; i < v.v.Length; i++)
        {
            v[i]++;
        }
        return v;
    }
    public static Vector operator --(Vector v)
    {
        for (int i = 0; i < v.v.Length; i++)
        {
            v[i]--;
        }
        return v;
    }
}
class EX
{
    public static void Main()
    {
        Vector c = new Vector(10);
        c--;
        for (int i = 0; i < 10; i++)
        {
            Console.Write("{0} ", c[i]);
        }
        c++;
        for (int i = 0; i < 10; i++)
        {
            Console.Write("{0} ", c[i]);
        }
    }
}