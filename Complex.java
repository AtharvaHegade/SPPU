
public class Complex {
	float real,img;
	public Complex() 
	{
		real=0;
		img=0;
	}
	public Complex(float real , float img )
	{
		this.real= real;
		this.img= img;
		System.out.println("Complex number:"+real+"+"+img+"i");
		
	}
	public void add (Complex x, Complex y)
	{
		real = x.real + y.real;
		img = x.img + y.img;
		System.out.println("Addition of two complex numbers:"+real+"+"+img+"i");
		
	}
	public void sub (Complex x , Complex y )
	{
		real = x.real - y.real;
		img  = x.img-y.img;
		System.out.println("Substraction of two complex numbers:"+real+"+"+img+"i");
		
	}
	public void multi(Complex x , Complex y)
    {
		real= x.real *y.real - x.img *y.img;
		img = x.real*y.img +x.real*y.img;
		System.out.println("Multiplication of two complex numbers:"+real+"+"+img+"i");
		
	}
	public void div(Complex x , Complex y)
    {
		real =(x.real*y.real+x.img*y.img)/(y.real*2+y.img*2);
		img =(x.img*y.real-x.real*y.img)/(y.real*2+y.img*2);
		System.out.println("Division of two complex numbers:"+real+"+"+img+"i");
		
	}
		

}
