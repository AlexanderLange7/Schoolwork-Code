/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Arrays;
import java.util.Scanner;
import java.util.HashMap;

/**
 *
 * @author alex.lange
 */
public class PH {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        char[] a = line.toCharArray();
        //Go through  spaces 0,3,6,9,12 in string
        char[] arr = new char[5];
        arr[0] = a[0];
        arr[1] = a[3];
        arr[2] = a[6];
        arr[3] = a[9];
        arr[4] = a[12];

        Arrays.sort(arr);

        //previous array space
        int previous = arr[0];
        //frequent
        int popular = arr[0];
        //total 
        int count = 1;
        int maxCount = 1;
        //loop thru array
        for (int i = 1; i < arr.length; i++) {
            //if array[i] == previous spot in array
            if (arr[i] == previous) {
                //increment most frequent
                count++;
            } else {
                //if count is > our current maximum
                if (count > maxCount) {
                    //set the frequent char to previous space in array
                    popular = arr[i - 1];
                    //get a new max count
                    maxCount = count;
                }
                previous = arr[i];
                count = 1;
            }
        }

        System.out.println(count);

    }
}
