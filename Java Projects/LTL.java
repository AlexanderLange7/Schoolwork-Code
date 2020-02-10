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
public class LTL {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int input = sc.nextInt();
    int[] debris = new int[input];
    for(int i = 0; i < input; i++){
    debris[i] = sc.nextInt();
    }
    //Loop through to find smallest debris
    int minimum=200000000;
    int minday =200000000;
    for(int i = 0; i < input; i++){
    if(debris[i]<minimum){
        minimum = debris[i];
        minday = i;
    }
    }
    
    
        System.out.println(minday);
    
    
    
    }
}
