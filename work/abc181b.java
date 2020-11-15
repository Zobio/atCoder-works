import java.util.*;
import java.lang.*;
 
public class abc181b {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long ans = 0;
		int a = 0;
		int b = 0;
		for(int i = 0; i < n; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			for(int j = a; j <= b; j++) {
				ans += j;
			}
		}
		System.out.println(ans);
	}
}