package Buoi5;

import java.util.Scanner;

public class KhachHangVIP extends KhachHang {
	private float tLeGiam;
	private Date d;
	
	public KhachHangVIP() {
		super();
		tLeGiam = 0.0f;
		d = new Date();
	}
	public KhachHangVIP(KhachHang k,float t, Date d1) {
		super(k);
		tLeGiam = t;
		d = new Date(d1);
	}
	public KhachHangVIP(KhachHangVIP k) {
		super(k);
		tLeGiam = 0.0f;
		d = new Date(k.d);
	}
	
	public void nhap() {
		super.nhap();
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ngay vao VIP");
		d.nhap();
		System.out.println("Nhap ti le Giam");
		tLeGiam = sc.nextFloat();
	}
	
	public void in() {
		super.in();
		System.out.print(", ti le giam:"+tLeGiam+", nam tro thanh VIP:" +d);
	}
	
	public String toString() {
		return super.toString()+(", ti le giam:"+tLeGiam+", nam tro thanh VIP:" +d);
	}
	
	public float layTLeGiam() {
		return tLeGiam;
	}
}
