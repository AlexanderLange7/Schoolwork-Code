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
public class DC {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] numlist = new int[N+M-1];
        //List will be from 2 to N+M, so we will have X spaces, where X is N+M-1.
        for (int i = 0; i < (N + M - 1); i++) {
          numlist[i]=0;  
        }
        int[][] arr = new int[N][M];
        //ADD DICE VALUES TO GRAPH
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //Add 2 because arrays start at 0
                arr[i][j] = i + j + 2;
            }
        }
        //LOOP THRU GRAPH AND ADD TO ARRAYLIST   
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //ADD TO LIST BASED ON NUM
                numlist[arr[i][j]-2]++;
            }    
        }
        //sout indexes of the highest arr+2
        int max = 0;
        for(int i = 0; i < numlist.length; i++){
            if(numlist[i]>max){
                max = numlist[i];
            }
        }
        int incrementer = 1;
        for(int i = 0; i < numlist.length; i++){
        if(numlist[i]==max){
            System.out.println(numlist[i]+incrementer);
            incrementer ++;
        }
        }
        
    
    
    }
}
