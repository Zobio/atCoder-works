import java.util.*;
import java.lang.*;

public class abc161b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        int[] A = new int[n];
        double voteSum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            voteSum += a[i];
        }
        Arrays.sort(a);
        for (int j = 0; j < m; j++) {
            if (a[n - j - 1] >= voteSum / (4 * m)) {
            } else {
                System.out.println("No");
                System.exit(0);
            }
        }
        System.out.println("Yes");
    }
}