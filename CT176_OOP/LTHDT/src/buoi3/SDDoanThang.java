package buoi3;

import buoi2.Diem;

public class SDDoanThang {

	public static void main(String[] args) {
		Diem A = new Diem(2,5);
		Diem B = new Diem(20,35);
		DoanThang AB = new DoanThang(A,B);
		System.out.println("Toa do AB: "+AB);
		AB.tinhTien(5, 3);
		System.out.println("Toa do AB sau khi tinh tien: "+ AB);
		
		DoanThang CD = new DoanThang();
		CD.nhap();
		System.out.println("Toa do CD: "+CD);
		System.out.format("Do dai doan thang CD = %.2f",CD.doDai());
	}

}
