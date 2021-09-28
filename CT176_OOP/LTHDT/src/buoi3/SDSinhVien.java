package buoi3;

import java.util.Scanner;

public class SDSinhVien {
	
	public void swapSV(SinhVien arr[], int a, int b) {
		SinhVien temp = new SinhVien(arr[a]);
			arr[a] = arr[b];
			arr[b] = temp;
	}
	
	public void sortbyName(SinhVien arr[], int n) {
		SDSinhVien x  = new SDSinhVien();
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				String si = arr[i].layHoTen();						//Cut name in fullname
				String sj = arr[j].layHoTen();
				si = si.substring(si.lastIndexOf(" ")+1);
				sj = sj.substring(sj.lastIndexOf(" ")+1);
				if(si.compareTo(sj)>0)
					x.swapSV(arr, i, j);
			}
		}
	}

	public static void main(String[] args) {
		SinhVien a = new SinhVien();
		System.out.println("*Nhap thong tin SV a");
		a.nhapThongTin();
		a.nhapDiemAll();
		a.themTen1HP("LTHDT");
		System.out.println("*Thong tin cua SV a: \n"+a);
		System.out.println();
		
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.print("Nhap so luong sinh vien:");
		n=sc.nextInt();
		SinhVien DS[] = new SinhVien[n];
		for(int i=0;i<n;i++) {
			DS[i]=new SinhVien();
			System.out.println("Nhap thong tin sinh vien "+(i+1)+":");
			DS[i].nhapThongTin();
			DS[i].nhapDiemAll();
		}
		
		System.out.println();
		System.out.println("*Cac Sinh vien bi canh cao hoc vu:");
		for(int i=0;i<n;i++)
			if(DS[i].tinhDiemTB()<0.8) System.out.println("- "+DS[i]);
		
		System.out.println();
		float diemMax=DS[0].tinhDiemTB();
		int check = 0;
		for(int i=1;i<n;i++) {
			if(diemMax<DS[i].tinhDiemTB()) {
				diemMax=DS[i].tinhDiemTB();
				check = i;
			}
		}
		System.out.println("*Sinh vien co diem TB cao nhat lop:\n"+DS[check]);
		
		System.out.println();
		SDSinhVien SDSV = new SDSinhVien();
		SDSV.sortbyName(DS, n);
		System.out.println("*Danh sach Sinh vien sau khi sap xep:");
		for(int i=0;i<n;i++)
			System.out.println("- "+DS[i]);		
	}

}
