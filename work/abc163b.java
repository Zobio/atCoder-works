import java.util.*;
import java.lang.*;
 
public class abc163b {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int m = sc.nextInt();
	for(int i = 0; i < m; i++) {
		n -= sc.nextInt();
	}
	if(n >= 0) {
		System.out.println(n);
	}else{
		System.out.println("-1");
	}
	}
}