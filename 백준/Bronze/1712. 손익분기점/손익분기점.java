import java.util.Scanner;

public class Main {
    public static void main(String args[]) throws Exception {
        Scanner SC = new Scanner(System.in);
        String Cost = SC.nextLine();
        String[] C = new String[3];
        C = Cost.split(" ");
        int FixedCost = Integer.parseInt(C[0]);
        int ManufacturingCost = Integer.parseInt(C[1]);
        int SalesCost = Integer.parseInt(C[2]);
        int i = 0;

        while(1<2){
            if(ManufacturingCost >= SalesCost){
                System.out.print("-1");
                return;
            }

            if((FixedCost < i*(SalesCost-ManufacturingCost) )) {
                System.out.print(i);
                return;
            }

            i = i + 1;
        }
    }
}