package A_xulyso;
//Viết chương trình tính giai thừa của n
import java.util.Scanner;

public class Bai2 {

	public long giaithua(int n) {
		long x=1;
		for(int i=n;i>0;i--)
			x*=i;
		return x;
	}
	
	public static void main(String[] args) {
		int n;
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		
		Bai2 t = new Bai2();
		long res = t.giaithua(n);
		
		System.out.println(n+"! = "+res);
	}

}
