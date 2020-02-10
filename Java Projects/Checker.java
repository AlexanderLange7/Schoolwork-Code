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
public class Checker {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int truth = 1;
        String lines = "";
        char[][] grid = new char[n][n];

        //look at the lines and do the easy checks. IE the # of chars per row AND 3cons
        for (int i = 0; i < n; i++) {
            String line = sc.next();
            lines += line;
            int numwhite = 0;
            int numblack = 0;
            for (int j = 0; j < n; j++) {
                if (line.charAt(j) == 'W') {
                    numwhite++;
                } else {
                    numblack++;
                }
            }

            if (line.contains("WWW") || line.contains("BBB") || numwhite != numblack) {
                truth = 0;
                System.out.println(truth);
                System.exit(0);
            }
        }
        //rip we have to check columns. let's set up the board rotated left one
        //just go through all of the lines, add their characters to a string, and use .contains again.
        String fix = "";
        int spaces = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                grid[i][j] = lines.charAt(spaces);
                spaces++;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                fix += grid[k][j];
            }

        }
        //Now that they're rotated. Again.
        for (int i = 0; i < n; i++) {
            String current = fix.substring((i * n), ((i * n) + n));
            if (current.contains("WWW") || current.contains("BBB")) {
                truth = 0;
                System.out.println(truth);
                System.exit(0);
            }
        }

        System.out.println(truth);
    }

}
