package buoi3;

import java.util.Scanner;

public class SDGach {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap so loai gach lot nen: ");
		int n = sc.nextInt();
		Gach[] DS = new Gach[n];
		for(int i=0;i<n;i++) {
			DS[i] = new Gach();
			System.out.println("*Nhap thong tin gach thu "+(i+1)+":");
			DS[i].nhap();
		}
		
		System.out.println("/*******************/");
		for(int i=0;i<n;i++) {
			System.out.println("*Thong tin gach thu "+(i+1)+":");
			DS[i].in();
		}
		
		long giaMin = Long.MAX_VALUE;
		int check = -1;
		for(int i=0;i<n;i++) {
			if(DS[i].layGia()<giaMin) {
				giaMin=DS[i].layGia();
				check=i;
			}
		}
		System.out.println("Loai gach co chi phi thap nhat:");
		DS[check].in();
		
		
		System.out.println("/*******************/");
		System.out.println("*Chi phi mua gach voi dien tich 20x5(m):");
		for(int i=0;i<n;i++) {
			long chiPhi = DS[i].soLuongHop(20, 5) * DS[i].layGia();
			System.out.println("Chi phi mua loai gach thu "+(i+1)+":"+chiPhi);
		}
	}
}
