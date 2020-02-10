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
public class PoC {
    public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int cakelength = sc.nextInt();
    int cuth = sc.nextInt();
    int cutv = sc.nextInt();
    int bigh = cuth;
    int bigv = cutv;
    if((cakelength - cuth) > (cakelength/2)){
    bigh = cakelength-cuth;
    }
    if((cakelength - cutv) > (cakelength/2)){
    bigv = cakelength-cutv;
    }
        System.out.println(bigh*bigv*4);
    
    
    
    
    
    
    }
}
