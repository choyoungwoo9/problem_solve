import java.util.Scanner;

//https://www.acmicpc.net/problem/11047
public class Main {

    static int N;
    static int K;
    static int[] coin_value; //화폐단위
    static int[] used_coin_value_count; //각 인덱스별 사용한 코인 갯수
    public static void main(String args[]){

        //input
        Scanner SC = new Scanner(System.in);
        N = SC.nextInt();
        K = SC.nextInt();
        coin_value = new int[N];
        used_coin_value_count = new int[N];
        for(int i = 0; i < N; i = i + 1){
            coin_value[i] = SC.nextInt();
        }

        //logic start
        int change = K;
        for(int i = 0; i < N; i = i + 1){
            used_coin_value_count[N-i-1] = change/coin_value[N-i-1];
            change = change - used_coin_value_count[N-i-1]*coin_value[N-i-1];
        }

        int sum = 0;
        for(int i = 0; i < N; i = i + 1){
            sum = sum + used_coin_value_count[i];
        }
        System.out.println(sum);

    }
}
