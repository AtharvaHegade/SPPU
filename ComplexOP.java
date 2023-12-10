import java.util.Scanner;

public class ComplexOP {

	public static void main(String[] args) {
		int a,b,c,d;
		int ch;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter First Complex Number:");
		a=sc.nextInt();
		b=sc.nextInt();
		System.out.println("Enter Second Complex Number:");
		c=sc.nextInt();
		d=sc.nextInt();
		
		Complex c1 = new Complex(a,b);
		Complex c2 = new Complex(c,d);
		Complex c3 = new Complex();
		
		do {
			System.out.println("1.Addtion");
			System.out.println("2.Substraction");
			System.out.println("3.Multiplication");
			System.out.println("4.Division");
			System.out.println("5.Exit");
			System.out.println("Enter your choice:");
			ch=sc.nextInt();
			switch(ch)
			{
			case 1: c3.add(c1,c2);
					break ;
			
			case 2: c3.sub(c1,c2);
					break ;
			case 3: c3.multi(c1,c2);
					break ;
			case 4 :c3.div(c1,c2);
					break ;
				
					
			}
			
			
			
		}while ( ch<5);
		
	}
	
}
				
				
			
			
			
			
			
			
			
			
			
			
					
	
	
