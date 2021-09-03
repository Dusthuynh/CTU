package A_xulyso;

import java.util.Scanner;
import java.lang.Math;
import java.text.DecimalFormat;

/*Viết chương trình giải phương trình bậc 2: ax2 + bx + c = 0*/
public class bai_1 {
	
	public static void gptb1(float a, float b) {
		if (a==0 && b==0) 
			System.out.println("Phuong trinh co vo so nghiem.");
		else if(a==0 && b!=0) 
			System.out.println("Phuong trinh vo nghiem.");
		else {
			System.out.println("Phuong trinh co nghiem x = "+(-b/a));
		}
	}
	
	public static void gptb2(float a, float b, float c) {
		if(a==0) gptb1(b,c);
		else {
			double x1, x2, del = Math.pow(b,2)-4*a*c;
			if(del<0)
				System.out.println("Phuong trinh vo nghiem.");
			else if(del==0)
				System.out.println("Phuong trinh co nghiem kep x1= x2= "+(-b/2*a));
			else {
				del=Math.sqrt(del);
				x1=(-b+del)/(2*a); 
				x2=(-b-del)/(2*a);
				DecimalFormat df = new DecimalFormat("#.####");
				System.out.println("Phuong trinh co nghiem: x1= "+df.format(x1)+", x2="+df.format(x2));
			}
		}
	}
	
	
	public static void main(String[] args) {
		int a,b,c;
		Scanner sc = new Scanner(System.in);
		System.out.print("a= ");
		a = sc.nextInt();
		System.out.print("b= ");
		b = sc.nextInt();
		System.out.print("c= ");
		c = sc.nextInt();
		
		gptb2(a,b,c);
	}
	
}
