import java.util.*;
import java.io.*;
 
public class ans172c {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int N = sc.nextInt(), M = sc.nextInt(), K = sc.nextInt();
		
		long[] Apref = new long[N+1];
		for (int i = 0; i < N; i++) {
			Apref[i+1] = Apref[i] + sc.nextInt();
		}
		
		TreeMap<Long, Long> map = new TreeMap<>();
		map.put(0l, 0l);
		long s = 0;
		for (int i = 0; i < M; i++) {
			s += sc.nextInt();
			map.put(s, i+1l);
		}
		
		long best = 0;
		for (int i = 0; i <= N; i++) {
			Long k = map.floorKey(K - Apref[i]);
			if (k != null) {
				best = Math.max(best, i + map.get(map.floorKey(K - Apref[i])));
			}
		}
		
		System.out.println(best);
	}
}