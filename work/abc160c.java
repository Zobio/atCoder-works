import java.util.*;

public class abc160c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] diff = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int j = 1; j < n; j++) {
            diff[j - 1] = a[j] - a[j - 1];
        }
        diff[n - 1] = k - a[n - 1] + a[0];
        Arrays.sort(diff);
        System.out.println(k - diff[n - 1]);
    }
}