package buoi2;

import java.util.Scanner;

public class SDSinhVien {
	
	public static void main(String[] args) {
		SinhVien x  = new SinhVien();
		Scanner sc = new Scanner(System.in);
		int n;
		
		System.out.println("Nhap so luong sinh vien");
		n = sc.nextInt();
		SinhVien SV[] = new SinhVien[n];
		for(int i=0; i<n; i++) {
			SV[i] = new SinhVien();
			System.out.println("Sinh vien thu "+(i+1)+": ");
			SV[i].input();
		}
		x.ouputForm();
		for(int i=0; i<n; i++)
			SV[i].display();
		
		
		System.out.println("--Edit 1 SV--");
		x.edit(SV);
		System.out.println("--Sau khi edit--");
		x.ouputForm();
		for(int i=0; i<n; i++) 
			SV[i].display();
		
		System.out.println("--Delete 1 SV--");
		x.delete(SV);
		n--;
		x.ouputForm();
		for(int i=0; i<n; i++)
			SV[i].display();
		
		System.out.println("--Sort by GPA--");
		x.sortbyGPA(SV,n);
		x.ouputForm();
		for(int i=0; i<n; i++)
			SV[i].display();
			
		System.out.println("--Sort by Name--");
		x.sortbyName(SV,n);
		x.ouputForm();
		for(int i=0; i<n; i++)
			SV[i].display();
	}	

}
