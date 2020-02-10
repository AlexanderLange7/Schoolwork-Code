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
public class HR {
    public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int cases=sc.nextInt();
    for(int i = 0; i < cases; i++){
    int b = sc.nextInt();
    double p = sc.nextDouble();
    
    double BPM = (60 * b) / p;
    double maxABPM = (BPM/b)+BPM;
    double minABPM = BPM-(BPM/b); 
    System.out.println(minABPM + " " + BPM + " " + maxABPM);
    }
    }
}

