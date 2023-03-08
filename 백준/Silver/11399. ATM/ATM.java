import java.util.Arrays;
import java.util.Scanner;

//https://www.acmicpc.net/problem/11399
public class Main {
    static int N;
    static int user_input[];
    static public void main(String args[]){
        Scanner SC = new Scanner(System.in);
        N = SC.nextInt();
        user_input = new int[N];
        for(int i = 0; i < N; i = i + 1){
            user_input[i] = SC.nextInt();
        }

        Arrays.sort(user_input);
        int sum = 0;
        for(int i = 0; i < N; i = i + 1){
            for(int j = 0; j <= i; j = j + 1){
                sum = sum + user_input[j];
            }
        }
        System.out.println(sum);
    }
}
