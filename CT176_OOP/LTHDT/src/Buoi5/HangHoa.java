package Buoi5;

import java.util.Scanner;

public class HangHoa {
	private String mso, ten, nsxuat;
	
	public HangHoa() {
		mso = new String();
		ten = new String();
		nsxuat = new String();
	}
	public HangHoa(String mso1, String ten1, String nsxuat1) {
		mso = new String(mso1);
		ten = new String(ten1);
		nsxuat = new String(nsxuat1);
	}
	public HangHoa(HangHoa k) {
		mso = new String(k.mso);
		ten = new String(k.ten);
		nsxuat = new String(k.nsxuat);
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so hang hoa:");
		mso = sc.nextLine();
		System.out.println("Nhap ten hang hoa:");
		ten = sc.nextLine();
		System.out.println("Nhap nha san xuat:");
		nsxuat = sc.nextLine();	
	}
	
	public void in() {
		System.out.println("["+mso+", "+ten+", "+nsxuat+"]");
	}
	
	public String toString() {
		return "["+mso+", "+ten+", "+nsxuat+"]";
	}
}
