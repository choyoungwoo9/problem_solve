import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();//유저가 입력한 값

        int all = 1; //개수 초과했는지 판별
        int line = 2; //몇번째 줄인지 판별

        while(true){
            if(X <= all){ //만약에 8이면 line => 4 line에서 num => 2   //   2/3가 나와야함
                //만약에 7이면 line => 4 line에서 num => 1   //   1/4가 나와야함
                //System.out.println(line-1);(실제 line)
                //System.out.println(X-(all-(line-1)));(실제 line에서의 번호)
                //System.out.println((line-1)-(X-(all-(line-1))-1));//분모
                //System.out.println(X-(all-(line-1))); //분자
                if((line-1)%2 == 0){ //짝수 line에서 계산법
                    System.out.print((X-(all-(line-1)))+"/"+((line-1)-(X-(all-(line-1))-1)));
                    break;
                }
                else{ //홀수line에서 계산법
                    System.out.print(((line-1)-(X-(all-(line-1))-1))+"/"+(X-(all-(line-1))));
                    break;
                }
            }
            else{ //조건에 부합하지않았을때
                all = line + all; //개수line으로 판별
                line = line + 1; //line다음으로 넘김
            }
        }

    }
}
