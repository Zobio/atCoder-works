import java.util.*;
 
public class ans170d {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		A[N] = 1000001;
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		Arrays.sort(A);
		sc.close();
 
		boolean[] check = new boolean[1000001];
		Arrays.fill(check, true);
		int ans = 0;
 
		// 小さい順に見ていく
		for (int i = 0; i < N; i++) {
			if (A[i + 1] != A[i] && check[A[i]]) {
				ans++;
			}
 
			for (int j = A[i]; j <= A[N - 1]; j += A[i]) {
				check[j] = false;
			}
		}
 
		System.out.println(ans);
	}
}