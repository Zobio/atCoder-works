import java.util.*;
public class ans173c {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();
		char[][] c = new char[H][W];
		for(int i = 0; i < H; i++)
			c[i] = sc.next().toCharArray();
		int ans = 0;
		for(int i = 0; i < 1<<(H+W); i++) {
			boolean[] x = new boolean[H+W];
		    for(int j = 0; j < (H+W); j++)
		        if ((1 & i >> j) == 1)
		            x[j] = true;
		    int black = 0;
		    for(int j = 0; j < H; j++)
		    	for(int k = 0; k < W; k++)
		    		if(x[j] && x[H+k] && c[j][k] == '#')
		    			black++;
		    if(black == K)
		    	ans++;
		}
		System.out.println(ans);
	}
 
}