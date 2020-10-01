import java.util.*;
public class ans167b {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int k = sc.nextInt();
		System.out.println(Math.min(a, k) - Math.max(k - a - b, 0));
	}
}