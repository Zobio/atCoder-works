import java.util.*;

public class abc167b2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        if((A + B) >= K ) {
			if (A > K)
		System.out.println(K);
			else
		System.out.println(A);
		}
		else if((A + B) < K ) {
		System.out.println(A + (K - A -B) * - 1);
		}
    }
}