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
public class IIH {
    public static void main(String[] args)
    {
    Scanner sc = new Scanner(System.in);
    String a = sc.nextLine();
    if(a.equals("OCT 31") || a.equals("DEC 25")){
        System.out.println("yup");
    }else{
        System.out.println("nope");}
    }
}
