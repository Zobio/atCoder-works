import java.util.*;
public class ans178c {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long MOD = 1_000_000_007;
		long a = 1, b = 1, c = 1;
		for(int i = 0; i < N; i++) {
			a = a * 8 % MOD;
			b = b * 9 % MOD;
			c = c * 10 % MOD;
		}
		System.out.println((c - b * 2 + a + 2 * MOD) % MOD);
	}

}