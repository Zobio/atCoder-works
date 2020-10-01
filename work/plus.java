import java.util.*;

public class plus {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
		long x = plus(100);
    }
    public static long plus (long x) {
        long u = (long)(x * 0.01);
        return (u + x);
    }
}