import java.io.*;
import java.util.*;

public class abc168eTest {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		long[] iwashi = new long[num * 2];
		for (int i = 0; i < num * 2; i += 2) {
			iwashi[i] = sc.nextInt();
			iwashi[i + 1] = sc.nextInt(); //偶数が美味しさ、奇数が香り高さ
		}
		long[] pair = new long[num];
		for (int n = 0; n < num; n ++) {
			pair[n] = iwashi[n * 2] * iwashi[n * 2 + 1]; //それぞれのイワシの美味しさと香り高さの積をpairに格納
		}

		long[] con = new long[(num * (num - 1)) / 2]; //nC2(n個の中から順序を選ばず2個選ぶ)
		long count = 0;
		int ele = 0;
		for (int t = 0; t < con.length; t++) { //掛ける左側の要素のfor
			for (int l = 1; l < pair.length; l++) { //掛ける右側の要素のfor
				for (int a = 0; a <= t; t++){
				ele = ele + (num - a); // n番目の要素の組み合わせの終着地点
				}
				con[l] = pair[0] + pair[0]; //　con[終着地点- イワシの要素数 + 今の数] = pair[今の数] + pair[今の数 + 1]
			}
		}

		for (int b = 0; b < con.length; b++) {
			System.out.println("con[b]:" + con[b]);
		}
	}
}