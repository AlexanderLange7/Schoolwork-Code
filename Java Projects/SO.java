/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author alex.lange
 */
public class SO {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int curr = sc.nextInt();
        int setnum = 1;
        //While The Integer !=0;
        while (curr != 0) {
            //Make an array of the set size
            String[] arr = new String[curr];
            //For each item per set
            for (int j = 0; j < curr; j++) {
                //Add the item to an array
                arr[j] = sc.next();
            }

            //Sort the array
            //FINAL OUTPUT
            System.out.println("");
            System.out.println("SET " + setnum);
            setnum++;
            int evens;
            int odds;
            
                if (arr.length % 2 == 0) {
                    //0,2,4,5,3,1 
                    evens = 0;
                    odds = arr.length;
                    while (evens < arr.length) {
                        System.out.println(arr[evens]);
                        evens += 2;
                    }
                    while (odds > 0) {
                        System.out.println(arr[odds-1]);
                        odds -= 2;
                    }
                } else {
                    //0,2,4,6,5,3,1
                    evens = 0;
                    odds = arr.length - 1;
                    while (evens <= arr.length - 1) {
                        System.out.println(arr[evens]);
                        evens += 2;
                    }
                    while (odds > 0) {
                        System.out.println(arr[odds-1]);
                        odds -= 2;
                    }
                }
            

            curr = sc.nextInt();

        }
    }

}
