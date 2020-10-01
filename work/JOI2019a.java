import java.util.*;

public class JOI2019a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int l = sc.nextInt();
		int r = sc.nextInt();
		int ans = l;
		for(int i = l; i <= r; i++) {
			if(Math.abs((x - i)) < Math.abs(x - ans)) {
				ans = i;
			}
		}
		System.out.println(ans);
    }
}