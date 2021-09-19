using System;
class a
{
    public static void Main()
    {
        //9-1
        int mid =11 / 2;
        for(int i = 0; i < mid; i++)
        {
            for(int j = 0; j < (mid - i); j++)
            {
                Console.Write(" ");
            }
            for(int k = 0; k < i * 2 + 1; k++)
            {
                Console.Write("*");
            }
            Console.WriteLine();
        }
        for(int i = 0; i < mid + 1; i++)
        {
            for(int j = 0; j < i; j++)
            {
                Console.Write(" ");
            }
            for(int k = 0; k < (mid + 1 - i) * 2 - 1; k++)
            {
                Console.Write("*");
            }
            Console.WriteLine();
        }

        //9-2
        int pnum = 9;
        for (int i = 0; i < pnum; i++)
        {
            for (int j = 0; j < (pnum - i); j++)
            {
                Console.Write(" ");
            }
            int z = i + 1;
            bool b = true;
            for (int k = 0; k < i * 2 + 1; k++)
            {
                Console.Write(z);
                if (z == 1) b = false;
                if (b == true) z -= 1;
                else z += 1;
                
            }
            Console.WriteLine();
        }


        //9-3
        Console.WriteLine("Enter number : ");
        int n = Console.Read() - '0';
        string num = "";
        int temp = 49;
        for(int i = 1; i <= n; i++)
        {
            char c = (char)temp;
            num += c;
            temp++;
        }
        Console.WriteLine(num);
        for(int i = 0; i < n-1; i++)
        {
            string c = num[0].ToString();
            num = num.Replace(c, "");
            num += c;
            for(int j = 0; j < i+1; j++)
            {
                Console.Write(' ');        
            }
            Console.WriteLine(num);
        }

        int bestnum=int.MinValue;
        int inputnum;
        while ((inputnum = Console.Read()-'0')!=0)
        {
            if (inputnum > bestnum) bestnum = inputnum;
        }
        if (inputnum == 0) Console.WriteLine("x");
        Console.WriteLine(bestnum);
    }
}