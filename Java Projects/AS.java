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
public class AS {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String line = s.nextLine();

        double ll = line.length();
        double lc = 0, ws = 0, uc = 0, sy = 0;

        //whitespace
        //lowercase
        //uppercase
        //symbol
        for (int i = 0; i < ll; i++) {
            //lowercase
            if (line.charAt(i) >= 97 && line.charAt(i) <= 122) {
                lc++;
            } //uppercase
            else if (line.charAt(i) >= 65 && line.charAt(i) <= 90) {
                uc++;
            }//whitespace
            else if (line.charAt(i) == '_') {
                ws++;
            } else {
                sy++;
            }

        }
        System.out.println(ws/ll);
        System.out.println(lc/ll);
        System.out.println(uc/ll);
        System.out.println(sy/ll);

    }
}
