

import java.util.Scanner;

//https://www.acmicpc.net/problem/1780
//종이의 개수
public class Main {
    static int[][] input_num_array;
    static int[] paper_num_index = new int[3];
    static int N;

    public static void main(String args[]) {
        input();
        d_and_q(N, 0, 0);
        print_answer();
    }

    static void input(){
        Scanner SC = new Scanner(System.in);
        N = SC.nextInt();
        input_num_array = new int[N][N];
        for (int i = 0; i < N; i = i + 1) {
            for (int j = 0; j < N; j = j + 1) {
                input_num_array[i][j] = SC.nextInt();
            }
        }
    }

    static void d_and_q(int numbers_of_rows, int row, int column){
        if(check(numbers_of_rows, row, column) == true){
            int base_num = input_num_array[row][column];
            if(base_num == -1){
                paper_num_index[0] = paper_num_index[0]+1;
            }
            else if(base_num == 0){
                paper_num_index[1] = paper_num_index[1]+1;
            }
            else if(base_num == 1){
                paper_num_index[2] = paper_num_index[2]+1;
            }
        }
        else{
            for(int i = 0; i < 9; i = i + 1){
                //divide
                d_and_q(numbers_of_rows/3
                        , row+(i%3)*(numbers_of_rows/3)
                        , column+(i/3)*(numbers_of_rows/3)
                );
            }
        }
    }

    static boolean check(int numbers_of_rows, int row, int column){
        int check_num = input_num_array[row][column];
        for(int i = 0; i < numbers_of_rows; i = i + 1){
            for(int j = 0; j < numbers_of_rows; j = j + 1){
                if(check_num != input_num_array[row+i][column+j]){
                    return false;
                }
            }
        }
        return true;
    }

    static void print_answer(){
        System.out.println(paper_num_index[0]);
        System.out.println(paper_num_index[1]);
        System.out.println(paper_num_index[2]);
    }
}
