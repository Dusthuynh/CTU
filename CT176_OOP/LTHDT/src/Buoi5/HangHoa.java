package Buoi5;

import java.util.Scanner;

public class HangHoa {
	private String mso, ten, nsxuat;
	private int sl;
	private float dgia;
	
	public HangHoa() {
		mso = new String();
		ten = new String();
		nsxuat = new String();
		sl = 0;
		dgia = 0.0f;
	}
	public HangHoa(String mso1, String ten1, String nsxuat1, int sl1, float dgia1) {
		mso = new String(mso1);
		ten = new String(ten1);
		nsxuat = new String(nsxuat1);
		sl = sl1;
		dgia=dgia1;
	}
	public HangHoa(HangHoa k) {
		mso = new String(k.mso);
		ten = new String(k.ten);
		nsxuat = new String(k.nsxuat);
		sl = k.sl;
		dgia = k.dgia;
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so hang hoa:");
		mso = sc.nextLine();
		System.out.println("Nhap ten hang hoa:");
		ten = sc.nextLine();
		System.out.println("Nhap nha san xuat:");
		nsxuat = sc.nextLine();	
		System.out.println("Nhap so luong:");
		sl = sc.nextInt();	
		System.out.println("Nhap don gia:");
		dgia = sc.nextFloat();
	}
	
	public void in() {
		System.out.println("["+mso+", "+ten+", "+nsxuat+", So luong:"+sl+",Don gia:"+dgia+"]");
	}
	
	public String toString() {
		return "["+mso+", "+ten+", "+nsxuat+", So luong:"+sl+",Don gia:"+dgia+"]";
	}
}
