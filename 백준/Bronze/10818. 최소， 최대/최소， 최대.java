import java.util.Scanner;

public class Main {
    public static void main(String args[]) throws Exception {
        Scanner SC = new Scanner(System.in);
        int N = SC.nextInt();

        int[] Box = new int[N];

        for(int i = 0; i < N; i++){
            Box[i] = SC.nextInt();
        }

        for(int i = 0; i < N; i++){
            if(Box[0] > Box[i]){
                int temp = Box[0];
                Box[0] = Box[i];
                Box[i] = temp;
            }
            if(Box[N-1] < Box[i]){
                int temp = Box[N-1];
                Box[N-1] = Box[i];
                Box[i] = temp;
            }
        }
        System.out.print(Box[0] + " " + Box[N-1]);

    }
}