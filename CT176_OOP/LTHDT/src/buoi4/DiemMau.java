package buoi4;

import java.util.Scanner;

import buoi2.Diem;

public class DiemMau extends Diem{
	private String mau;
	
	public DiemMau() {
		super();
		mau = new String();
	}
	public DiemMau(int x1, int y1, String m1) {
		super(x1,y1);
		mau = new String(m1);
	}
	public DiemMau(DiemMau a) {
		super(a);
		mau = new String(a.mau);
	}
	
	public void GanMau(String mau1) {
		mau = mau1;
	}
	public void nhap() {
		super.nhap();
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap mau: ");
		mau = sc.nextLine();
	}
	public void in() {
		super.in();
		System.out.print(", mau: "+mau+"\n");
	}
	public String toString(){
		return super.toString() + ", mau: "+mau+"\n";
	}
	
}
