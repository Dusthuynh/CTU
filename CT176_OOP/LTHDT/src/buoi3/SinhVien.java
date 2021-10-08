package buoi3;

import java.util.Scanner;

import buoi2.Date;

public class SinhVien {
	private String mssv;
	private	String hoten;
	private	Date ngsinh;
	private int MAX;
	private int slHP;
	private String tenHP[];
	private String diemHP[];
	
	public SinhVien() {
		mssv   = new String();
		hoten  = new String();
		ngsinh = new Date();
		slHP = 0;
		MAX = 60;
		tenHP = new String[MAX];
		diemHP = new String[MAX];
	}
	
	public SinhVien(int max1) {
		mssv   = new String();
		hoten  = new String();
		ngsinh = new Date();
		slHP = 0;
		MAX = max1;
		tenHP = new String[MAX];
		diemHP = new String[MAX];
	}
	
	public SinhVien(SinhVien SV) {
		mssv   = new String(SV.mssv);
		hoten  = new String(SV.hoten);
		ngsinh = new Date(SV.ngsinh);
		slHP   = SV.slHP;
		MAX = SV.MAX;
		tenHP  = new String[MAX];
		diemHP = new String[MAX];
		for(int i=0; i<slHP; i++) {
			tenHP[i]  = new String(SV.tenHP[i]);
			diemHP[i] = new String(SV.diemHP[i]);
		}
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
		System.out.print("Nhap so luong hoc phan: ");
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			System.out.print("  Nhap ten HP"+(i+1)+": ");
			themTen1HP();
		}
	}
	
	public void themTen1HP() {
		Scanner sc = new Scanner(System.in);
		tenHP[slHP]=sc.nextLine();
		slHP+=1;
	}
	
	public void themTen1HP(String ten) {
		tenHP[slHP] = new String(ten);
		diemHP[slHP] = "(chua co)";
		slHP+=1;
	}
	
	public void them1HP(String ten, String diem) {
		if(slHP < MAX-1) {
			System.out.println("Da dang ki HP "+ten+" cho Sinh vien");
			tenHP[slHP]= new String(ten);
			diemHP[slHP]= new String(diem);
			slHP++;
		}
		else System.out.println("Ban khong the them vi da day!!");
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
	
	public void in() {
		System.out.println("MSSV:"+mssv+"; HoTen:"+hoten+"; Ngay Sinh:"+ngsinh+"\n    ");
		for(int i=0;i<slHP;i++) {
			System.out.println(" "+tenHP[i]+":"+diemHP[i]+";");
		}
	}
	
	public String toString() {
		String s = "MSSV:"+mssv+"; HoTen:"+hoten+"; Ngay Sinh:"+ngsinh+"\n    ";
		for(int i=0;i<slHP;i++) {
			s = s + tenHP[i]+":"+diemHP[i]+", ";
		}
		return s;
	}
	
	float tinhDiemTB() {
		float tongDiem = 0;
		int count = 0;
		for(int i=0;i<slHP;i++) {
			switch(diemHP[i]) {
				case "F":
					tongDiem+=0;
					count ++;
					break;
				case "D":
					tongDiem+=1;
					count ++;
					break;
				case "D+":
					tongDiem+=1.5;
					count ++;
					break;
				case "C":
					tongDiem+=2;
					count ++;
					break;
				case "C+":
					tongDiem+=2.5;
					count ++;
					break;
				case "B":
					tongDiem+=3;
					count ++;
					break;
				case "B+":
					tongDiem+=3.5;
					count ++;
					break;
				case "A":
					tongDiem+=4;
					count ++;
					break;	
			}
		}
		return tongDiem/count;
	}
}