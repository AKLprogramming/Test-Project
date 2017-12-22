import java.util.*;
import java.lang.Math;

public class q1{
	
	public static void main(String[] args){
		
		System.out.println("Key in an integer: ");
		
		int test = 0;
		int i =0;
		while(i < test){
			i=i+8;
			test = test - i;
		}
		
		
		System.out.println(octal(24));
		
	}
	
	public static string octal(int integer){
		string text = "";
		int result = 0;		
		int power = 0;
		for(int i =0; i<200; i++){
			if(integer < Math.pow(8,i)){
				//note: obtain the smallest difference for 
				//result
				power = i-1;
				result = (integer % Math.pow(8, power));
				break; 		
			}
		}
		
		int result2 = 0;
		int answer = 0;
		
		for(int j =0; j<100; j++){
			if((integer-(Math.pow(8, power)*j)) < 0){
				answer = j-1;				
				result2 = integer-(Math.pow(8, power)*(answer));
			}
			break;	
		}	
		
		return answer.toString() + octal(result2);
	}
	
}
