/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;

/**
 *
 * @author alex.lange
 */
public class TF {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int lines = sc.nextInt();
        double totalarea = 0;
        int ti1 = sc.nextInt();
        double vi1 = sc.nextDouble();
        for (int i = 0; i < lines-1; i++) {
            int ti2 = sc.nextInt();
            double vi2 = sc.nextDouble();

        totalarea+=(ti2-ti1)*((vi2+vi1)/2);
            ti1=ti2;
            vi1=vi2;
        }
        System.out.println(totalarea/1000);

    }
}
