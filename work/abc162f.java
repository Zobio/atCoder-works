import java.util.*;

public class abc162f {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Integer[] srt = a.clone();
        Arrays.sort(srt, Collections.reverseOrder());

    }
}