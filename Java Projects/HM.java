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
public class HM {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String a = sc.nextLine();
    char[] b = a.toCharArray();
    String c = "no hiss";
    for(int i = 0; i < b.length-1; i++){
        char d = b[i];
        char e = b[i+1];
        char f = 's';
        if(d == e){
            if(e == f){
        c = "hiss";
        }}
}
        System.out.println(c);
 }
}