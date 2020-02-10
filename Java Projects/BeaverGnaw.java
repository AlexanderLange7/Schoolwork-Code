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
public class BeaverGnaw {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int D = sc.nextInt();
    int V = sc.nextInt();
        while(D !=0 && V !=0){        
        //Calculate The Volume of the smaller cylinder.
        //This is done by subtracting the Volume of the Full Cylinder by
        //The V, and the Volume NOT Chomped by the idealizer Beaver.
        
        double BeaverSegmentVolume = D * Math.PI * Math.pow(D/2, 2);
        double HorizontalCones = Math.PI * Math.pow(D/2, 2) * (D/3);
        double currentpiece = BeaverSegmentVolume - V - HorizontalCones;
        double cyl = currentpiece*1.5;
        double radius = Math.pow((cyl/(2*Math.PI)), (1.0/3.0));
        //Now we have the colume of the mini cylinder! Now we must calculate the diameter of the mini cylinder.
        //We only have the volume though. SO. uhhh.
        //BUT we know that the the Height and Diameter are the SAME.
        
            System.out.println(radius*2);
            D = sc.nextInt();
            V = sc.nextInt();
        }
        
    
    
    
    
    
    }
}
