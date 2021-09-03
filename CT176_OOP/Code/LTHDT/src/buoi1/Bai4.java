package buoi1;

import java.util.Scanner;

public class Bai4 {
	public int nhap () {
		Scanner sc = new Scanner(System.in);
		String s; int n;
		do {
			System.out.println("Nhap vao mot so nguyen: ");
			s = sc.nextLine();
			try {n= Integer.parseInt(s);}
			catch(NumberFormatException e) {
				n = Integer.MAX_VALUE;
				System.out.println("Nhap sai dinh dang, yeu cau nhap lai");
			}
		}while(n==Integer.MAX_VALUE);
		return n;
	}
	public static void main(String[] args) {
		Bai4 t = new Bai4();
		int a= t.nhap();
		int b= t.nhap();
		System.out.println("a+b= "+(a+b));
	}

}
