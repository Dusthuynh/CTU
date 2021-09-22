package buoi2;

import java.util.Scanner;

public class SDDate {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Date date = new Date();
		date.nhap();
		System.out.print("Ngay da nhap: ");
		date.in();
		System.out.print("Ngay hom sau: ");
		date.ngayHomsau().in();;
		
		System.out.print("Nhap so ngay can cong: ");
		int n = sc.nextInt();
		System.out.print("Thoi gian sau "+n+" ngay:");
		date.congNgay(n).in();;
	}

}
