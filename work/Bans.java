import java.util.*;
import java.io.PrintWriter;
public class Bans{
	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		long n = sc.nextLong();
		long ans = 0;
		for(long i = 2; i*i <= n; i++){
			int count = 0;
			while(n % i == 0){
				System.out.println("n:" + n + " i:" + i);
				count++;
				n /= i;
			}
			System.out.println("count:" + count);
			for(int j =1 ; count - j >= 0 ; j++){
				ans++;
				count -= j;
				System.out.println("j:" + j + " count:" + count);
			}
		}
		if(n > 1){
			ans++;
			System.out.println("ansが追加された");
		}
		System.out.println(ans);
	}
}