import java.util.*;
public class ans175c {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long X = Math.abs(sc.nextLong()); // 最初の座標
		long K = sc.nextLong(); //回数
		long D = sc.nextLong(); //移動距離
		long ans = X;
		if(K <= (double) X / D)
			ans = X - K * D;
		else {
			K -= X / D;
			X %= D;
			if(K % 2 == 1)
				ans = Math.abs(X - D);
			else
				ans = X;
		}
		System.out.println(ans);
	}
 
}