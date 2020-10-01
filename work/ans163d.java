import java.util.Scanner;

public class ans163d {
    static final long M = 1000000007;

    public static void main(String[] args) {
        long N, K, res = 0;
        Scanner sc = new Scanner(System.in);
        N = sc.nextLong();
        K = sc.nextLong();
        for (long i = K; i <= N + 1; i++) {
            res = (res + (N * i % M - i * i % M + i + 1) % M) % M;
        }
        System.out.println(res);
    }
}