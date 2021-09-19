using System; // +n -n 구현 못함
class Date
{
    static int[] days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    private int day, month, year;
    public Date(int mm, int dd, int yy)
    {
        day = dd;
        month = mm;
        year = yy;
    }
    public static bool operator ==(Date d1, Date d2)
    {
        if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) return true;
        else return false;
    }
    public static bool operator !=(Date d1, Date d2)
    {
        if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) return false;
        else return true;
    }
    public static bool operator >(Date d1, Date d2)
    {
        if (d1.year > d2.year) return true;
        else
        {
            if (d1.month > d2.month) return true;
            else
            {
                if (d1.day > d2.day) return true;
                else return false;
            }
        }
    }
    public static bool operator <(Date d1, Date d2)
    {
        if (d1.year < d2.year) return true;
        else
        {
            if (d1.month < d2.month) return true;
            else
            {
                if (d1.day < d2.day) return true;
                else return false;
            }
        }
    }
    public static Date operator +(Date d, int n)
    {
        Date temp = new Date(1, 1, 1);
        temp.year = d.year;
        temp.month = d.month;
        if (d.day + n > days[temp.month])
        {
            if (d.month == 12)
            {
                temp.year += 1;
                temp.month = 1;
                temp.day = n - (days[12] - d.day);
            }
            else
            {
                temp.day = n - (days[temp.month] - d.day);
                temp.month += 1;
            }
        }
        else temp.day = d.day + n;
        return temp;
    }
    public static Date operator -(Date d, int n)
    {
        Date temp = new Date(1, 1, 1);
        temp.year = d.year;
        temp.month = d.month;
        if (d.day - n <= 0)
        {
            if (d.month == 1)
            {
                temp.year -= 1;
                temp.month = 12;
                temp.day = days[temp.month]-(n - d.day);
            }
            else
            {
                temp.month -= 1;
                temp.day = days[temp.month] - (n - d.day);
            }
        }
        else temp.day = d.day - n;
        return temp;
    }
    public static Date operator ++(Date d)
    {
        Date temp = new Date(1, 1, 1);
        temp.year = d.year;
        temp.month = d.month;
        if (d.day == days[temp.month])
        {
            if (d.month == 12)
            {
                temp.year += 1;
                temp.month = 1;
                temp.day = 1;
            }
            else
            {
                temp.month += 1;
                temp.day = 1;
            }
        }
        else temp.day = d.day + 1;
        return temp;
    }
    public static Date operator --(Date d)
    {
        Date temp = new Date(1, 1, 1);
        temp.year = d.year;
        temp.month = d.month;
        if (d.day - 1 == 0)
        {
            if (d.month == 1)
            {
                temp.year = d.year - 1;
                temp.month = 12;
                temp.day = 31;
            }
            else
            {
                temp.month -= 1;
                temp.day = days[temp.month];
            }
        }
        else temp.day = d.day - 1;
        return temp;
    }
    public override string ToString()
    {
        return string.Format("{0}/{1}/{2}", month, day, year);
    }
}
class ExerciseCh4_6
{
    public static void Main()
    {
        Date d1 = new Date(1, 2, 2019);
        Date d2 = new Date(11, 8, 2020);
        Date d3 = new Date(11, 8, 2020);
        if (d1 == d2) Console.WriteLine("1");
        if (d3 == d2) Console.WriteLine("2");
        if (d1 != d2) Console.WriteLine("3");
        if (d3 != d2) Console.WriteLine("4");
        if (d1 < d3) Console.WriteLine("5");
        d1=d1-10; Console.WriteLine(d1.ToString());
    }
}