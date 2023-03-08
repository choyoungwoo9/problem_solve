import java.util.Scanner;

public class Main {
    public static void main(String[] args){
            int A;
            Scanner sc = new Scanner(System.in);
            A = sc.nextInt();
            for(int i = 0; i<9; i++){
                System.out.println(A + " * " + (i+1) + " = " + A*(i+1));
            }
    }
}
