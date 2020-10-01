import java.util.*;

public class abc162b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long count = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 || i % 5 == 0)
                continue;
            else
                count += i;
        }
        System.out.println(count);
    }
}