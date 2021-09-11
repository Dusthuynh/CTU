package buoi1;

import java.util.Scanner;

public class Bai7 {
	public String tachten(String chuoi) {
		chuoi=chuoi.trim();					
		int k=chuoi.lastIndexOf(" ");		
		String res=chuoi.substring(k+1);	
		return res;	
	}
	
	public static void main(String[] args) {	
		Scanner sc =new Scanner(System.in);
		System.out.println("Nhap Ho ten: ");
		String hoten = sc.nextLine();
		
		Bai7 t = new Bai7();
		String ten =t.tachten(hoten);
		
		System.out.println("Ten:"+ten);
	}

}
