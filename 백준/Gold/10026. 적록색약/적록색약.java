//https://www.acmicpc.net/problem/10026

import java.util.Scanner;

public class Main {
    static int N;
    static String[] u_map;
    static boolean[][] is_used_u_map;

    static int count_1 = 0; //지역 갯수 구분
    static int count_2 = 0; //적록 색맹 지역 구분

    static void bfs(int i, int j){
        is_used_u_map[i][j] = true;

        if(i == 0){

            if(j == 0){
                if(u_map[i].charAt(j) == u_map[i].charAt(j+1)&& is_used_u_map[i][j+1] == false){ //우
                    bfs(i, j+1);
                }
                if(u_map[i].charAt(j) == u_map[i+1].charAt(j) && is_used_u_map[i+1][j] == false){ //하
                    bfs(i+1, j);
                }
            }

            else if(j == N-1){
                if(u_map[i].charAt(j) == u_map[i+1].charAt(j) && is_used_u_map[i+1][j] == false){ //하
                    bfs(i+1, j);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j-1) && is_used_u_map[i][j-1] == false){ //좌
                    bfs(i, j-1);
                }
            }

            else{
                if(u_map[i].charAt(j) == u_map[i+1].charAt(j) && is_used_u_map[i+1][j] == false){ //하
                    bfs(i+1, j);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j-1) && is_used_u_map[i][j-1] == false){ //좌
                    bfs(i, j-1);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j+1)&& is_used_u_map[i][j+1] == false){ //우
                    bfs(i, j+1);
                }
            }

        }

        else if(i == N-1){
            if(j == 0){
                if(u_map[i].charAt(j) == u_map[i-1].charAt(j) && is_used_u_map[i-1][j] == false){ //상
                    bfs(i-1, j);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j+1)&& is_used_u_map[i][j+1] == false){ //우
                    bfs(i, j+1);
                }
            }
            else if(j == N-1){
                if(u_map[i].charAt(j) == u_map[i-1].charAt(j) && is_used_u_map[i-1][j] == false){ //상
                    bfs(i-1, j);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j-1) && is_used_u_map[i][j-1] == false){ //좌
                    bfs(i, j-1);
                }
            }
            else{
                if(u_map[i].charAt(j) == u_map[i-1].charAt(j) && is_used_u_map[i-1][j] == false){ //상
                    bfs(i-1, j);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j-1) && is_used_u_map[i][j-1] == false){ //좌
                    bfs(i, j-1);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j+1)&& is_used_u_map[i][j+1] == false){ //우
                    bfs(i, j+1);
                }
            }
        }
        else{
            if(j == 0){
                if(u_map[i].charAt(j) == u_map[i-1].charAt(j) && is_used_u_map[i-1][j] == false){ //상
                    bfs(i-1, j);
                }
                if(u_map[i].charAt(j) == u_map[i+1].charAt(j) && is_used_u_map[i+1][j] == false){ //하
                    bfs(i+1, j);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j+1)&& is_used_u_map[i][j+1] == false){ //우
                    bfs(i, j+1);
                }
            }
            else if(j == N-1){
                if(u_map[i].charAt(j) == u_map[i-1].charAt(j) && is_used_u_map[i-1][j] == false){ //상
                    bfs(i-1, j);
                }
                if(u_map[i].charAt(j) == u_map[i+1].charAt(j) && is_used_u_map[i+1][j] == false){ //하
                    bfs(i+1, j);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j-1) && is_used_u_map[i][j-1] == false){ //좌
                    bfs(i, j-1);
                }
            }
            else{
                if(u_map[i].charAt(j) == u_map[i-1].charAt(j) && is_used_u_map[i-1][j] == false){ //상
                    bfs(i-1, j);
                }
                if(u_map[i].charAt(j) == u_map[i+1].charAt(j) && is_used_u_map[i+1][j] == false){ //하
                    bfs(i+1, j);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j-1) && is_used_u_map[i][j-1] == false){ //좌
                    bfs(i, j-1);
                }
                if(u_map[i].charAt(j) == u_map[i].charAt(j+1)&& is_used_u_map[i][j+1] == false){ //우
                    bfs(i, j+1);
                }
            }
        }
    }

    static boolean check_1(){
        for(int i = 0; i < N; i = i + 1){
            for(int j = 0; j < N; j = j + 1){
                if(is_used_u_map[i][j] == true){ //이미 지나간 지역
                    //그냥 지나감
                }
                else{ //처음 보는 지역
                    count_1 = count_1 + 1;
                    bfs(i, j);
                }
            }
        }
        return true;
    }

    static boolean check_2(){
        for(int i = 0; i < N; i = i + 1){
            for(int j = 0; j < N; j = j + 1){
                if(is_used_u_map[i][j] == true){ //이미 지나간 지역
                    //그냥 지나감
                }
                else{ //처음 보는 지역
                    count_2 = count_2 + 1;
                    bfs(i, j);
                }
            }
        }
        return true;
    }

    static public void main(String args[]){
        Scanner SC = new Scanner(System.in);
        N = SC.nextInt();
        u_map = new String[N];
        is_used_u_map = new boolean[N][N]; //default == false


        for(int i = 0; i < N; i = i + 1){
            u_map[i] = SC.next();
        }
        check_1();
        System.out.print(count_1 + " ");

        for(int i = 0; i < N; i = i + 1){
            u_map[i] = u_map[i].replaceAll("R", "G");
        }
        for(int i = 0; i < N; i = i + 1){
            for(int j = 0; j < N; j = j + 1){
                is_used_u_map[i][j] = false;
            }
        }
        check_2();
        System.out.println(count_2);
    }
}
