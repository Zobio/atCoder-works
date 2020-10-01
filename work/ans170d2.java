import java.util.Scanner;
import java.util.Arrays;
 
class ans170d2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) A[i] = sc.nextInt();
		Arrays.sort(A);
		boolean[] ng = new boolean[A[N - 1] + 1];
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (!ng[A[i]]) {
				if (!(i + 1 < N && A[i + 1] == A[i])) count++;
				for (int j = A[i]; j <= A[N - 1]; j += A[i]) ng[j] = true;
			}
		}
		System.out.println(count);
	}
}