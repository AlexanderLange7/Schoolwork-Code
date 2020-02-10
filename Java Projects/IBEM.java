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
public class IBEM {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<>();
        //The sum for a case = 0
        int sum = 0;
        //Grab the # of test cases we will need to do
        int testcases = sc.nextInt();
        //For EACH testcase
        for(int i = 0; i < testcases; i++){
            //Work through a case
            int currcase = sc.nextInt();
            //For each object in the current case
            for(int j = 0; j < currcase; j++){
            //We grab a town
            String town = sc.next();
            //If the town is not in our list
            if (!list.contains(town)){
            //Add it and increment our sum    
            list.add(town);
            sum++;
            }
            }
            //Output our sum after the case, clear the list, and loop again.
            System.out.println(sum);
            list.clear();
            sum=0;
        }
    
    }
}
