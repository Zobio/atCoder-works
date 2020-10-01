import java.util.*;
public class ans174d {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		int ans = 0;
		int Rc = 0;
		for(int i = 0; i < N; i++)
			if(S.charAt(i) == 'R')
				Rc++;
		for(int i = 0; i < Rc; i++)
			if(S.charAt(i) == 'W')
				ans++;
		System.out.println(ans);
	}
 
}