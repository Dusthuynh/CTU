package b2012232;

import java.util.Scanner;
// STT: 49; MSSV: B2012232; HoTen: Huynh Minh Nghia; Nhom: 6; So de: 1.

public class NhanVien {
	private String msnv;
	private String hten;
	private String cvu;
	private int tnien;
	
	
	public NhanVien() {
		msnv = new String();
		hten = new String();
		cvu = new String();
		tnien = 0;
	}
	public NhanVien(String m, String h, String c, int t) {
		msnv = new String(m);
		hten = new String(h);
		cvu = new String(c);
		tnien = t;
	}
	public NhanVien(NhanVien n) {
		msnv = new String(n.msnv);
		hten = new String(n.hten);
		cvu = new String(n.cvu);
		tnien = n.tnien;
	}
	
	public String layMSNV(){
		return msnv;
	}
	public String layHoTen() {
		return hten;
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap thong tin Nhan vien");
		System.out.println("Nhap ma so nhan vien");
		msnv = sc.nextLine();
		System.out.println("Nhap ho va ten");
		hten = sc.nextLine();
		System.out.println("Nhap chuc vu");
		cvu = sc.nextLine();
		System.out.println("Nhap tham nien cong tac");
		tnien = sc.nextInt();
	}
	public void hthi() {
		System.out.println("[MSNV: "+msnv+", Ho ten: "+hten+", Chuc vu: "+cvu+", tham niem cong tac: "+tnien+"]");
	}
	
	public static void main(String[] args) {
		NhanVien nv1 = new NhanVien();
		nv1.nhap();
		nv1.hthi();
		
		NhanVien nv2 = new NhanVien("12345","Tran Tue Chau","",30);
		nv2.hthi();
	}
}
