/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import static java.util.Arrays.sort;
import java.util.Scanner;
/**
 *
 * @author alex.lange
 */
public class K {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int[] nums = new int[4];
    for(int i = 0; i < 4; i++){
    nums[i]=sc.nextInt();
    
    }
    //sort
    sort(nums);
        System.out.println(nums[0]*nums[2]);
    
    }
}
