using System;
public interface IFigure
{
    void Area();
    void Girth();
    void Draw();
}
class Rect : IFigure
{
    int width, heigth;
    public Rect(int width, int heigth)
    {
        this.width = width;
        this.heigth = heigth;
    }
    public void Area()
    {
        Console.WriteLine("사각형의 넓이는 {0}입니다.", width * heigth);
    }
    public void Girth()
    {
        Console.WriteLine("사각형의 둘레는 {0}입니다.", 2 * width + 2 * heigth);
    }
    public void Draw()
    {
        Console.WriteLine("사각형을 그립니다.");
        for (int i = 0; i < width; i++) Console.Write("*"); Console.WriteLine();
        for (int i = 0; i < heigth - 2; i++)
        {
            Console.Write("*");
            for (int j = 0; j < width - 2; j++) Console.Write(" ");
            Console.WriteLine("*");
        }
        for (int i = 0; i < width; i++) Console.Write("*"); Console.WriteLine();
    }
}
class Circle : IFigure
{
    int radius;
    public Circle(int radius)
    {
        this.radius = radius;
    }
    public void Area()
    {
        Console.WriteLine("원의 넓이는 {0:F2}입니다.", Math.PI * Math.Pow(radius, 2));
    }
    public void Girth()
    {
        Console.WriteLine("원의 둘레는 {0:F2}입니다.", 2 * Math.PI * radius);
    }
    public void Draw()
    {
        Console.WriteLine("원을 그렸습니다.");
    }
}
class Exercise5_11
{
    public static void Main()
    {
        Rect r = new Rect(5, 3);
        Circle c = new Circle(10);

        r.Area(); r.Girth(); r.Draw();
        Console.WriteLine();
        c.Area(); c.Girth(); c.Draw();
    }
}