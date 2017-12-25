import java.util.*;


public class q7{

    public static void main(String[] args){

        System.out.println("");
        int firstNumber, secondNumber;

        Scanner scan = new Scanner(System.in);

        System.out.println("Key in first number: ");
        firstNumber = scan.nextInt();

        System.out.println("Key in second number: ");
        secondNumber = scan.nextInt();

        System.out.println("The sum of "+ firstNumber + " and " + secondNumber + " is " + (firstNumber + secondNumber));
        System.out.println("The product of "+ firstNumber + " and " + secondNumber + " is " + (firstNumber * secondNumber));
        System.out.println("The difference of "+ firstNumber + " and " + secondNumber + " is " + (firstNumber / secondNumber));
        System.out.println("The remainder of "+ firstNumber + " and " + secondNumber + " is " + (firstNumber % secondNumber));
        
        scan.close();

    }



}