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
public class FB {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int X = sc.nextInt();
    int Y = sc.nextInt();
    int N = sc.nextInt();
    for(int i = 1; i<N + 1; i++){
    if(i%X==0){
        if(i%Y==0){
            System.out.println("FizzBuzz");
        }else{
        System.out.println("Fizz");
        }
    }else if(i%Y==0){
        System.out.println("Buzz");
    }else{
        System.out.println(i);
    }
    
    
    
    
    }
    
    
    
    }
}
