package buoi3;

import java.util.Scanner;

import buoi2.Diem;

public class DoanThang {
	private Diem d1,d2;

	public DoanThang() {
		d1 = new Diem();
		d2 = new Diem();
	}

	public DoanThang(Diem da, Diem db) {
		d1 = new Diem(da);
		d2 = new Diem(db);
	}
	
	public DoanThang(int x1, int y1, int x2, int y2) {
		d1 = new Diem(x1,y1);
		d2 = new Diem(x2,y2);
	}
	
	public void nhap() {
		System.out.println("Nhap toa do diem dau: ");
		d1.nhap();
		System.out.println("Nhap toa do diem cuoi: ");
		d2.nhap();
	}
	
	public void in() {
		System.out.println("[");
		d1.in();
		System.out.println(",");
		d2.in();
		System.out.println("]");
	}
	
	public String toString() {
		return "[" + d1 + "," + d2 + "]";
	}
	
	public void tinhTien(int dx, int dy) {
		d1.tinhTien(dx, dy);
		d2.tinhTien(dx, dy);
	}
	
	public float doDai() {
		return d1.khoangCach(d2);
	}
}
