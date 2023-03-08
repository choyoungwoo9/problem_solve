import java.util.Scanner;

public class Main {
    public static void main(String[] args){
            int A, B;
            B = 0;
            Scanner sc = new Scanner(System.in);
            A = sc.nextInt();
            for(int i = 0; i < A; i++){
                B = B+A-i;
            }
            System.out.print(B);
    }
}
