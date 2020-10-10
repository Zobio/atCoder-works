import java.util.*;

public class Main3 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		boolean[] yet = new boolean[200001];
		int count = 0;
		int now = 0;
		for(int i = 0; i < n; i++) {
			now =sc.nextInt();
			yet[now] = true;
			while(yet[count]){
				count++;
			}
			System.out.println(count);
		}
	}
}