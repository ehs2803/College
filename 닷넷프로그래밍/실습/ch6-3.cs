using System;
interface SimpleList<T>
{
    void insert(T obj);
    void delete(T obj);
    T find(T obj);
    int currentCount();
}
class mylist<T> : SimpleList<T>
{
    int size;
    T[] arr;
    public mylist(int s)
    {
        size = 0;
        arr = new T[s];
    }
    public void insert(T obj)
    {
        arr[size++] = obj;
    }
    public void delete(T obj)
    {

    }
    public T find(T obj)
    {
        return arr[0];
    }
    public int currentCount()
    {
        return size;
    }
}
class ExerciseCh6_12
{
    public static void Main()
    {
        mylist<double> ml = new mylist<double>(10);
        Console.WriteLine(ml.currentCount());
        ml.insert(1.3);
        Console.WriteLine(ml.find(5.5)+" "+ml.currentCount());
    }
}
//6.12