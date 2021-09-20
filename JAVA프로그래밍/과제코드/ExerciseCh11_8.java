class Account{
	private double balance;
	
	public Account(double initialDeposit) {
		balance = initialDeposit;
	}
	public synchronized double getBalance() {
		return balance;
	}
	public synchronized void deposit(double amount) {
		balance += amount;
	}
}

class Teller extends Thread{
	String name;
	Account account;
	double amount;
	Teller(String name, Account account, double amount){
		this.name = name;
		this.account = account;
		this.amount = amount;
	}
	public void run() {
		account.deposit(amount);
		System.out.println(name+" : "+account.getBalance());
	}
}

public class ExerciseCh11_8 {
	public static void main(String[] args) {
		Account account = new Account(50000);
		
		Teller teller1 = new Teller("A", account, 5000);
		Teller teller2 = new Teller("B", account, 1000);
		Teller teller3 = new Teller("C", account, 2000);
		
		teller1.start();
		teller2.start();
		teller3.start();
	}
}

