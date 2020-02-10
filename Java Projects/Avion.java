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
public class Avion {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        boolean found = false;
        String output = "";

        for (int i = 0; i < 5; i++) {
            String line = s.nextLine();

            for (int j = 0; j < (line.length() - 2); j++) {

                if (line.charAt(j) == 'F' && line.charAt(j+1) == 'B' && line.charAt(j+2) == 'I') {
                    output += (i+1);
                    
                        output += " ";
                   
                    found = true;
                }
            }
        }
        if(found){System.out.println(output);}
        if (!found) {
            System.out.println("HE GOT AWAY!");
        }

    }
}
