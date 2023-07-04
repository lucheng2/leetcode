package hj6;

import java.util.Scanner;

import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {
        int n;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        for (int i=2; i<=sqrt(n); i++) {
            while (n%i==0) {
                System.out.printf("%d ", i);
                n = n/i;
            }
        }
        if (n>1) {
            System.out.printf("%d", n);
        }
    }
}
