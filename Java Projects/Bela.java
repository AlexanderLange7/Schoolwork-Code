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
public class Bela {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int hands = sc.nextInt();
        String domSuit = sc.next();
        int total = 0;
        int counter = 0;
        while (counter < hands * 4) {
            String card = sc.next();
            String face = card.substring(0, 1);
            String suit = card.substring(1);
            counter++;
            if (domSuit.equals(suit)) {
                switch (face) {
                    case "A":
                        total += 11;
                        break;
                    case "K":
                        total += 4;
                        break;
                    case "Q":
                        total += 3;
                        break;
                    case "J":
                        total += 20;
                        break;
                    case "T":
                        total += 10;
                        break;
                    case "9":
                        total += 14;
                        break;
                    case "8":
                        total += 0;
                        break;
                    case "7":
                        total += 0;
                        break;

                }

            } else {
                switch (face) {
                    case "A":
                        total += 11;
                        break;
                    case "K":
                        total += 4;
                        break;
                    case "Q":
                        total += 3;
                        break;
                    case "J":
                        total += 2;
                        break;
                    case "T":
                        total += 10;
                        break;
                    case "9":
                        total += 0;
                        break;
                    case "8":
                        total += 0;
                        break;
                    case "7":
                        total += 0;
                        break;

                }
            }
        }
        System.out.println(total);
    }

}
