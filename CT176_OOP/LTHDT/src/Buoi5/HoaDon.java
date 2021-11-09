package Buoi5;

import java.util.Scanner;

public class HoaDon {
	private String mso;
	private String tde;
	private String nvien;
	private KhachHang khachHang;
	private Date nLap;
	private ChiTiet c[];
	private int sl;
	
	public HoaDon() {
		mso = new String();
		tde = new String();
		nvien = new String();
		khachHang = new KhachHang();
		nLap = new Date();
		c = new ChiTiet[20];
		sl = 0;
	}
	public HoaDon(HoaDon hd) {
		mso = new String(hd.mso);
		tde = new String(hd.tde);
		nvien = new String(hd.nvien);
		khachHang = new KhachHang(hd.khachHang);
		nLap = new Date(hd.nLap);
		c = new ChiTiet[hd.c.length];
		sl = hd.sl;
		for(int i=0;i<sl;i++) {
			c[i] = new ChiTiet(hd.c[i]);
		}
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("\n Nhap ma so hoa don:");
		mso = sc.nextLine();
		System.out.println("\n Nhap tieu de:");
		tde = sc.nextLine();
		System.out.println("\n Nhap ten nhan vien:");
		nvien = sc.nextLine();
		System.out.println("\n Nhap ngay lap hoa don:");
		nLap.nhap();
		
		int select=0;
		System.out.println("\n Nhap thong tin khach hang(0) hay khach hang VIP(1):");
		select = sc.nextInt();
		if(select == 0) khachHang = new KhachHang();
		else khachHang = new KhachHangVIP();
		khachHang.nhap();
		
		System.out.println("\n Nhap so luong chi tiet hang hoa:");
		sl = sc.nextInt();
		System.out.println("Nhap thong tin cac chi tiet hang hoa:");
		for(int i=0;i<sl;i++) {
			System.out.println("\n Nhap hang hoa thu "+(i+1)+":");
			c[i] = new ChiTiet();
			c[i].nhap();
		}
	}
	
	public void in() {
		System.out.println(mso+","+tde+"\n Nguoi lap hdon: "+nvien
				+"\n Ngay lap"+ nLap + "\n Khach hang: "+ khachHang);
		System.out.println("\n Cac chi tiet hoa don:");
		for(int i=0;i<sl;i++) {
			System.out.println("\n + "+(i+1) + c[i]);
		}
		System.out.println("\n Tong so tien " + tong());
	}
	
	public String toString() {
		String s= mso+","+tde+"\n Nguoi lap hdon"+nvien
				+"\n Ngay lap"+ nLap + "\n Khach hang: "+ khachHang;
		s += ("\n Cac chi tiet hoa don:");
		for(int i=0;i<sl;i++) {
			s+=("\n + "+(i+1) + c[i]);
		}
		s+=("\n Tong so tien " + tong());
		return s;
	}
	
	public float tong() {
		float res = 0.0f;
		for(int i=0;i<sl;i++) {
			res+=c[i].laySLuong() * c[i].layDGia();
		}
		res = res - res*khachHang.layTLeGiam();
		return res;
	}
}
