package Buoi5;

import java.util.Scanner;

public class ChiTiet {
	private HangHoa hh;
	private int sluong;
	private float dgia;
	
	public ChiTiet() {
		hh = new HangHoa();
		sluong = 0;
		dgia = 0.0f;
	}
	public ChiTiet( HangHoa h,int s,float d) {
		hh = new HangHoa(h);
		sluong = s;
		dgia = d;
	}
	public ChiTiet(ChiTiet ct) {
		hh = new HangHoa(ct.hh);
		sluong = ct.sluong;
		dgia = ct.dgia;
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		hh.nhap();
		System.out.println("Nhap so luong:");
		sluong = sc.nextInt();
		System.out.println("Nhap don gia:");
		dgia = sc.nextFloat();
	}
	
	public void in() {
		System.out.println(",[sl:"+sluong+",dongia:"+dgia+"]");
	}
	
	public String toString() {
		return ",[sl:"+sluong+",dongia:"+dgia+"]";
	}
	
	public float laySLuong() {
		return sluong;
	}
	
	public float layDGia() {
		return dgia;
	}
}
