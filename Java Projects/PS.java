import java.util.Scanner;
public class PS {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        int p = 1;
        int days = 0;
        while(input > p ){
        p*=2;
        days++;
        }
        days++;
        System.out.println(days);
}
}
