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
public class CC {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String cipher = sc.next();
    char[] broken = cipher.toCharArray();
    int scale = 0;
    int days = 0;
    while(scale != broken.length){
    if(broken[scale]!= 'P'){
    days++;
    }
    scale++;
    if(broken[scale]!= 'E'){
    days++;
    }
    scale++;
    if(broken[scale]!= 'R'){
    days++;
    }
    scale++;
    }
        System.out.println(days);
    
    
    }
    
}
