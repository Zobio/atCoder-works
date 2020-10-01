import java.util.*;

public class Main3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
		}
		long ans = 0;
		long mod = 1000000007L;
		list<long> loop = new ArrayList<long>();
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				for(int b = 0; b < a[i]; b++){
				ans = (ans + a[j]) % mod;
				if(loop.contains(ans)){
					j = j - j % b;
				}
				loop.add(ans);
				}
			}
		}
		System.out.println(ans);
	}
}