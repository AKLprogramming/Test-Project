import java.util.*;
import java.lang.Math;

public class q1 {

	public static void main(String[] args) {
		System.out.println("Key in an integer: ");

		Scanner sc = new Scanner(System.in);
		Math.
		int test = sc.nextInt();
		// binary
		// octal
		System.out.println("Binary: " + Integer.toBinaryString(test));
		System.out.println("Octal: " + Integer.toOctalString(test));
	}

	public static double power(double compare, double num) {
		if (compare < Math.pow(8, num)) {
			return num - 1;
		} else {
			return power(compare, (num + 1));
		}
	}

	public static String octal(double integer) {
		
		String text = "";
		double result = 0;
		double power = power(integer, 0.0);
		double answer = 0;
		double ans = 0.0;

		while (true) {
			
			for (int j = 0; j < 100; j++) {
				if ((integer - (Math.pow(8, power) * j)) < 0) {
					answer = j - 1;
					result = integer - (Math.pow(8, power) * (answer));
					break;
				}
			}
			
			ans = (integer % result);
			text = Double.toString(answer);
			
			if (integer < Math.pow(8, power)) {
				
			} else {
				
			}
			break;
		}
		
		return text;
		/*
		 * if (integer < Math.pow(8, power)) return Double.toString(power); else
		 * return text + octal(ans);
		 */
		
	}
}