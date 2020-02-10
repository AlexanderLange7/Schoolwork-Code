/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
import java.util.Calendar;
import java.util.Date;

/**
 *
 * @author alex.lange
 */
public class Datum {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int m = sc.nextInt();

        Date c = new Date(2009-1900, m-1,d);
        c.getDay();
        String a = c.toString();
        char[] arr = a.toCharArray();
        if(arr[0] == 'S'){
            if(arr[1]=='u'){
                System.out.println("Sunday");
            }else{
                System.out.println("Saturday");
            }
        }else if(arr[0] == 'T'){
            if(arr[1] == 'h'){
                System.out.println("Thursday");
            }else{
                System.out.println("Tuesday");
            }
            
        }else if(arr[0] == 'M'){
            System.out.println("Monday");
        }else if(arr[0]== 'W'){
            System.out.println("Wednesday");
        }else{  System.out.println("Friday");}
        
        
        
        }
        }

    
