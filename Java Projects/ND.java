/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
import java.util.HashMap;

/**
 *
 * @author alex.lange
 */
public class ND {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String dupe = "yes";
        String[] words = line.split(" ");
        HashMap words2 = new HashMap();
        for (String a : words) {
            if (words2.containsKey(a)) {
                dupe = "no";
            } else {
                words2.put(a, 1);
            }
        }

        System.out.println(dupe);

    }
}
