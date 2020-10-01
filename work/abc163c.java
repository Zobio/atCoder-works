import java.util.*;
import java.lang.*;
 
public class abc163c {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] num = new int[n];
		int point = 0;
		for(int i = 0; i < n - 1; i++) {
			point = sc.nextInt();
			num[point - 1]++;
		}
		for(int j = 0; j < n; j++) {
			System.out.println(num[j]);
		}
	}
}