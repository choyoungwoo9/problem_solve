import java.util.*;
import java.io.*;

class Main {
    public static void main(String args[]) throws Exception {
        int a = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        a = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for(int i = 0; i < a; i++){
            st = new StringTokenizer(br.readLine(), " ");
            bw.write(Integer.parseInt(st.nextToken())+Integer.parseInt(st.nextToken())+"\n");
        }
        bw.flush();
    }
}