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
public class Cup {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lines = sc.nextInt();
        String[] colors = new String[lines];
        int[] sizes = new int[lines];

        //FOR EACH LINE
        for (int i = 0; i < lines; i++) {
            //array size of 2.
            String[] line = sc.next().split(" ");
            
            //If the first token was a word
            if (line[0].charAt(1) >= 97 && line[0].charAt(1) <= 122) {
                //Set the first word as a color
                colors[i] = line[0];
                //Set its corresponding size
                sizes[i] = Integer.parseInt(line[1]);
            } else {
                //Set the firs word as a size/2
                sizes[i] = Integer.parseInt(line[1])/2;
                //Set its corresponding color
                colors[i] = line[0];
            }
            i++;
        }

        for (int i = 0; i < lines; i++) {
            System.out.println(colors[i]);
            System.out.println(sizes[i]);
        }

    }

}
