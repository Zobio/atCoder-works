import java.util.*;

public class abc159a {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int ans = 0;
		if(n >= 2){
			ans += n * (n - 1) / 2;
		}
		if(m >= 2){
			ans += m * (m - 1) / 2;
		}
		System.out.println(ans);
	}
}