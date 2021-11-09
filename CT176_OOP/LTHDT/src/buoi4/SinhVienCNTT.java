package buoi4;

import java.util.Scanner;

import buoi3.SinhVien;

public class SinhVienCNTT extends SinhVien{
	private String tKhoan;
	private String mKhau;
	private String email;
	
	public SinhVienCNTT() {
		super();
		tKhoan = new String();
		mKhau = new String();
		email = new String();
	}
	public SinhVienCNTT(SinhVien s, String tk, String mk, String e) {
		super(s);
		tKhoan = new String(tk);
		mKhau = new String(mk);
		email = new String(e);
	}
	public SinhVienCNTT(SinhVienCNTT s) {
		super(s);
		tKhoan = new String(s.tKhoan);
		mKhau = new String(s.mKhau);
		email = new String(s.email);
	}
	
	public void nhapThongTin() {
		super.nhapThongTin();
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap tai khoan: ");
		tKhoan = sc.nextLine();
		System.out.print("Nhap mat khau: ");
		mKhau = sc.nextLine();
		System.out.print("Nhap email: ");
		email = sc.nextLine();
	}
	
	public void in() {
		super.in();
		System.out.print("Tai khoan: "+tKhoan+", Email: "+email+"\n");
	}
	
	public String toString() {
		return super.toString() + "Tai khoan: "+tKhoan+", Email: "+email+"\n";
	}
	
	public void doiMatKhau(String mk1) {
		mKhau = mk1;
	}
	
	public String layEmail(SinhVienCNTT s) {
		return s.email;
	}
	
}
