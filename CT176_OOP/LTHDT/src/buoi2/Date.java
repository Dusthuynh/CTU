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
		do {
			System.out.println("Nhap date: ");
			Scanner sc = new Scanner(System.in);
			String date=sc.next();
			String[] arr=(date.split("/"));
			ngay = Integer.parseInt(arr[0]);
			thang = Integer.parseInt(arr[1]);
			nam = Integer.parseInt(arr[2]);
		}while(!hopLe());
	}
//==============================DustHuyn==============================//
	public boolean hopLe() {
		boolean check = true;
		if(ngay<0) check = false;
		if(thang>12 || thang<0) check = false;
		
		if((thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10 || thang==12) && (ngay>31))
			check = false;
		else 
		if((thang==4 || thang==6 || thang==9 || thang==11) && (ngay>30))
			check = false;
		else 
		if((thang==2) && ((nam%4==0 && nam%100!=0) || nam%400==0) && ((ngay>29)))
			check = false;
		else 
		if((thang==2) && !((nam%4==0 && nam%100!=0) || nam%400==0) && ((ngay>28))) 
			check = false;
		return check;
	}
//==============================DustHuyn==============================//
	public int checkLastDay() {
		int check=0;
		
		if((thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10) && (ngay==31)) 
			check = 1;
		if((thang==4 || thang==6 || thang==9 || thang==11) && (ngay==30))
			check = 1;
		if(((nam%4==0 && nam%100!=0) || nam%400==0) && (ngay==29) && (thang==2))
			check = 1;
		if((!(nam%4==0 && nam%100!=0) || nam%400==0) && (ngay==28) && (thang==2))
			check = 1;
		
		if(thang==12 && ngay==31)
			check = 2;
		
		return check;
	}
//==============================DustHuyn==============================//
	public void ngayHomsau(){
		if(checkLastDay()==1) {
			ngay=1;
			thang+=1;
		}else
		if(checkLastDay()==2){
			ngay=1;
			thang=1;
			nam+=1;
		}else 
		if(checkLastDay()==0) {
			ngay+=1;
		}
	}
//==============================DustHuyn==============================//
	public void congNgay(int n) {
		for(int i=0;i<n;i++) {
			ngayHomsau();
		}
	}
	
	public static void main(String[] args) {
		
	}

}
