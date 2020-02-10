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
public class GS {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    double cost = sc.nextDouble();
    int lawns = sc.nextInt();
    double total = 0;
    for(int i = 0; i < lawns; i++){
    double lawnwidth = sc.nextDouble();
    double lawnlength = sc.nextDouble();
    total+=(lawnwidth*lawnlength*cost);
    }
        System.out.println(total);
    
    
    }
}
