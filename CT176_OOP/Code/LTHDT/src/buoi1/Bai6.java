package buoi1;

import java.util.Scanner;
import java.lang.Math;

public class Bai6 {
	public void ktsnt(int x) {
		boolean temp=true;
		if(x==2) temp=true;
		else {
			for(int i=2;i<Math.sqrt(x);i++) {
				if (x%i==0) {
					temp=false;
					break;
				}
			}
		}
		
		if(temp) System.out.println("x la so nguyen to");
		else System.out.println("x khong la so nguyen to");
	}
	public int nhiphan(int x) {
	    int b;
	    if(x==0)
	         return 0;
	    else
	         b=x%2; 
	    return nhiphan(x/2)*10+b;
	}
	
	public static void main(String[] args) {
		int x;
		Bai6 t = new Bai6();
		Scanner sc =new Scanner(System.in);
		System.out.print("x=");
		x=sc.nextInt();
		
		t.ktsnt(x);
		
		System.out.println("Nhi Phan cua "+x+" la: "+(t.nhiphan(x)) );
	}

}
