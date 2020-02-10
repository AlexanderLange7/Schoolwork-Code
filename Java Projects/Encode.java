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
public class Encode {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int cases = sc.nextInt();
        
        
        for (int i = 0; i <= cases; i++) {
            //Get the String to work with
            String line = sc.nextLine();
            //Get the amount of characters in the string
            int linelen = line.length();
            //Get the root of that to make our grid
            int lendiv = (int) Math.round(Math.sqrt(linelen));

            //EXAMPLE: THE LENGTH WAS 9 AND THE ROOT WAS 3
            //Make a grid of size [3][3]
            char[][] characters = new char[lendiv][lendiv];
            
            //Keep track of what character from the string we plug into the grid
            int space = 0;
            


            //Rotate the square counterclockwise one
            //STARTING AT THE BOTTOM LEFT SPACE
            for (int j = 0; j < lendiv; j++) {
                for (int k = lendiv-1; k >= 0; k--) {
                    characters[j][k] = line.charAt(space);
                    space++;
                }
            }
            
            
            
            //output the entire square from left to right
            String outmessage = "";
            for (int j = 0; j < lendiv; j++) {
                for (int k = 0; k < lendiv; k++) {
                    outmessage += characters[k][j];
                }
            }
            System.out.println(outmessage);
        }

    }

}
