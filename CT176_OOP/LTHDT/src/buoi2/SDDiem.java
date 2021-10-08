package buoi2;

public class SDDiem{

	public static void main(String[] args) {
		Diem A = new Diem(3, 4);
		System.out.print("Toa do diem A:");
		A.in();
		
		Diem B = new Diem();
		System.out.println("Nhap toa do diem B:");
		B.nhap();
		System.out.print("Toa do diem B:");
		B.in();
		
		
		Diem C = new Diem(-B.layX(),-B.layY());
		System.out.print("Toa do diem C:");
		C.in();
		
		System.out.print("Khoang cach tu B den O: ");
		System.out.format("%.3f\n",B.khoangCach());
		
		System.out.print("Khoang cach tu A den B: ");
		System.out.format("%.3f",A.khoangCach(B));
	}

}
