import java.util.*;

public class JOI20191b {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] str = sc.next().toCharArray();
		int count = 0;
		for(int i = 0; i < n; i++) {
			switch(str[i]){
				case 'a':
				case 'i':
				case 'u':
				case 'e':
				case 'o':
				count++;
				break;
			}
		}
		System.out.println(count);
    }
}