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
public class AHC {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for(int i = 0; i < cases; i++){
            double velocity = sc.nextDouble();
            double angle = sc.nextDouble();
            double hole = sc.nextDouble();
            double holeY1 = sc.nextDouble();
            double holeY2 = sc.nextDouble();
            double t = hole / velocity / Math.cos(Math.toRadians(angle));
            double y = velocity * t * Math.sin(Math.toRadians(angle)) - 4.905 * Math.pow(t, 2);
            if(y - holeY1 >= 1 && holeY2 - y >= 1)
                System.out.println("Safe");
            else
                System.out.println("Not Safe");
        
        
        
        
       
        
        
        }
    
    
    }
}
