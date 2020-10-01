import java.util.*;

public class abc168b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		String S = sc.next();
		sc.close();
		if (K >= S.length()){
			System.out.println(S);
		}else{
			System.out.println(S.substring(0, K) + "...");
		}
    }
}