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
public class MF {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    while(a!=0 && b !=0){
    
    
        System.out.println((a/b)+ " "+ (a%b) + " / " + b);
    a = sc.nextInt();
    b = sc.nextInt();
    }
    
}
}
