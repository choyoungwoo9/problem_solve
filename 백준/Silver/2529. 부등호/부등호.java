import java.util.Scanner;

public class Main {

    static int sign_count;
    static String sign;

    static String min = "0";
    static String max = "0";

    static int check(int[] val, int depth, boolean[] used_num){

        if(depth == sign_count+1){
            String f_value = "";
            for(int i = 0; i < val.length; i = i +1){
                f_value = f_value + val[i];
            }
            if(min.equals("0")){
                min = f_value;
            }
            max = f_value;
            return 0;
        }



        if(depth == 0 || sign.charAt(2*(depth-1)) == '<'){
            for(int i = 0; i < 10; i = i + 1){
                val[depth] = i;
                if(depth == 0){
                    val[0] = i;
                    used_num[i] = true;
                    check(val, 1, used_num);
                    used_num[i] = false;
                }
                else if(val[depth-1] < val[depth] && used_num[i] == false){
                    val[depth] = i;
                    used_num[i] = true;
                    check(val, depth+1, used_num);
                    used_num[i] = false;
                }
            }
        }

        else if(sign.charAt(2*(depth-1)) == '>'){
            for(int i = 0; i < 10; i = i + 1){
                val[depth] = i;
                if(val[depth-1] > val[depth] && used_num[i] == false){
                    val[depth] = i;
                    used_num[i] = true;
                    check(val, depth+1, used_num);
                    used_num[i] = false;
                }
            }
        }
        return 0;
    }

    public static void main(String args[]){
        Scanner SC = new Scanner(System.in);
        sign_count = SC.nextInt();
        SC.nextLine();
        sign = SC.nextLine();

        int[] val = new int[sign_count+1];
        boolean[] used_num = {false, false, false, false, false, false, false, false, false, false};
        check(val, 0, used_num);
        System.out.println(max);
        System.out.println(min);

    }
}
