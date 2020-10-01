import java.util.*;

public class abc166c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] h = new int[n];
        for(int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }
        boolean[] good = new boolean[n];
		Arrays.fill(good,true);
		int form = 0;
		int lett = 0;
		for(int j = 0; j < m * 2; j += 2) {
			form = sc.nextInt();
			lett = sc.nextInt();
			if(h[form - 1] > h[lett - 1]){
				good[lett - 1] = false;
				System.out.println("lettがfalse");
				System.out.println("form:" + form + " lett:" + lett);
			}
			if(h[form - 1] < h[lett - 1]){
				good[form - 1] = false;
				System.out.println("formがfalse");
				System.out.println("form:" + form + " lett:" + lett);
			}
		}
		int count = 0;
		for(int k = 0; k < n; k++) {
			if(good[k])
			count++;
		}
		System.out.println(count);
		sc.close();
    }
}