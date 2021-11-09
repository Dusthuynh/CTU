package buoi4;

public class SDDiemMau {

	public static void main(String[] args) {
		DiemMau A= new DiemMau(5,10,"Trang");
		System.out.print("*Thong tin diem A: ");
		A.in();
		
		DiemMau B= new DiemMau();
		System.out.println("\n*Nhap thong tin diem B");
		B.nhap();
		System.out.print("\n*Thong tin diem B: ");
		B.in();
		B.tinhTien(10, 8);
		System.out.print("B sau khi tinh tien: "+B);
		B.GanMau("Vang");
		System.out.println("B sau khi gan mau: "+B);
	}

}
