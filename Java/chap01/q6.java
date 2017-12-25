import java.util.*;

public class q6{

    public static void main(String[] args){

        System.out.print("Please key in a value: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int result = 1;
        
        for(int i=1; i <= n; i++){
            result *= i;
        }
        
        System.out.println("Result: " + result);




    }
}