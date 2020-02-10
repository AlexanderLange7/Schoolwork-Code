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
public class apax {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        String line = s.nextLine();
        String out = "";
        char lastchar = 'Z';
        for(int i = 0; i < line.length(); i++){
        if(line.charAt(i)!=lastchar){
        out+=line.charAt(i);
        lastchar = line.charAt(i);
        }
        }
       
        System.out.println(out);
    }

}
