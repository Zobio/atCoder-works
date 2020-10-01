import java.util.Scanner;
 
public class ans167c {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int[] c = new int[n];
		int[][] a = new int[n][m];
		for(int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for(int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
				System.out.println(a[i][j]);
			}
		}
		sc.close();
 
		int ans = Integer.MAX_VALUE;
		int all = 1<<n;
		for(int mask = 0; mask < all; mask++) {
			int[] level = new int[m];
			int cost = 0;
			for(int i = 0; i < n; i++) {
				if(((mask>>i)&1)==1) {
					cost += c[i];
					for(int j = 0; j < m; j++) {
						level[j] += a[i][j];
					}
				}
			}
			boolean ok = true;
			for(int j = 0; j < m; j++) {
				if(level[j] < x) {
					ok = false;
				}
			}
			if(ok) {
				ans = Math.min(ans, cost);
			}
		}
		if(ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}
}