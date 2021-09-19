using System;
using System.Runtime.InteropServices.ComTypes;

class Exercisech3_10_2
{
    static int HexValue(char ch)
    {
        switch (ch)
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7':case '8':case '9':
                return (ch - '0');
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
                return (ch - 'A' + 10);
            case 'a': case 'b': case 'c': case 'd': case 'f': case 'e':
                return (ch - 'a' + 10);
            default: return- 1;
        }
    }
    public static void Main()
    {
        int num = 0;
        int value;
        char ch;
        ch = (char)Console.Read();
        if (ch == '0')
        {
            ch = (char)Console.Read();
            if ((ch == 'x') || (ch == 'X'))
            {
               // ch = (char)Console.Read();
                while ((value = HexValue((char)Console.Read())) != -1)
                    num = 16 * num + value; //ch = (char)Console.Read();
            }
            else num = 0;
        }
        else
        {
            do
            {
                num = 10 * num + (int)(ch - '0');
                ch = (char)Console.Read();
            } while (char.IsDigit(ch));
        }
        Console.WriteLine(num);
    }
}