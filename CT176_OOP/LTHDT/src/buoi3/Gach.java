package buoi3;

import java.util.Scanner;

public class Gach {
	private String maso;
	private String mau;
	private int sl;	//trong 1 hop
	private int dai;
	private int ngang;
	private long gia;			//cua 1 hop
	
	public Gach(){
		maso	= "0000";
		mau  	= "vang";
		sl  	= 20;
		dai 	= 40;
		ngang   = 30;
		gia 	= 100;
	}
	public Gach(String maso1, String mau1, int sl1, int dai1, int ngang1, long gia1){
		maso	= maso1;
		mau  	= mau1;
		sl  	= sl1;
		dai 	= dai1;
		ngang   = ngang1;
		gia 	= gia1;
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so: ");
		maso=sc.next();
		System.out.print("Nhap mau: ");
		mau=sc.next();
		System.out.print("So luong vien trong 1 hop: ");
		sl=sc.nextInt();
		System.out.print("Chieu dai vien gach: ");
		dai=sc.nextInt();
		System.out.print("Chieu ngang vien gach: ");
		ngang=sc.nextInt();
		System.out.print("Gia ban 1 hop: ");
		gia=sc.nextLong();
	}
	
	public void in() {
		System.out.println("Ma so: " + maso);
		System.out.println("Mau: " + mau);
		System.out.println("So luong vien trong 1 hop: " + sl);
		System.out.println("Chieu dai vien gach: " + dai);
		System.out.println("Chieu ngang vien gach: " + ngang);
		System.out.println("Gia ban 1 hop: " + gia);
	}
	
	public float giaBanLe() {
		float giaMotVien = gia/sl;
		return (float)(giaMotVien + giaMotVien*0.2);
	}

	public int dienTichToiDa() {
		return dai*ngang*sl;
	}
	
	public int soLuongHop(int D, int N) {	//D, N don vi la m
		int soVienDai 	= D*100/dai;
		if((D*100)%dai!=0)  soVienDai+=1;
		int soVienNgang = N*100/ngang;
		if((N*100)%ngang!=0) soVienNgang+=1;
		int soVien=soVienDai*soVienNgang;
		return soVien/sl;
	}
	
	public long layGia() {
		return gia;
	}
}
