import java.util.Scanner;

public class Main {
    public static void main(String[] args){
            int A;
            Scanner sc = new Scanner(System.in);
            A = sc.nextInt();
            if(A%4 == 0 && (A%100 != 0 || A%400 == 0)){
                System.out.print("1");
            }
            else
                System.out.print("0");
    }
}
