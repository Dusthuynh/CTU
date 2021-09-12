package buoi2;

import java.util.Scanner;

public class PhanSo {
	int tu;
	int mau;
	public PhanSo() {
		tu = 0;
		mau = 1;
	}
	
	public PhanSo(int tu, int mau) {
		this.tu=tu;
		this.mau=mau;
	}
//==============================DustHuyn==============================//
	public void input() {
		Scanner sc = new Scanner(System.in);
		do {
			System.out.println("Nhap gia tri cho phan so:");
			System.out.print("Tu so:");
			this.tu=sc.nextInt();
			System.out.print("Mau so:");
			this.mau=sc.nextInt();
		} while(this.mau==0);
		
	}
//==============================DustHuyn==============================//
	public void chuanhoa(PhanSo x) {
		if(x.tu!=0 && x.mau<0) {
			x.mau=-x.mau;
			x.tu=-x.tu;
		}	
	}
	public void chuanhoa() {
			if(this.tu!=0 && this.mau<0) {
				this.mau=-this.mau;
				this.tu=-this.tu;
			}
	}
//==============================DustHuyn==============================//	
	public void display() {
		chuanhoa();
		int mau = this.mau;
		int tu  = this.tu;

		if (tu==0){
			System.out.println("0");
		}else if (mau==1) {
			System.out.println(tu);
		}else
			System.out.printf("%d/%d\n",tu,mau);
	}
//==============================DustHuyn==============================//
	public void nghichDao() {
		int temp=this.tu;
		this.tu=this.mau;
		this.mau=temp;
	}
//==============================DustHuyn==============================//
	public PhanSo giatriNghichDao() {	
		int tu  = this.mau;
		int mau = this.tu;
		PhanSo x = new PhanSo(tu,mau);
		return x;
	}
//==============================DustHuyn==============================//
	public float giatriThuc() {
		float tu = this.tu;
		float mau= this.mau;
		return (tu/mau);
	}
//==============================DustHuyn==============================//
	public boolean lonHon(PhanSo a) {
		if(giatriThuc() > a.giatriThuc())
			return true;
		else return false;
	}
//==============================DustHuyn==============================//
	public PhanSo cong(PhanSo a) {
		PhanSo x = new PhanSo();
		x.tu =this.tu;
		x.mau=this.mau;
		
		quydongCungMau(x, a);
		x.tu+=a.tu;
		x = rutgon(x);
		return x;
	}
//==============================DustHuyn==============================//
	public PhanSo tru(PhanSo a) {
		if(a.tu>0) a.tu=-a.tu;
		else if(a.mau>0) a.mau=-a.mau;
		return this.cong(a);
	}
//==============================DustHuyn==============================//
	public PhanSo nhan(PhanSo a) {
		int mau = this.mau*a.mau;
		int tu  = this.tu*a.tu;
		PhanSo x = new PhanSo(tu, mau);
		return x;
	}
//==============================DustHuyn==============================//
	public PhanSo chia(PhanSo a) {
		a = a.giatriNghichDao();
		return nhan(a);
	}
	
//==============================DustHuyn==============================//	
	public PhanSo rutgon(PhanSo x) {
		int min = Math.abs(x.tu);
		if(Math.abs(x.tu) > Math.abs(x.mau)) min=x.mau;
		for(int i=min;i>1;i--) {
			if(x.mau%i==0 && x.tu%i==0) {
				x.tu/=i;
				x.mau/=i;
			}
		}
		return x;
	}
//==============================DustHuyn==============================//	
	public void quydongCungMau(PhanSo x, PhanSo a) {
		if(x.mau!=a.mau) {
			int mau=x.mau;
			x.mau*=a.mau;
			x.tu *=a.mau;
			a.tu*=mau;
			a.mau*=mau;
		}
	}
//==============================DustHuyn==============================//	
	public static void main(String[] args) {
	}

}
