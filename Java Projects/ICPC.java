/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
import java.util.ArrayList;

/**
 *
 * @author alex.lange
 */
public class ICPC {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        ArrayList<String> winners = new ArrayList<>();
        int counter = 0;

        for (int i = 0; i < cases; i++) {
            String university = sc.next();
            String teamname = sc.next();
            if (!winners.contains(university) && counter != 12) {
                System.out.println(university + " " + teamname);
                winners.add(university);
                counter++;
            }
        }

    }

}
