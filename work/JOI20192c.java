import java.util.*;

public class JOI20192c {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] num = new int[n];
		for(int i = 0; i < n; i++) {
			num[i] = sc.nextInt();
		}
		Arrays.sort(num);
		int[] numCount = new int[m + 1];
		for(int j = 0; j < n; j++) {
			if(num[j] > m)
			break;
				numCount[num[j]]++;
		}
		int ans = 0;
		for(int a = 0; a <= m; a++) {
			if(ans < numCount[a]){
			ans = numCount[a];
			}
		}
		System.out.println(ans);
    }
}