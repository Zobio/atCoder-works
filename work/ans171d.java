import java.util.*;
public class ans171d {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
 
		int n = sc.nextInt();
 
		int[] a = new int[100001];
 
		long sm = 0l;
		for ( int i=0; i<n; i++ ) {
			int a1 = sc.nextInt();
			sm += (long)a1;
			a[a1]++;
		}
 
		int q = sc.nextInt();
 
		for ( int i=0; i<q; i++ ) {
			int b = sc.nextInt();
			int c = sc.nextInt();
 
			sm = sm + (long)(c-b)*(long)a[b];
			System.out.println(sm);
 
			a[c] += a[b];
			a[b] = 0;
		}
 
	}
}