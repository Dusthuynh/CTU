package buoi1;

import java.util.Scanner;

public class Bai3 {

	public static void main(String[] args) {
		double sum=0, n, max = Double.MIN_VALUE;
		
		for(String e : args) {
			try{n = Double.parseDouble(e);}
			catch(NumberFormatException ex) { n=0; }
			
			sum +=n;
			if(max < n) max =n;
		}
		System.out.println("Sum ="+sum+", Max="+max);
		
	}
	
}
