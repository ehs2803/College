class Complex{
	public double real;
	public double image;
	public Complex(double num) {
		real=num;
		image=num;
	}
	public Complex(double real, double image) {
		this.real=real;
		this.image=image;
	}
	public String toString() {
		return "("+real+", "+image+")";
	}
	public Complex addComplex(Complex c) {
		Complex temp = new Complex(0);
		temp.real= this.real+c.real;
		temp.image = this.image + c.image;
		return temp;
	}
	public Complex subComplex(Complex c) {
		Complex temp = new Complex(0);
		temp.real = this.real - c.real;
		temp.image = this.image - c.image;
		return temp;
	}
	public Complex mulComplex(Complex c) {
		Complex temp = new Complex(0);
		temp.real = this.real*c.real - this.image*c.image;
		temp.image = this.real*c.image + this.image*c.real;
		return temp;
	}
	public Complex divComplex(Complex c) {
		Complex temp = new Complex(0);
		temp.real = (this.real*c.real + this.image*c.image)/(c.real*c.real+c.image*c.image);
		temp.image = (this.image*c.real-this.real*c.image)/(c.real*c.real+c.image*c.image);
		return temp;
	}
}

public class prob2 {
	public static void main(String[] args) {
		Complex c1=new Complex(1.0,2.0);
		Complex c2=new Complex(3.0,4.0);
		
		Complex result_add = c1.addComplex(c2);
		Complex result_mul = c1.mulComplex(c2);
		
		System.out.println(c1.toString()+"+"+c2.toString()+"="+result_add.toString());
		System.out.println(c1.toString()+"*"+c2.toString()+"="+result_mul.toString());
	}
}
