import java.util.*;
import java.lang.*;

public class abc159d {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		List<Integer> point = new ArrayList<Integer>();
		for(int i = 0; i < n; i++) {
			point.add(sc.nextInt());
		}
		int count = 0;
		int ans = 0;
		for(int j = 0; j < n; j++) {
			List<Integer> pointSort = new ArrayList<Integer>();
			List<Integer> pointSort = point.clone();
			pointSort.remove(j);
			pointSort.sort();
			List<Integer> countSum = new ArrayList<Integer>();
			for(int a = 1; a < n - 1; a++) {
				if(point.get(a) == point.get(a - 1)) {
					count++;
				}else{
					countSum.add(count + 1);
					count = 0;
				}
			}
			for(int b = 0; b < pointSort.size(); b++) {
				ans += countSum.get(b);
			}
			System.out.println(ans);
			ans = 0;
		}
	}
}