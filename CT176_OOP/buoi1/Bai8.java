package buoi1;

import java.util.Scanner;

public class Bai8 {
	int a[];
	int n;
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap so phan tu trong day: "); n=sc.nextInt();
		a = new int[n]; 
		
		for(int i=0;i<n;i++) {
			System.out.print("Nhap so thu "+(i+1)+" :");
			a[i]=sc.nextInt();
		}
	}
	public void in() {
		for(int i=0;i<n;i++) {
			System.out.print(a[i]+" ");
		}
	}
	public void sort() {
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++) {
				if (a[i]>a[j]) {
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
	}
	public int dem(int x) {
		int res=0;
		for(int e :a) {
			if(e==x) res++;
		}
		return res;
	}
	public static void main(String[] args) {
		Bai8 t = new Bai8();
		t.nhap();
		t.in();
		Scanner sc = new Scanner(System.in);
		int x;
		System.out.print("\nNhap so x can dem: "); x=sc.nextInt();
		System.out.println("So luong so "+x+" trong DS la: "+(t.dem(x)));
		
		System.out.println("Danh sach sau khi sap xep:");
		t.sort();
		t.in();
	}
}
