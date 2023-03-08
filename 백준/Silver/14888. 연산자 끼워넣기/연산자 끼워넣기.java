import java.util.Scanner;

public class Main {
    static int num_count;
    static int[] num_list;
    static int[] operator_count_list = new int[4];

    static int max = -1000000000;
    static int min = 1000000000;

    static int gogo(int val[], int depth, boolean is_used_num[]){
        if(depth == is_used_num.length){

            int sum = num_list[0];
            for(int i = 0; i < val.length; i = i + 1){

                if(val[i]<=operator_count_list[0]-1 && operator_count_list[0] != 0){
                    sum = sum + num_list[i+1];
                }
                else if(val[i]>operator_count_list[0]-1 && val[i] <= operator_count_list[0]+operator_count_list[1]-1&& operator_count_list[1] != 0){
                    sum = sum - num_list[i+1];
                }
                else if(val[i]>operator_count_list[0]+operator_count_list[1]-1 && val[i] <= operator_count_list[0]+operator_count_list[1]+operator_count_list[2]-1&& operator_count_list[2] != 0){
                    sum = sum * num_list[i+1];
                }
                else{
                    sum = sum / num_list[i+1];
                }
            }
            if(max < sum){
                max = sum;
            }
            if(min > sum){
                min = sum;
            }
            return 0;
        }

        for(int i = 0; i < is_used_num.length; i = i + 1){
            if(is_used_num[i] == false){
                val[depth] = i;
                is_used_num[i] = true;
                gogo(val, depth+1, is_used_num);
                is_used_num[i] = false;
            }
        }

        return 0;
    }

    public static void main(String args[]){
        Scanner SC = new Scanner(System.in);
        num_count = SC.nextInt();
        num_list = new int[num_count];

        for(int i = 0; i < num_count; i = i + 1){
            num_list[i] = SC.nextInt();
        }
        for(int i = 0; i < 4; i = i + 1){
            operator_count_list[i] = SC.nextInt();
        }

        int sum = operator_count_list[0] + operator_count_list[1]
        + operator_count_list[2] + operator_count_list[3];

        boolean[] is_used_num = new boolean[sum];
        int[] val = new int[sum];

        for(int i = 0; i < sum; i = i + 1){
            is_used_num[i] = false;
        }

        gogo(val, 0, is_used_num);

        System.out.println(max);
        System.out.println(min);
    }
}
