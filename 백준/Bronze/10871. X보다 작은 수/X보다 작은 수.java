import java.io.*;
import java.util.Scanner;

class Main {
    public static void main(String args[]) throws Exception {
        int N ,x =0;
        Scanner SC = new Scanner(System.in);
        N = SC.nextInt();
        x = SC.nextInt();

        int[] NN = new int[N];

        int a = 0;
        for(int i = 0; i < N; i++){
            int y = SC.nextInt();
            if(y < x){
                NN[a] = y;
                a = a + 1;
            }
        }
        for(int i = 0; i < a; i++){
            System.out.print(NN[i]);
            System.out.print(" ");
        }
    }
}