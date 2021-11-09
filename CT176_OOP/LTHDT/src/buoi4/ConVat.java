package buoi4;

import java.util.Scanner;

public abstract class ConVat {
	private String giong;
	private String mauLong;
	private float canNang;
	private static int count =0;
	public abstract void keu();
	
	public ConVat() {
		giong = new String();
		mauLong = new String();
		canNang = 0.0f;
		count++;
	}
	public ConVat(String giong1, String mauLong1, float canNang1) {
		giong = new String(giong1);
		mauLong = new String(mauLong1);
		canNang = canNang1;
		count++;
	}
	public ConVat(ConVat c) {
		giong = new String(c.giong);
		mauLong = new String(c.mauLong);
		canNang = c.canNang;
		count++;
	}
	
	public void nhap() {
		Scanner sc= new Scanner(System.in);
		System.out.print("Nhap giong: ");
		giong = sc.nextLine();
		System.out.print("Nhap ten mau long: ");
		mauLong = sc.nextLine();
		System.out.print("Nhap can nang (kg): ");
		canNang = sc.nextFloat();
	}
	
	public void in() {
		System.out.println("Giong: "+giong+", mau long: "+mauLong+", can nang: "+canNang+"kg.\n");
	}
	
	public String toTring() {
		return "Giong: "+giong+", mau long: "+mauLong+", can nang: "+canNang+"kg.\n";
	}
	
	public int layCount() {
		return count;
	}
}
