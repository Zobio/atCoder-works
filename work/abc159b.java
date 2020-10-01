import java.util.*;

public class abc159b {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		boolean same = true;
		for(int i = 0; i < s.length; i++) {
			if(s[i] != s[s.length - 1 - i]){
				System.out.println("No");
				System.exit(0);
			}
		}
		for(int j = 0; j <= (s.length - 2) / 2; j++) {
			if(s[j] != s[(s.length - 2) / 2 - j]){
				System.out.println("No");
				System.exit(0);
			}
		}
		int count = 0;
		for(int a = (s.length + 2) / 2; a < s.length; a++){
		if(s[a] != s[(s.length - 2) / 2 - count]){
			System.out.println("No");
			System.exit(0);
		}
		count++;
	}
		System.out.println("Yes");
	}
}