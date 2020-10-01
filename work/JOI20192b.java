import java.util.*;

public class JOI20192b {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		char[] str = sc.next().toCharArray();
		char[] str2 = str.clone();
		int num = 0;
		for(int i = a - 1; i <= b - 1; i++) {
			str[i] = str2[b - 1 - num];
			num++;
		}
		for(int j = 0; j < n; j++) {
			System.out.print(str[j]);
		}
		System.out.println();
    }
}