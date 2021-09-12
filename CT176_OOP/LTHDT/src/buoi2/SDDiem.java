package buoi2;

public class SDDiem extends Diem{

	public static void main(String[] args) {
		Diem A = new Diem(3, 4);
		System.out.print("Display point A:");
		A.hienthi();
		
		Diem B = new Diem();
		System.out.println("Nhap toa do diem B:");
		B.nhapDiem();
		System.out.print("Display point B:");
		B.hienthi();
		
		
		Diem C = new Diem(-B.giaTriX(),-B.giaTriY());
		System.out.print("Display point C:");
		C.hienthi();
		
		System.out.print("Distance from B to O: ");
		System.out.printf("%.3f\n",B.khoangCach());
		
		System.out.print("Distance from A to B: ");
		System.out.printf("%.3f",A.khoangCach(B));
	}

}
