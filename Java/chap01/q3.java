import java.util.*;
import java.lang.Math;

public class q3{

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.print("Key in first integer: ");
		
		int num1 = sc.nextInt();
		
		System.out.print("Key in second integer: ");
		
		int num2 = sc.nextInt();
		
		System.out.print("Key in third integer: ");
		int num3 = sc.nextInt();
		
		
		System.out.println("The largest number between "+ num1 + ", " + num2 + ", and "+ num3+ " is " + Math.max(Math.max(num1,num2),Math.max(num2,num3)));
		

	}



}
