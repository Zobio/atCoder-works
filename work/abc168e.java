import java.io.*;
import java.util.*;

public class abc168e {
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
			System.out.println();
			System.out.println("pair[n]:" + pair[n]);
		}

		long count = 0;
		for (int t = 0; t < pair.length; t++) { 
			for (int a = 0; a < pair.length; a++) {
				if (t == a){}
				else if (pair[t] + pair[a] == 0)
				count++;
			}
		}
		System.out.println(num + (num - count / 2));
	}
}