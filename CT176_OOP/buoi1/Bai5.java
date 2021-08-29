package buoi1;

import java.util.Scanner;
import java.lang.Math;

public class Bai5 {

	public static void gptb1(float b, float c) {
		if(b==0 && c==0) {
			System.out.println("Phuong trinh co vo so nghiem");
		}else
		if(b==0 && c!=0) {
			System.out.println("Phuong trinh vo nghiem");
		}
		else {
			System.out.println("Phuong trinh co nghiem x = "+((-c)/b));
		}
	}
	public static void gptb2(float a, float b, float c) {	 
		if(a==0) gptb1(b,c);
		else {
			double x1, x2, del=(Math.pow(b, 2)-4*a*c);
			if(del<0) {
				System.out.println("Phuong trinh vo nghiem");
			}else
			if(del==0) {
				x1=x2=-b/2*a;
				System.out.println("Phuong trinh co nghiem kep x1 = x2 = "+x1);
			}
			else {
				del=Math.sqrt(del);
				x1=(-b+(del))/(2*a);
				x2=(-b-(del))/(2*a);
				System.out.println("Phuong trinh co hai nghiem x1 = "+x1+"; x2= "+x2);
			}
		}
	}
	
	public static void main(String[] args) {
		int a, b, c;
		Scanner sc =new Scanner(System.in);
		System.out.print("a= ");
		a=sc.nextInt();
		System.out.print("b= ");
		b=sc.nextInt();
		System.out.print("c= ");
		c=sc.nextInt();
		
		gptb2(a,b,c);
	}
}
