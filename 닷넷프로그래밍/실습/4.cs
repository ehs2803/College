using System;
using System.Collections.Specialized;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;

class EXE4
{
    public static void Main()
    {
        //1
        for(int i = 1; i <= 100; i++)
        {
            int counting = 0;
            bool b = false;
            for(int j = 1; j <= i; j++)
            {
                if (i % j == 0) counting++;
            }
            if (counting == 2) b = true;
            if (b)
            {
                Console.Write(i + " ");
            }
        }
        Console.WriteLine();

        //2
        for(int i = 1; i <= 500; i++)
        {
            int sum = 0;
            for(int j = 1; j <= i; j++)
            {
                if (i % j == 0) sum += j;
            }
            sum -= i;
            if (sum == i) Console.Write(i + " ");
        }
        Console.WriteLine();

        //3
        Console.WriteLine("Enter number : ");
        string instr = Console.ReadLine();
        int mid = instr.Length / 2;
        bool bb = false;
        for(int i = 0; i < mid; i++)
        {
            if (instr[i] != instr[instr.Length -1 - i])
            {
                bb = true;
                break;
            }
        }
        if (bb) Console.WriteLine("회문수 아닙니다.");
        else Console.WriteLine("회문수 입니다.");

        //4
        //error

        //5
        int getGCD(int a, int b)        //재귀호출로 구현한 부분
        {
            if ((a % b) == 0)   //나누어 떨어지면 그냥 나눈 수를 리턴
            {
                return b;
            }
            else   //나누어 떨어지지 않으면 b 와 a를 b로 나눈 나머지로 재귀호출
            {
                return getGCD(b, a % b);
            }
        }

        int answer = getGCD(10, 100);
        Console.WriteLine(answer);
        int aa = 6, bbb = 10;
        int d = aa * bbb;
        while (bbb > 0)
        {
            int c = aa;
            aa = bbb;
            bbb = c % bbb;
        }
        int e = d / aa;
        Console.WriteLine(e);


        //6
        //error

        //7
        int ssum = 0;
        for(int i = 1; i <= 10; i++)
        {
            int temp = 1;
            for (int j = 1; j <= i; j++) temp *= j;
            ssum += temp;
        }
        Console.WriteLine("7-1 : " +ssum);
        double fsum = 0.0;
        for(int i = 1; i <= 10; i++)
        {
            if (i % 2 == 1)
            {
                fsum += 1.0 / (double)i;
            }
            else
            {
                fsum -= 1.0 / (double)i;
            }
        }
        Console.WriteLine("7-2 : " + fsum);
        Console.WriteLine();

        //8
        for(int i = 1; i <= 9; i++)
        {
            for (int j = 2; j <= 5; j++)
            {
                Console.Write("{0} * {1} ={2,3:d},\t",j,i,j*i);
            }
            Console.WriteLine();
        }
        Console.WriteLine();
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 6; j <= 9; j++)
            {
                Console.Write("{0} * {1} ={2,3:d},\t", j, i, j * i); if (j == 9&&i==9) Console.Write("\b\b\b\b\b\b");
            }  
            Console.WriteLine();
        }
        //9///////////////////////////////////
        int n = 9;
        int m = n / 2;
        for(int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++) Console.Write(' ');
            for (int j = 0; j < 2 * i + 1; j++) Console.Write("*");
            Console.WriteLine();
        }
        for (int i = 0; i < n; i++) Console.WriteLine("*");
        for (int i = m; i > m; i--)
        {
            for (int j = i; j < m; j++) Console.Write(' ');
            for (int j = 0; j < 2 * i + 1; j++) Console.Write("*");
            Console.WriteLine();
        }
        //10
        //pass 알고리즘 시간

        //11
        int[,] array = new int[2,3] { { 1, 2, 3 }, { 4, 5, 6 } };
        int[,] array1 = new int[3,2];
        //Console.WriteLine(array.Length); 6
        //Console.WriteLine(array1.Length); 6
        for(int i = 0; i < 2;i++)
        {
            for(int j = 0; j < 3; j++)
            {
                array1[j,i] = array[i,j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                Console.Write(array1[i, j]);
            }
            Console.WriteLine();
        }

        //12
        //error
        //13
        //error
    }
}