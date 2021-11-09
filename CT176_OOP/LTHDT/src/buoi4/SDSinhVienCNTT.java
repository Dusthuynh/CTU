package buoi4;

import java.util.Scanner;

import buoi3.SinhVien;

public class SDSinhVienCNTT {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.print("Nhap so luong sinh vien: ");
		n = sc.nextInt();
		SinhVien ds[] = new SinhVien[n];
		for(int i=0; i<n;i++) {
			int check = -1;
			System.out.println("Nhap thong tin SV "+(i+1)+": ");
			System.out.println("Ban nhap sinh vien(0) hay sinh vien CNTT(1)");
			check = sc.nextInt();
			String c = sc.nextLine();
			if(check==0) ds[i] = new SinhVien();
			else if(check==1) ds[i] = new SinhVienCNTT();
			ds[i].nhapThongTin();
			ds[i].nhapDiemAll();
		}
		
		for(int i=0; i<n;i++) {
			System.out.println(ds[i]);
		}
		
		
		System.out.println("Nhap vao dia chi mail cua SV can tim: ");
		String email1 = sc.nextLine();
		boolean checkEmail = false;
		for(int i=0;i<n;i++) {
			if(email1.equals(ds[i].layEmail())) {
				System.out.format("Diem trung binh cua sinh vien co email tren: %.2f \n",ds[i].tinhDiemTB());
				checkEmail = true;
			}
		}
		if(!checkEmail) System.out.println("!!!Khong tim thay Sinh vien!!!");
		
		for(int i=0;i<n-1;i++)
			for(int j=1;j<n;j++) {
				if(ds[i].tinhDiemTB()<ds[j].tinhDiemTB()) {
					SinhVien temp = new SinhVien(ds[i]);
					ds[i] = ds[j];
					ds[j] = temp;
				}
			}
		System.out.println("Danh Sach sinh vien sau khi sap xep theo diem TB giam dan: ");
		for(int i=0; i<n;i++) {
			System.out.println(ds[i]);
		}
	}
}
