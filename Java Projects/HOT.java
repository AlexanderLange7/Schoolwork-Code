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
public class HOT {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int currnum = 0;
    int denials = 0;
    int threshold = sc.nextInt();
    int cases = sc.nextInt();
    sc.nextLine();
    for(int i = 0; i < cases; i++){
    String line = sc.nextLine();
    String EoL = line.substring(0,1);
    int terracegoers = Integer.parseInt(line.substring(6));
        
        if(EoL.equals("e") && terracegoers + currnum > threshold){
            denials++;
        }else if(EoL.equals("e")){
        currnum+=terracegoers;
        }else if(EoL.equals("l")){
        currnum-=terracegoers;
        }
    }
        System.out.println(denials);
    
    
    }
}
