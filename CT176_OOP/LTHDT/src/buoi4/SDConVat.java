package buoi4;

import java.util.Scanner;

public class SDConVat {

	public static void main(String[] args) {
		ConVat cv;
		
		cv = new ConBo();
		cv.nhap();
		cv.in();
		cv.keu();
		
		cv = new ConHeo();
		cv.nhap();
		cv.in();
		cv.keu();
		
		cv.layCount();
		
		
//		int n;
//		Scanner sc =new Scanner(System.in);
//		System.out.print("Nhap so luong con vat: ");
//		n = sc.nextInt();
//		ConVat CV[] = new ConVat[n];
//		int check = -1;
//		for(int i=0;i<n;i++) {
//			System.out.println("*Nhap con vat "+(i+1)+":");
//			System.out.print("     Ban muon nhap Heo(0) hay Bo(1) hay De(2) hay Ga(3): ");
//			check = sc.nextInt();
//			if(check == 0) CV[i]=new ConHeo();
//			else if(check == 1) CV[i]=new ConBo();
//			else if(check == 2) CV[i]=new ConDe();
//			else if(check == 3) CV[i]=new ConGa();
//			CV[i].nhap();
//		}
//		
//		System.out.println("Tieng keu cua cac con vat: ");
//		for(int i=0;i<n;i++) {
//			System.out.println("Con thu "+(i+1)+" keu: "+CV[i].tiengKeu());
//		}

		

	}

}
