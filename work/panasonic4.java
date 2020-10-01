import java.util.*;

public class panasonic4 {
    public static void main(String[] a) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] le = new char[10];
        le[0] = 'a';
        le[1] = 'b';
        le[2] = 'c';
        le[3] = 'd';
        le[4] = 'e';
        le[5] = 'f';
        le[6] = 'g';
        le[7] = 'h';
        le[8] = 'i';
        le[9] = 'j';
        if (n == 1) {
            System.out.println("a");
            System.exit(0);
        }
        char[] ans = new char[n];
        int[] st = new int[n];
        Arrays.fill(st, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = le[0];
        }

    }
}