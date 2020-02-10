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
public class Ctva {
    public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    
    //point a
    int ax = sc.nextInt();
    int ay = sc.nextInt();
    //point b
    int bx = sc.nextInt();
    int by = sc.nextInt();
    //point c
    int cx = sc.nextInt();
    int cy = sc.nextInt();
    
    int dx, dy;
    //find the outlier of the x's
    if(ax == bx){
        dx = cx;
    }else if(cx == bx){
        dx = ax;
    }else{
        dx = bx;
    }
    //find the outlier of the y's
    if(ay == by){
        dy = cy;
    }else if(cy == by){
        dy = ay;
    }else{
        dy = by;
    }
    
        System.out.println(dx + " " + dy);
    }
}
