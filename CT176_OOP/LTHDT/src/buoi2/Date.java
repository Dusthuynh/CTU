package buoi2;

import java.util.Scanner;

public class Date {
	private int ngay;
	private int thang;
	private int nam;
	
	public Date() {
		this.ngay=1;
		this.thang=1;
		this.nam=1990;
	}
	
	public Date(int ngay, int thang, int nam) {
		this.ngay=ngay;
		this.thang=thang;
		this.nam=nam;
	}
//==============================DustHuyn==============================//
	public void display() {
		System.out.printf("%02d/%02d/%4d\n",this.ngay,this.thang,this.nam);
	}
//==============================DustHuyn==============================//
	public void input() {
		do {
			System.out.println("Nhap date: ");
			Scanner sc = new Scanner(System.in);
			String date=sc.next();
			String[] arr=(date.split("/"));
			this.ngay = Integer.parseInt(arr[0]);
			this.thang = Integer.parseInt(arr[1]);
			this.nam = Integer.parseInt(arr[2]);
		}while(!hopLe());
	}
//==============================DustHuyn==============================//
	public boolean hopLe() {
		boolean check = true;
		if(this.ngay<0) check = false;
		if(this.thang>12 || this.thang<0) check = false;
		
		if((this.thang==1 || this.thang==3 || this.thang==5 || this.thang==7 || this.thang==8 || this.thang==10 || this.thang==12) && (this.ngay>31))
			check = false;
		else 
		if((this.thang==4 || this.thang==6 || this.thang==9 || this.thang==11) && (this.ngay>30))
			check = false;
		else 
		if((this.thang==2) && ((this.nam%4==0 && this.nam%100!=0) || this.nam%400==0) && ((this.ngay>29)))
			check = false;
		else 
		if((this.thang==2) && !((this.nam%4==0 && this.nam%100!=0) || this.nam%400==0) && ((this.ngay>28))) 
			check = false;
		return check;
	}
//==============================DustHuyn==============================//
	public int checkLastDay() {
		int check=0;
		
		if((this.thang==1 || this.thang==3 || this.thang==5 || this.thang==7 || this.thang==8 || this.thang==10) && (this.ngay==31)) 
			check = 1;
		if((this.thang==4 || this.thang==6 || this.thang==9 || this.thang==11) && (this.ngay==30))
			check = 1;
		if(((this.nam%4==0 && this.nam%100!=0) || this.nam%400==0) && (this.ngay==29) && (this.thang==2))
			check = 1;
		if((!(this.nam%4==0 && this.nam%100!=0) || this.nam%400==0) && (this.ngay==28) && (this.thang==2))
			check = 1;
		
		if(this.thang==12 && this.ngay==31)
			check = 2;
		
		return check;
	}
//==============================DustHuyn==============================//
	public void ngayHomsau(){
		if(checkLastDay()==1) {
			this.ngay=1;
			this.thang+=1;
		}else
		if(checkLastDay()==2){
			this.ngay=1;
			this.thang=1;
			this.nam+=1;
		}else 
		if(checkLastDay()==0) {
			this.ngay+=1;
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
