import java.util.*;

public class B {
	public static void main(String[] args) {
		long ans = 1;
		Scanner sc = new Scanner(System.in);
		long first = sc.nextLong();
		for (long i = 0; i < first; i++){
			ans = ans * sc.nextLong();
		}
		if (ans > 1000000000000000000L){
			ans = -1;
		}
		System.out.println(ans);
	}
}