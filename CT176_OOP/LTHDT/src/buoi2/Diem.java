package buoi2;

import java.util.Scanner;

public class Diem {
	private int x;
	private int y;
	
	public Diem(){
			x=0;
			y=0;
	}
	
	public Diem(int x, int y) {
		this.x=x;
		this.y=y;
	}

	public Diem(Diem a) {
		x = a.x;
		y = a.y;
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap x= ");
		x=sc.nextInt();
		System.out.print("Nhap y= ");
		y=sc.nextInt();
	}

	public void in() {
		System.out.println("("+x+","+y+")");
	}

	public String toString() {
		return "("+x+","+y+")";
	}
	
	public void tinhTien(int dx, int dy) {
		x+=dx;
		y+=dy;
	}

	public int layX() {
		return x;
	}

	public int layY() {
		return y;
	}

	public float khoangCach() {
		return (float)Math.sqrt(Math.pow(x, 2)+Math.pow(y, 2));
	}

	public float khoangCach(Diem d) {
		return (float)Math.sqrt(Math.pow(x-d.x, 2) + Math.pow(y-d.y, 2));
	}

}
