package buoi2;

import java.util.Scanner;

public class Date {
	private int ngay;
	private int thang;
	private int nam;
	
	public Date() {
		ngay=1;
		thang=1;
		nam=1990;
	}
	
	public Date(int ngay, int thang, int nam) {
		this.ngay=ngay;
		this.thang=thang;
		this.nam=nam;
	}
//==============================DustHuyn==============================//
	public void display() {
		System.out.printf("%02d/%02d/%4d\n",ngay,thang,nam);
	}
//==============================DustHuyn==============================//
	public void input() {
		Scanner sc = new Scanner(System.in);
		do {
			System.out.println("Nhap date: ##/##/####");
			String date=sc.next();
			String[] arr=(date.split("/"));
			ngay = Integer.parseInt(arr[0]);
			thang = Integer.parseInt(arr[1]);
			nam = Integer.parseInt(arr[2]);
			if(!hopLe()) System.out.println("Nhap loi, vui long nhap lai:");
		}while(!hopLe());
	}
//==============================DustHuyn==============================//
	public boolean hopLe() {
				   //0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12
		int max[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		if ((nam%4==0 && nam%100!=0) || nam%400==0) max[2]=29;
		
		boolean check = false;
		if(ngay>0 && thang>0 && nam>0 && thang<13 && ngay<=max[thang]) 
			check = true;
		return check;
	}
//==============================DustHuyn==============================//
	public Date ngayHomsau(){
		Date res = new Date(ngay, thang, nam);
		res.ngay++;
		if(!res.hopLe()) {
			res.ngay=1;
			res.thang++;
			
			if(!res.hopLe()) {
				res.thang=1;
				res.nam++;
			}
		}
		return res;
	}
//==============================DustHuyn==============================//
	public Date congNgay(int n) {
		Date res = new Date(ngay, thang, nam);
		for(int i=0;i<n;i++) {
			res = res.ngayHomsau();
		}
		return res;
	}
	
	public static void main(String[] args) {
		
	}

}
