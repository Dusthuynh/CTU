package A_xulyso;

import java.util.Scanner;

//Viết chương trình chuyển đổi một số tự nhiên ở hệ số 10 thành một số ở hệ cơ số B (1 <= B <= 32) bất kỳ
public class bai3 {
	public static void main(String[] args) {
		int n,b;
		Scanner sc= new Scanner(System.in);
		System.out.println("nhap n, b: ");
		n = sc.nextInt();
		b = sc.nextInt();
		String str = chuyen(n,b);
		System.out.print("Gia tri "+n+" chuyen tu he 10 sang he "+b+" :");

		System.out.println(str);
	}
	
	/*static void xuat(String str) {
		for(int i=0; i<str.length();i++) {
			System.out.print(str.charAt(str.length()-i-1));
		}
	}*/
	
	static String chuyen(int n,int b) {
		String str="";
		int x=0;
		while(n>0) {
			x  = n%b;
			n /= b;
			if(x>9) {
				x+=55;
				str=(char)x + str;
			}
			else str=x + str;	
		}
		return str;
	}

}
