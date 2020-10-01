import java.util.Scanner;
 
public class ansLamps {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
 
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
 
		for (int j = 0; j < k; j++) {
			int[] sum = new int[n];
 
			for (int i = 0; i < n; i++) {
				int s, t;
				if (i - a[i] < 0) {
					s = 0;
				} else {
					s = i - a[i];
				}
				if (i + a[i] + 1 < n) {
					sum[i + a[i] + 1] -= 1;
				}
				sum[s] += 1;
			}
 
			for (int i = 0; i < n; i++) {
				if (i == 0) {
					a[i] = sum[i];
				} else {
					a[i] = a[i - 1] + sum[i];
				}
			}
 
			boolean f = true;
			for (int i = 0; i < n; i++) {
				if (a[i] != n) {
					f = false;
					break;
				}
			}
			if (f) {
				break;
			}
		}
 
		for (int i = 0; i < n - 1; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println(a[n - 1]);
 
	}
 
}