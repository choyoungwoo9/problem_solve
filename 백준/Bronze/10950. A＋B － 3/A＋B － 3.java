import java.util.Scanner;

public class Main {
    public static void main(String[] args){
            int A;
            Scanner sc = new Scanner(System.in);
            A = sc.nextInt();
            for(int i = 0; i < A; i++){
                int B = sc.nextInt();
                int C = sc.nextInt();
                System.out.print(B+C);
                System.out.println();
            }
    }
}
