import java.util.*;

public class abc166b {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); //すぬけ君
		int k = sc.nextInt(); //お菓子の数
		int treat[][] = new int[n][k];
		int num = 0;
		for(int i = 0; i < k ; i++) {
			int pn = sc.nextInt();
			for (int t = 0; t < pn; t++) { //人数だけ繰り返し
				num = sc.nextInt();
				System.out.println(num - 1);
				treat[num - 1][i] = 1; // i個目のお菓子を持っているすぬけ君を１にする
			}
		}
		int count = 0;
		int person = 0;
		for (int a = 0; a < n; n++){
			for (int b = 0; b < k; k++) {
				if(treat [a][b] == 0)
				count++;
			}
			if(count == k){
			person++; // もし全てのお菓子をもっていないならperson++
			}
			count = 0;
		}
		System.out.println(person);
	}
}