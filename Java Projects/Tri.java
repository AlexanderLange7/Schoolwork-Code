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
public class Tri {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    if(a + b == c){
        System.out.println(a + "+" + b + "=" + c);
    }else if (a - b == c){
        System.out.println(a + "-" + b + "=" + c);
    }else if (a / b == c){
        System.out.println(a + "/" + b + "=" + c);
    }else if (a * b == c){
        System.out.println(a + "*" + b + "=" + c);
    }else if ( a == b + c){
        System.out.println(a + "=" + b + "+" + c);
    }else if ( a == b - c){
        System.out.println(a + "=" + b + "-" + c);
    }else if ( a == b * c){
        System.out.println(a + "=" + b + "*" + c);
    }else if ( a == b / c){
        System.out.println(a + "=" + b + "/" + c);
    }
    }
}
