using System;
class GenericSwap<T>
{
    public T x, y;
    public void swap()
    {
        T temp;
        temp = x; x = y; y = temp;
    }
    
}
public class ExerciseCh6_11
{
    public static void Main(String[] args)
    {
        Console.WriteLine("[제네릭클래스 int형 테스트]");
        GenericSwap<int> i = new GenericSwap<int>();
        i.x = 1; i.y = 2;
        Console.Write("[swap 전] ");
        Console.WriteLine("x: " + i.x + " y: " + i.y);
        i.swap();
        Console.Write("[swap 후] ");
        Console.WriteLine("x: " + i.x + " y: " + i.y);

        Console.WriteLine("\n[제네릭클래스 double형 테스트]");
        GenericSwap<double> d = new GenericSwap<double>();
        d.x = 1.1; d.y = 2.2;
        Console.Write("[swap 전] ");
        Console.WriteLine("x: " + d.x + " y: " + d.y);
        d.swap();
        Console.Write("[swap 후] ");
        Console.WriteLine("x: " + d.x + " y: " + d.y);      
    }
}
