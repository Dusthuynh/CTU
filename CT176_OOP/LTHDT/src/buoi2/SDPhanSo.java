package buoi2;

import java.util.Scanner;

public class SDPhanSo {
	//+Luu y, khi xai ham x.cong(y) se lam thay doi gia tri cua y, 
	// do phai quy dong; nhung khong lam thay doi gia tri cua x,
	// do da tao doi tuong khac. Co the fix lai truong hop nay.
	//+Ham display chi hien thi nhung chua co rut gon, co the fix.
	public static void main(String[] args) {
		PhanSo a = new PhanSo(3,7);
		PhanSo b = new PhanSo(4,9);
		a.display();
		b.display();
//==============================DustHuyn==============================//
		PhanSo x = new PhanSo();
		PhanSo y = new PhanSo();
		System.out.println("-Phan so x");
		x.input();
		System.out.println("-Phan so y");
		y.input();
//==============================DustHuyn==============================//
		System.out.print("Phan So nghich dao cua x: ");
		PhanSo x1 = new PhanSo();
		x1 = x.giatriNghichDao();
		x1.display();
//==============================DustHuyn==============================//
		System.out.print("x + y = ");
		(x.cong(y)).display();
		x.display();
		y.display();
//==============================DustHuyn==============================//
		System.out.print("Nhap so phan so: ");
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		PhanSo[] arr = new PhanSo[n+1];
		for(int i=1;i<=n;i++) {
			arr[i] = new PhanSo();
			System.out.println("Phan so "+i+":");
			arr[i].input(); 
			System.out.println("/////////");
		}
		System.out.println("Day phan so da nhap:");
		for(int i=1;i<=n;i++)
			arr[i].display();
//==============================DustHuyn==============================//
		System.out.print("Sum:");
		PhanSo Sum = new PhanSo(0,1);
		for(int j=1;j<=n;j++) {
			Sum = arr[j].cong(Sum);
		}
		Sum.display();
		/*for(int j=1;j<=n;j++)
			arr[j].display();*/
//==============================DustHuyn==============================//
		System.out.print("Max:");
		float max=Float.MIN_VALUE;
		int check=0;
		for(int k=1;k<=n;k++) {
			if(max < arr[k].giatriThuc()) {
				max = arr[k].giatriThuc();
				check = k;
			}
		}
		arr[check].display();
//==============================DustHuyn==============================//
		System.out.println("Sort:");
		PhanSo temp = new PhanSo();
		for(int i=1;i<n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(arr[i].giatriThuc() > arr[j].giatriThuc()) {
					temp   = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		for(int i=1;i<=n;i++) {
			arr[i].display();
		}
		
	}
}
