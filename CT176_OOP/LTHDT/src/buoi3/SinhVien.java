package buoi3;

import java.util.Scanner;

import buoi2.Date;

public class SinhVien {
	private String mssv;
	private	String hoten;
	private	Date ngsinh;
	final static int MAX = 50;
	private int slHP;
	private String tenHP[];
	private String diemHP[];
	
	public SinhVien() {
		mssv   = "AAA";
		hoten  = "Nguyen Van A";
		ngsinh = new Date();
		slHP = 0;
		tenHP = new String[MAX];
		diemHP = new String[MAX];
	}
	public SinhVien(SinhVien SV) {
		mssv   = SV.mssv;
		hoten  = SV.hoten;
		ngsinh = SV.ngsinh;
		slHP   = SV.slHP;
		tenHP  = SV.tenHP;
		diemHP = SV.diemHP;
	}
	public SinhVien(String mssv1, String hoten1, Date ngsinh1) {
		mssv   = mssv1;
		hoten  = hoten1;
		ngsinh = ngsinh1;
		slHP = 0;
		tenHP = new String[MAX];
		diemHP = new String[MAX];
	}
	
	public String layHoTen() {
		return hoten;
	}
	
	public void nhapThongTin() {
		Scanner sc = new Scanner(System.in);
		System.out.print("  MSSV: ");
		mssv=sc.nextLine();
		System.out.print("  Ho Ten: ");
		hoten=sc.nextLine();
		System.out.print("  Ngay sinh: ");
		ngsinh.nhap();
        nhapTenHPAll();
	}
	
	public void themTen1HP() {
		Scanner sc = new Scanner(System.in);
		tenHP[slHP]=sc.nextLine();
		slHP+=1;
	}
	
	public void themTen1HP(String str) {
		System.out.println("Da dang ki HP "+str+" cho Sinh vien");
		tenHP[slHP]=str;
		slHP+=1;
	}
	
	public void nhapDiemAll() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap diem hoc phan:");
		for(int i=0;i<slHP;i++) {
			System.out.print("  "+tenHP[i]+": ");
			diemHP[i]=sc.next();
		}
	}
	
	public void xoa1HP() {
		Scanner sc = new Scanner(System.in);
		int temp=-1;
		do {
			System.out.print("Nhap ten hoc phan can xoa");
			String str = sc.nextLine();
			for(int i=0;i<slHP;i++) {
				if(tenHP[i].compareTo(str)==0)  temp=i;
			}
			if(temp==-1) System.out.println("Khong tim thay HP can xoa, nhap lai!");
		}while(temp==-1);
		
		for(int i=temp;i<slHP;i++) {
			tenHP[i]=tenHP[i+1];
			diemHP[i]=diemHP[i+1];
		}
		slHP-=1;
	}
	
	public void nhapTenHPAll() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap so luong hoc phan: ");
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			System.out.print("  Nhap ten HP"+(i+1)+": ");
			themTen1HP();
		}
	}
	
	public String inTenHPAll() {
		String s="";
		for(int i=0;i<slHP;i++) {
			s+=" "+tenHP[i]+";";
		}
		return s;
	}
	
	public String toString() {
		return "MSSV:"+mssv+"; HoTen:"+hoten+"; Ngay Sinh:"+ngsinh+"\n   Cac hoc phan dang ki:"+inTenHPAll();
	}
	
	float tinhDiemTB() {
		float tongDiem = 0;
		for(int i=0;i<slHP;i++) {
			switch(diemHP[i]) {
				case "F":
					tongDiem+=0;
					break;
				case "D":
					tongDiem+=1;
					break;
				case "D+":
					tongDiem+=1.5;
					break;
				case "C":
					tongDiem+=2;
					break;
				case "C+":
					tongDiem+=2.5;
					break;
				case "B":
					tongDiem+=3;
					break;
				case "B+":
					tongDiem+=3.5;
					break;
				case "A":
					tongDiem+=4;
					break;	
			}
		}
		return tongDiem/slHP;
	}
}