using System;
using System.Threading;
class Account
{
    private double balance;
    public Account(double initialDeposit)
    {
        balance = initialDeposit;
    }
    public double Balance
    {
        get { return balance; }
    }
    public void Deposit(double amount)
    { 
        lock (this)
        {
            balance += amount;
            Console.WriteLine(balance);
        }  
    }
}
class Teller
{
    string name;
    Account account;
    double amount;
    public Teller(string name, Account account, double amount)
    {
        this.name = name;
        this.account = account;
        this.amount = amount;
    }
    public void TellerTask()
    {
        account.Deposit(amount);
        Console.WriteLine(name + " : " + account.Balance);
    }
}
class ExerciseCh6_14
{
    public static void Main()
    {     
        Account a = new Account(10000);
        Teller t1 = new Teller("은행원A씨", a, 3000);
        Teller t2 = new Teller("은행원B씨", a, 8000);

        ThreadStart ts1 = new ThreadStart(t1.TellerTask);
        ThreadStart ts2 = new ThreadStart(t2.TellerTask);

        Thread th1 = new Thread(ts1);
        Thread th2 = new Thread(ts2);

        th1.Start();
        th2.Start();
    }
}
