/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
import java.lang.Math;
/**
 *
 * @author alex.lange
 */
public class LD {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    double a = sc.nextInt();
    double b = sc.nextInt();
    b = Math.toRadians(b);
        
    double c =(a/Math.sin(b));
        System.out.println((int) Math.ceil(c));
    }
}
