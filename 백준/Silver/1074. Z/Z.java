

import java.util.Arrays;
import java.util.Scanner;

//https://www.acmicpc.net/problem/1074
//Z
public class Main {
    static int N, r, c;
    static int[] memorize_quadrant = new int[16];
    static int last_value = 0;

    public static void main(String args[]) {
        Scanner SC = new Scanner(System.in);
        N = SC.nextInt();
        r = SC.nextInt();
        c = SC.nextInt();
        //logic start
        divide_and_conquer(N, r, c);
        System.out.println(last_value);
    }

    static void divide_and_conquer(int level, int row, int column) {
        if (level == 1) {
            memorize_quadrant[level] = check(level, row, column);
            for(int i = N; i >= 1; i = i -1){
                last_value = last_value + (int)Math.pow(4, i-1)*(memorize_quadrant[i]-1);
            }
        } else {
            int quadrant = check(level, row, column);
            memorize_quadrant[level] = quadrant;
            if(quadrant == 1){
                row = row;
                column = column;
            }
            else if(quadrant == 2){
                column = column-(int)Math.pow(2, level-1);
            }
            else if(quadrant == 3){
                row = row-(int)Math.pow(2, level-1);
            }
            else if(quadrant == 4){
                row = row-(int)Math.pow(2, level-1);
                column = column-(int)Math.pow(2, level-1);
            }
            divide_and_conquer(level - 1, row, column);
        }
    }

    static int check(int level, int row, int column) {
        if (row < (int) (Math.pow(2, level) / 2)) {
            if (column < (int) (Math.pow(2, level) / 2)) {
                return 1;
            } else {
                return 2;
            }
        } else {
            if (column < (int) (Math.pow(2, level) / 2)) {
                return 3;
            } else {
                return 4;
            }
        }
    }
}
