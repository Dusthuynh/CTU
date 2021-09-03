package TuHoc;

import java.util.Scanner;

public class tim_n_so_fibonacci {

	public int infibo(int x) {
		if(x==0 || x==1) return x;
		else return infibo(x-1)+infibo(x-2);
	}
	
	public static void main(String[] args) {
		int n;
		Scanner sc = new Scanner(System.in);
		System.out.println("n=");
		n=sc.nextInt();
		
		tim_n_so_fibonacci t = new tim_n_so_fibonacci();
		for(int i=1;i<=n;i++) {
			System.out.print(t.infibo(i)+" ");
		}
		
	}

}
