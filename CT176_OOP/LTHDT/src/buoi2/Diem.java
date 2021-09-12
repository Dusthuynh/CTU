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
//==============================DustHuyn==============================//
	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap x= ");
		x=sc.nextInt();
		System.out.print("Nhap y= ");
		y=sc.nextInt();
	}
//==============================DustHuyn==============================//
	public void hienthi() {
		System.out.println("("+x+","+y+")");
	}
//==============================DustHuyn==============================//
	public void doiDiem(int dx, int dy) {
		x+=dx;
		y+=dy;
	}
//==============================DustHuyn==============================//
	public int giaTriX() {
		return x;
	}
//==============================DustHuyn==============================//
	public int giaTriY() {
		return y;
	}
//==============================DustHuyn==============================//
	public float khoangCach() {
		return (float)Math.sqrt(Math.pow(x, 2)+Math.pow(y, 2));
	}
//==============================DustHuyn==============================//
	public float khoangCach(Diem d) {
		return (float)Math.sqrt(Math.pow(x-d.x, 2) + Math.pow(y-d.y, 2));
	}
//==============================DustHuyn==============================//

	public static void main(String[] args) {
		
	}

}
