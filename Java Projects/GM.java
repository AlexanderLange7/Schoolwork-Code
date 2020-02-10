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
public class GM {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int d = sc.nextInt();
        int p = sc.nextInt();
        //Precinct Data. 0 will be p1a, 1 will be p1b, and so forth.
        int[] precincts = new int[p * 2];

        for (int i = 0; i < d; i++) {
            int currp = sc.nextInt();
            precincts[(currp * 2) - 2] += sc.nextInt();
            precincts[(currp * 2) - 1] += sc.nextInt();

        }
        //Compare precinct data. Output stuff
        int totalwastea = 0;
        int totalwasteb = 0;
        int wastea = 0;
        int wasteb = 0;
        for (int i = 0; i < precincts.length; i++) {
            //get i[0] and i[i]. Must increment i a second time at the end of loop.
            if (precincts[i] > precincts[i + 1]) {
                wastea = ((precincts[i] - (precincts[i] + precincts[i + 1]) / 2) - 1);
                wasteb = precincts[i + 1];
                System.out.println("A " + wastea + " " + wasteb);
                totalwastea += wastea;
                totalwasteb += wasteb;

            }
            if (precincts[i] < precincts[i + 1]) {
                wastea = precincts[i];
                wasteb = (precincts[i + 1] - ((precincts[i + 1] + precincts[i]) / 2) - 1);
                System.out.println("B " + wastea + " " + wasteb);
                totalwastea += wastea;
                totalwasteb += wasteb;
            }
            i++;
        }
        


        //Calculate the efficiency gap and output on it's own line.
        double totalvotes = 0;
        for (int i = 0; i < precincts.length; i++) {
            totalvotes += precincts[i];
        }
     
        if (totalwastea > totalwasteb) {
            System.out.println(((totalwastea - totalwasteb )/ totalvotes));
        } else {
            System.out.println(((totalwasteb - totalwastea )/ totalvotes));

        }
    }
}
