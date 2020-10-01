import java.util.*;

	public class abc171d {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Integer[] a = new Integer[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int q = sc.nextInt();
		Integer[] b = new Integer[(q + 1) * 2];
		for(int j = 0; j < b.length - 2; j+= 2) {
			b[j] = sc.nextInt();
			b[j + 1] = sc.nextInt();
		}
		int ans = 0;
		for(int k = 0; k < b.length; k+= 2) {
			for(int l = 0; l < b.length; l+= 2) {
			if(a[l / 2] == b[k]){
				a[l / 2] = b[k + 1];
			}
			System.out.println(a[l / 2]);
			ans += a[l / 2];
		}
		System.out.println(ans);
		ans = 0;
		}
	}
}