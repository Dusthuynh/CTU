package buoi2;

import java.util.Scanner;

public class SDSinhVien {
	private int count=0;			//so luong sinh vien
	
	
	public void menu(SinhVien SV[]) {
		SinhVien x =new SinhVien();
		Scanner sc = new Scanner(System.in);
		System.out.print("*Nhap vao lua chon cua ban:");
		int choose = sc.nextInt();
		switch(choose) {
		  case 0:
			  	System.out.println("--EXIT--");
			  	break;
		  case 1:
			  	System.out.println("--ADD SINH VIEN--");
			  	add(SV);
			  	System.out.println("//////////////////////////////");
			  	menu(SV);
			  	break;
		  case 2:
			  	System.out.println("--EDIT STUDENT BY ID--");
			  	x.edit(SV,count);
			  	System.out.println("//////////////////////////////");
			  	menu(SV);
			  	break;
		  case 3:
			  	System.out.println("--DELETESTUDENT BY ID--");
			  	x.delete(SV,count);
			  	count--;
			  	System.out.println("//////////////////////////////");
			  	menu(SV);
			    break;
		  case 4:
			  	System.out.println("--SORT STUDENT BY GPA--");
			  	x.sortbyGPA(SV,count);
			  	System.out.println("//////////////////////////////");
			  	menu(SV);
			    break;
		  case 5:
			  	System.out.println("--SORT STUDENT BY NAME--");
			  	x.sortbyName(SV,count);
			  	System.out.println("//////////////////////////////");
			  	menu(SV);
			    break;
		  case 6:
			  	System.out.println("--SHOW STUDENT BOARD--");
			  	x.ouputForm();
				for(int i=0; i<count; i++)
					SV[i].display();
				System.out.println("//////////////////////////////");
				menu(SV);
			    break;
		  default:System.out.print("!!!Khong co lua chon nay, vui long nhap lai:");
		    	menu(SV);
		}
	}
	
	public void add(SinhVien SV[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap so luong sinh vien can them: ");
		int x = sc.nextInt();
		for(int i=count; i<count+x; i++) {
			SV[i] = new SinhVien();
			System.out.println("Sinh vien thu "+(i+1)+": ");
			SV[i].input();
		}
		count +=x;
	}
	
	public static void main(String[] args) {
		SDSinhVien SD = new SDSinhVien();
		SinhVien SV[] = new SinhVien[100];
		String line = new String(new char[77]).replace('\0', '-');
		System.out.println(line);
		System.out.println("|1.Add| |2.Edit| |3.Delete| |4.Sort by id| |5.Sort by name| |6.Show| |0.Exit|");
		System.out.println(line);
		SD.menu(SV);
	}	

}
