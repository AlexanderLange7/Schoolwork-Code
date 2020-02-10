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
public class DD {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for (int i = 0; i < tc; i++) {
            
            String a = sc.next();
            String b = sc.next();
            char[] ach = a.toCharArray();
            char[] bch = b.toCharArray();
            String c = "";
            
            System.out.println(a);
            System.out.println(b);
            
            for (int j = 0; j < ach.length; j++) {
                if (ach[j] == bch[j]) {
                    c += '.';
                } else {
                    c += '*';
                }

            }
            
            System.out.println(c);
            System.out.println("");
        }

    }
}
