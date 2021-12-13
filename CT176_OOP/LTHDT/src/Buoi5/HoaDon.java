package Buoi5;

import java.util.Scanner;

import buoi2.Date;

public class HoaDon {
	private String mso;
	private String tde;
	private String nvien;
	private String nmua;
	private Date date;
	private HangHoa hh[];
	private int sl;
	
	public HoaDon() {
		mso = new String();
		tde = new String();
		nvien = new String();
		nmua = new String();
		date = new Date();
		hh = new HangHoa[100];
		sl = 0;
	}
	public HoaDon(HoaDon hd) {
		mso = new String(hd.mso);
		tde = new String(hd.tde);
		nvien = new String(hd.nvien);
		nmua = new String(hd.nmua);
		date = new Date(hd.date);
		sl = hd.sl;
		hh = new HangHoa[sl];
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("\n Nhap ma so hoa don:");
		mso = sc.nextLine();
		System.out.println("\n Nhap tieu de:");
		tde = sc.nextLine();
		System.out.println("\n Nhap ten nhan vien:");
		nvien = sc.nextLine();
		System.out.println("\n Nhap ten khach hang:");
		nmua = sc.nextLine();
		System.out.println("\n Nhap ngay mua:");
		date.nhap();
		
		System.out.println("\n Nhap so luong chi tiet hang hoa:");
		sl = sc.nextInt();
		System.out.println("Nhap thong tin cac chi tiet hang hoa:");
		for(int i=0;i<sl;i++) {
			System.out.println("\n Nhap hang hoa thu "+(i+1)+":");
			hh[i] = new HangHoa();
			hh[i].nhap();
		}
	}
	
	public void in() {
		System.out.println("\n"+mso+","+tde+", Nguoi lap hdon: "+nvien+", Nguoi mua: "+nmua);
		System.out.println("Cac chi tiet hoa don:");
		for(int i=0;i<sl;i++) {
			System.out.println("+ "+(i+1)+". " + hh[i]);
		}
	}
	
	public String toString() {
		String s= "\n"+mso+","+tde+", Nguoi lap hdon"+nvien+", Nguoi mua: "+nmua;
		s += ("\n Cac chi tiet hoa don:");
		for(int i=0;i<sl;i++) {
			s+=("\n+ "+(i+1)+". " + hh[i]);
		}
		return s;
	}
	
	public static void main(String[] args) {
		HoaDon hd = new HoaDon();
		hd.nhap();
		hd.in();
	}
}
