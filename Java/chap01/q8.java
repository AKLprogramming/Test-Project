import java.util.*;


public class q8{

    public static void main(String[] args){
        String input;
        Scanner scan = new Scanner(System.in);

        System.out.print("Type any word: ");
        input = scan.next();

        for(int j=0; j <input.length(); j++){
            for(int i=0; i < input.length(); i++){
                System.out.println(input.substring(i,input.length()));
            }
            
        }
        
        


        
        
        scan.close();

    }


}