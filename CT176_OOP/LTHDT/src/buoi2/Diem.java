package buoi2;

import java.util.Scanner;

public class Diem {
	int x,y;
	public Diem(){
			this.x=0;
			this.y=0;
	}
	
	public Diem(int a, int b) {
		this.x=a;
		this.y=b;
	}
//==============================DustHuyn==============================//
	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap x:");
		this.x=sc.nextInt();
		System.out.print("Nhap y:");
		this.y=sc.nextInt();
	}
//==============================DustHuyn==============================//
	public void hienthi() {
		System.out.println("("+this.x+","+this.y+")");
	}
//==============================DustHuyn==============================//
	public void doiDiem(int dx, int dy) {
		this.x+=dx;
		this.y+=dy;
	}
//==============================DustHuyn==============================//
	public int giaTriX() {
		return this.x;
	}
//==============================DustHuyn==============================//
	public int giaTriY() {
		return this.y;
	}
//==============================DustHuyn==============================//
	public float khoangCach() {
		return (float)Math.sqrt(Math.pow(this.x, 2)+Math.pow(this.y, 2));
	}
//==============================DustHuyn==============================//
	public float khoangCach(Diem d) {
		return (float)Math.sqrt(Math.pow(this.x-d.x, 2) + Math.pow(this.y-d.y, 2));
	}
//==============================DustHuyn==============================//

	public static void main(String[] args) {
		
	}

}
