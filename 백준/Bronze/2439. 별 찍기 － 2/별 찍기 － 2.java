import java.util.Scanner;

public class Main {
    public static void main(String[] args){
            int A;
            Scanner sc = new Scanner(System.in);
            A = sc.nextInt();
            for(int j = 1; j <= A; j++){
                for(int k = 1; k <= A-j; k++){
                    System.out.print(" ");
                }
                for(int i = 1; i <= j; i++){
                    System.out.print("*");
                }
                System.out.println("");
            }
    }
}
