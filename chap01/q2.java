import java.util.*;



public class q2{
	
	
	public static void main(String[] args){
		
		try{
		System.out.println("Enter an integer value: ");
		Scanner sc = new Scanner(System.in);
		
		int input = sc.nextInt();
		
		System.out.println("Mod :" + input % 360);
		
		System.out.println("FloorMod: " +Math.floorMod(input, 360));
		}catch(Exception ex){
			System.out.println("Key in again");
		}
		
	}
	
	
	
}