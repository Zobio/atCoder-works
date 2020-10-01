import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
 
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Obj[] arr = new Obj[n];
		for (int i = 0; i < n; i++) {
			String[] sa = br.readLine().split(" ");
			Obj o = new Obj();
			o.a = Long.parseLong(sa[0]);
			o.b = Long.parseLong(sa[1]);
			arr[i] = o;
		}
		br.close(); // 配列にそれぞれのインスタンスを格納
 
		for (Obj o : arr) {
			if (o.a != 0 || o.b != 0) {
				long gcd = gcd(o.a, o.b);
				o.a /= gcd; //美味しさと香り高さの最大公約数でわる
				o.b /= gcd;
				if (o.a < 0) {
					o.a *= -1; //積は正負が逆転しても問題ないから美味しさが-の場合は逆転させる
					o.b *= -1;
				}
			}
		}
 
		int zero = 0;
		Map<Obj, Integer> map = new HashMap<>();
		for (Obj o : arr) {
			if (o.a == 0 && o.b == 0) {
				zero++;
			} else {
				if (map.containsKey(o)) {
					map.put(o, map.get(o) + 1);
				} else {
					map.put(o, 1);
				}
			}
		}
 
		int mod = 1000000007;
		long ans = 1;
		Obj[] keys = map.keySet().toArray(new Obj[0]);
		for (Obj k : keys) {
			if (!map.containsKey(k)) {
				continue;
			}
			int v1 = map.get(k);
			long a = power(2, v1, mod);
 
			Obj k2 = new Obj();
			if (k.b > 0) {
				k2.a = k.b;
				k2.b = -k.a;
			} else if (k.b == 0) {
				k2.b = 1;
			} else {
				k2.a = -k.b;
				k2.b = k.a;
			}
			Integer v2 = map.get(k2);
			if (v2 != null) {
				long a2 = power(2, v2, mod) - 1;
				a += a2;
				map.remove(k2);
			}
			ans *= a;
			ans %= mod;
		}
		ans--;
		ans += zero + mod;
		ans %= mod;
		System.out.println(ans);
	}
 
	static class Obj {
		long a, b;
 
		@Override
		public boolean equals(Object o) {
			Obj o2 = (Obj) o;
			if (a == o2.a && b == o2.b) {
				return true;
			}
			return false;
		}
 
		@Override
		public int hashCode() {
			return (int) (31 * a + b);
		}
	}
 
	static long power(long x, long n, int m) {
		if (n == 0) {
			return 1;
		}
		long val = power(x, n / 2, m);
		val = val * val % m;
		if (n % 2 == 1) {
			val = val * x % m;
		}
		return val;
	}
 
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
}