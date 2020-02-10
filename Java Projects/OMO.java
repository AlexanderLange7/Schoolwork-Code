/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Objects;

/**
 *
 * @author alex.lange
 */
public class OMO {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            int numofguests = sc.nextInt();
            int outlier = 0;
            ArrayList<Integer> guests = new ArrayList<Integer>();
            for (int j = 0; j < numofguests; j++) {
                guests.add(sc.nextInt());
            }
            //sort the guests.
            Collections.sort(guests);
            int flag1 = 0;
            int flag2 = 1;
            int flag3 = 2;
            boolean found = false;
            
            
            while (!found) {
                //IF WE HAVE NOBODY SINGLED OUT
                if (guests.size() != 1) {
                    //DO WE HAVE A PAIR?
                    if (Objects.equals(guests.get(flag1), guests.get(flag2))) {
                        //REMoVE THE PAIR. THEY CAN'T BE THE OUTLIER.
                        guests.remove(flag1);
                        guests.remove(flag1);
                        
                    } 
                    //ONE OF THEM WAS DIFFERENT? IF 1 2 2, IF INDEX1 AND INDEX2 ARE THE SAME OUTPUT 0
                    else if (Objects.equals(guests.get(flag2), guests.get(flag3))) {
                        System.out.println("Case #" + (i + 1) + ": " + guests.get(flag1));
                        found = !found;
                    } 
                  
                } else {
                    System.out.println("Case #" + (i + 1) + ": " + guests.get(flag1));
                    found = !found;
                }
            }

        }

    }
}
