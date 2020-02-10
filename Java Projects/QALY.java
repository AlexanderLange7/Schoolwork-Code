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
public class QALY {
    public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int g = sc.nextInt();
    double sum = 0;
    for(int i = 0; i < g; i++){
    double x = sc.nextDouble();
    double y = sc.nextDouble();
    sum+=x*y;
    
    }
        System.out.println(sum);
    
    
    }
}
