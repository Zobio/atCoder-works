import java.util.*;

public class abc173a {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(n % 1000 == 0 ? 0 : 1000 - n % 1000);
	}
}