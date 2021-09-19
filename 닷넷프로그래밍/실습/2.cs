using System;

enum Color { Red,Green,Blue};
class EXE2
{
    public static void Main()
    {
        int @int = 10;
        string s1 = "hello \\tword";
        string s2 = @"hello \tword";
        Console.WriteLine(s1 + s2);
        Color co = Color.Red;
        co++;
        @int = (int)co;
        Console.Write(co); Console.WriteLine(@int);

        int a, b, c;
        int m;
        Console.Write("Enter three number : ");
        a = Console.Read() - '0';
        b = Console.Read() - '0';
        c = Console.Read() - '0';
        Console.Write(a); Console.Write(b); Console.WriteLine(c);
        Console.WriteLine("{0,-10:D}", 100);

        char[] com = { 'a', 'v' };
        foreach(char aa in com)
        {
            Console.WriteLine(aa);
        }
    }
    
    
}