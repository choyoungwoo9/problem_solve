import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner SC = new Scanner(System.in);
        int N = SC.nextInt();
        int check = 1;
        int roundnum = 1;//몇번째 원인지
        while(true){
            if(N <= check){
                System.out.print(roundnum);
                break;
            }
            else{
                check = check + roundnum*6;
                roundnum = roundnum + 1;
            }

        }
    }
}
