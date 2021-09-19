using System;
using System.Collections.Generic;
using System.Text;

namespace 닷넷프로그래밍_실습._5주차
{
    class Class1
    {
        static void Main(string[] args)
        {
            //1.Math라이브러리 사용법
            //2.콘솔환경에서 사용자 입력 받는법 (scanf, cin)
            double r2 = Math.Sqrt(2.0);
            double a = Math.Pow(r2, 2);
            double b = Math.Abs(-1);
            Console.WriteLine(r2);         
            Console.WriteLine(a);           
            Console.WriteLine(b);

            //3개의 정수를 스페이스바 단위로 입력 1 2 3
            string buffer = Console.ReadLine(); //buffer = "1 2 3"
            string[] bufferArray = buffer.Split(" "); // bufferArray = {"1", "2", "3"}
            //int aa = int.Parse(bufferArray[0]);
            int[] intArr = new int[bufferArray.Length];
            for(int i = 0; i < bufferArray.Length; i++)
            {
                intArr[i] = int.Parse(bufferArray[i]);
            }
            for(int i = 0; i < intArr.Length; i++)
            {
                Console.Write(intArr[i] + " ");
            }
        }
    }
}
//