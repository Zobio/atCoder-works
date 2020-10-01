import java.util.*;
 
public class Main{
	public static void main(String args[]) {
 
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int[] A = new int[N]; 
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt() - 1;
		}
 
		int[] time = new int[N];
		Arrays.fill(time, -1);
 
		int now = 0;
		int clock = 0;
 
		while(K > 0) {
			if(time[now] == -1) {
				time[now] = clock++;
				now = A[now];
				K--;
			}
			else {
				K %= clock - time[now];
				break;
			}
		}
		
		while(K > 0) {
				now = A[now];
				K--;
		}
 
		System.out.println(now+1);
		sc.close();
	}
}