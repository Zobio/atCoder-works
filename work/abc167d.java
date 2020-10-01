import java.util.*;

public class abc167d {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
        int[] town = new int[n];
        for (int i = 0; i < n; i++) {
            town[i] = sc.nextInt();
		}
		int ans = 1;
		int dup[] = new int[n];
		for (long l = 0; l < k; n++) {
			if(Arrays.asList(dup).contains(ans)) {
				System.out.println("重複あり");
				System.exit(0);
			}else{
			ans = town[ans - 1];
			dup[(int)l] = town[ans - 1]; //配列でlong無理だからどうにかする
			}
		}
		System.out.println(ans);
    }
}