using System;
class ReadIntergerApp
{
    static int ReadInt()
    {
        char ch;
        int n = 0;
        while (!char.IsDigit(ch = (char)Console.Read())) ;
        do
        {
            n = n * 10 + (ch - '0');
            ch = (char)Console.Read();
        } while (char.IsDigit(ch));
        return n;
    }
    public static void Main()
    {
        Console.Write("***input data : ");
        Console.WriteLine("*** read data : " + ReadInt() + " " + ReadInt());
    }
}