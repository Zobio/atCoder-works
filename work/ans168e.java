import java.util.*;
public class ans168e {
	
	static long gcd(long a, long b) {
		return b == 0 ? a: gcd(b, a % b);
	}
	
	static String rev(String S) {
		if(S.equals("1,0"))
			return "0,1";
		else if(S.equals("0,1"))
			return "1,0";
		String[] s = S.split(",");
		if(s[0].charAt(0) == '-')
			return s[1] + "," + s[0].substring(1);
		else
			return "-" + s[1] + "," + s[0];
	}
	
	public static void main(String[] args) {
		int MOD = 1000000007;
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String C;
		Map<String, Integer> m1 = new HashMap<>();
		Map<String, Integer> m2 = new HashMap<>();
		int zero = 0;
		for(int i = 0; i  < N; i++) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			if(A == 0 && B == 0) {
				zero++;
				continue;
			}
			long gcd = gcd(A, B);
			A /= gcd;
			B /= gcd;
			if(B < 0) {
				A = -A;
				B = -B;
			}
			if(B == 0)
				C = "1,0";
			else if(A == 0)
				C = "0,1";
			else
				C = A + "," + B;
			if(A >= 0 && B != 0)
				m1.put(C, m1.getOrDefault(C, 0)+1);
			else 
				m2.put(C, m2.getOrDefault(C, 0)+1);		
		}
		long ans = 1;
		long[] pow2 = new long[N+1];
		pow2[0] = 1;
		for(int i = 1; i <= N; i++)
			pow2[i] = pow2[i-1] * 2 % MOD;
		for(String s : m1.keySet()) {
			int a = m1.get(s), b = m2.getOrDefault(rev(s), 0);
			ans = ans * (pow2[a] + pow2[b] - 1) % MOD;
		}
		for(String s : m2.keySet())
			if(!m1.containsKey(rev(s)))
				ans = ans * pow2[m2.get(s)] % MOD;
		System.out.println((ans + zero - 1 + MOD) % MOD);
	}
 
}