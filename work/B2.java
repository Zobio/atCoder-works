import java.util.*;
import java.lang.*;

public class B2 {
	public static void main(String[] args) {
		long ans = 1;
		Scanner sc = new Scanner(System.in);
		long first = sc.nextLong();
		long[] ans = new long[first];
		for (long i = 0; i < first; i++){
			ans[i] = sc.nextLong();
		}
		for (long l = 0; l < first; l++) {
			
		}
		if (ans > 1000000000000000000L){
			ans = -1;
		}
		System.out.println(ans);
	}
}