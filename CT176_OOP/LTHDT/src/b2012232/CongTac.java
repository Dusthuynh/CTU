package b2012232;

import java.util.Scanner;
//STT: 49; MSSV: B2012232; HoTen: Huynh Minh Nghia; Nhom: 6; So de: 1.

public class CongTac {
	private NhanVien nv;
	private String dvi;
	private int tnien;
	private boolean bche;
	
	public CongTac() {
		nv = new NhanVien();
		dvi = new String();
		tnien = 0;
		bche = false;
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		nv.nhap();
		System.out.println("Nhap don vi cong tac:");
		dvi = sc.nextLine();
		System.out.println("Nhap tham nien cong tac: ");
		tnien = sc.nextInt();
		System.out.println("Co bien che(true) hay khong bien che(false):");
		bche = sc.nextBoolean();
	}
	public void hthi() {
		nv.hthi();
		System.out.print("Don vi cong tac: " +dvi+", tham nien: "+tnien);
		if(bche) {
			System.out.println(", co tham nien.");
		}else System.out.println(", khong co tham nien.");
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m;
		System.out.println("Nhap so thanh vien cong tac:");
		m= sc.nextInt();
		CongTac DS[] = new CongTac[m];
		for(int i=0;i<m;i++) {
			DS[i] = new CongTac();
			System.out.println("Thanh vien"+(i+1)+":");
			DS[i].nhap();
		}
		System.out.println("\n **Thong tin cac thanh vien cong tac:");
		for(int i=0;i<m;i++) {
			DS[i].hthi();
		}
		
		for(int i=0;i<m;i++) {
			String temp = DS[i].nv.layMSNV();
			if(temp.equals("12346"))
				System.out.println("\n **Ho ten nhan vien MS 12346: "+DS[i].nv.layHoTen());
				break;
		}
		
		System.out.println("\n **So nhan vien trong bien che theo chuc vu:");
		for(int i=0;i<m;i++) {
			if(DS[i].bche) {
				DS[i].hthi();
			}
		}
	}

}
