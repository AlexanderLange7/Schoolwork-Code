/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Stack;
import java.util.Scanner;

/**
 *
 * @author alex.lange
 */
public class SSDF {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int datasets = sc.nextInt();
        int output = 0;
        Stack a = new Stack();

        for (int i = 0; i < datasets; i++) {
            int k = sc.nextInt();
            int b = sc.nextInt();
            int n = sc.nextInt();

            //Mess with the base of the numbers
            //Convert N to base 3 and then store
            
            
            while(n>0){
            output += (n%b) * (n%b);
            n/=b;
            
            }
            System.out.println(k + " " + output);
            output = 0;
        }

    }
}
