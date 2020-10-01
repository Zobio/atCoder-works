import java.util.*;

public class abc161c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long h = sc.nextLong();
        long k = sc.nextLong();
        long num = h / k;
        h -= k * num;
        while (true) {
            if (k / 2 < h) {
                h = Math.abs(h - k);
            } else {
                System.out.println(h);
                System.exit(0);
            }
        }
    }
}