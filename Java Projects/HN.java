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
public class HN {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        boolean done = false;
        //LOOK AT EVERYTTHING i AND GREATER. ONCE HARSHAD, OUTPUT
        while (!done) {
            String nums = String.valueOf(i);
            
            int k = 0;
            for (int j = 0; j < nums.length(); j++) {

                k += Character.getNumericValue(nums.charAt(j));
            }    
                if (i % k == 0) {
                    done = !done;
                    System.out.println(i);
                }else{
                i++;
                }
            
            

        }

    }
}
