package buoi2;

import java.util.Scanner;

public class SinhVien {
	private String id;
	private String name;
	private String address;
	private double gpa;
	
	public SinhVien() {
		id = "0";
		name = "Nguyen Van A";
		address = "6/9 Duong 3/2, Quan Ninh Kieu, TP Can Tho";
		gpa = 0;
	}
	
	public SinhVien(String id, String name, String address, double gpa) {
		this.id = id;
		this.name = name;
		this.address = address;
		this.gpa = gpa;
	}
	
	public SinhVien(SinhVien x){
		this.id = x.id;
		this.name = x.name;
		this.address = x.address;
		this.gpa = x.gpa;
	}
//-------------------------------------------------------------------------------------------//
	public void input() {
		Scanner sc = new Scanner(System.in);
		System.out.println("-Nhap vao thong tin SV:");
		System.out.print("ID: ");
		id = sc.nextLine();
		System.out.print("Name: ");
		name = sc.nextLine();
		System.out.print("Address: ");
		address = sc.nextLine();
		System.out.print("GPA: ");
		gpa = sc.nextDouble();
	}
//-------------------------------------------------------------------------------------------//
	public void ouputForm() {
		String line = new String(new char[100]).replace('\0', '-');
		System.out.println(line);
		System.out.printf("    ID    |        NAME        |                                ADDRESS                     | GPA\n");
		System.out.println(line);
	}
	public void display() {
		System.out.printf("%-10s|%-20s|%-60s|%.2f\n",id,name,address,gpa);
	}
//-------------------------------------------------------------------------------------------//
	public int takeIndexbyID(SinhVien arr[]) {
		Scanner sc = new Scanner(System.in);
		String takeID;
		boolean check = false;
		int temp=0;
		do {
			System.out.print("Nhap ID can thay doi: ");
			takeID = sc.nextLine();
			for(int i=0;i<arr.length;i++) {
				if(takeID.compareTo(arr[i].id)==0) {
					check = true;
					temp = i;
					break;
				}
			}
			if(!check) System.out.println("Khong tim thay ID trong DS, vui lòng nhap lai.");
		}while(!check);
		
		return temp;
	}
//-------------------------------------------------------------------------------------------//
	public void swapSV(SinhVien arr[], int a, int b) {
		SinhVien temp = new SinhVien(arr[a]);
			arr[a] = arr[b];
			arr[b] = temp;
	}
//-------------------------------------------------------------------------------------------//
	public void edit(SinhVien arr[],int n) {
		if (n==0) System.out.println("!!! Danh sach rong !!!");
		else {
			int idx = takeIndexbyID(arr);
			System.out.println("Sua thong tin sinh vien co ID="+arr[idx].id+" :");
			Scanner sc = new Scanner(System.in);
			System.out.println("-Nhap thong tin SV:");
			System.out.print("Name: ");
			arr[idx].name = sc.nextLine();
			System.out.print("Address: ");
			arr[idx].address = sc.nextLine();
			System.out.print("GPA: ");
			arr[idx].gpa = sc.nextDouble();
		}
	}
//-------------------------------------------------------------------------------------------//
	public void delete(SinhVien arr[],int n){
		if (n==0) System.out.println("!!! Danh sach rong !!!");
		else{
			int k = takeIndexbyID(arr);
			SinhVien x  = new SinhVien();
			for(int i=k;i<n;i++)
				x.swapSV(arr,i,i+1);
		}
	}
//-------------------------------------------------------------------------------------------//
	public void sortbyGPA(SinhVien arr[], int n) {
		SinhVien x  = new SinhVien();
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				if(arr[i].gpa > arr[j].gpa)
					x.swapSV(arr, i, j);
			}
		}
	}
//-------------------------------------------------------------------------------------------//
	public void sortbyName(SinhVien arr[], int n) {
		SinhVien x  = new SinhVien();
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				String si = arr[i].name;						//Cut name in fullname
				String sj = arr[j].name;
				si = si.substring(si.lastIndexOf(" ")+1);
				sj = sj.substring(sj.lastIndexOf(" ")+1);
				if(si.compareTo(sj)>0)
					x.swapSV(arr, i, j);
			}
		}
	}
//-------------------------------------------------------------------------------------------//
	public static void main(String[] args) {
	}

}
