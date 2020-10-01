import java.util.*;

public class Main5 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int m = sc.nextInt();
		boolean[][] bomb = new boolean[h][w];
		for(int i = 0; i < m; i++) {
			bomb[sc.nextInt() - 1][sc.nextInt() - 1] = true;
		}
		int hHighest = 0;
		int wHighest = 0;
		int hCount = 0;
		int wCount = 0;
		int hSum = 0;
		int wSum = 0;
		int hHighestPlace = 0;
		int wHighestPlace = 0;
		int hHighestPlaceNum = 0;
		int wHighestPlaceNum = 0;
	   boolean[][] yet = new boolean[h][w];
		for(int j = 0; j < h; j++) {
			for(int k = 0; k < w; k++) {
				if(bomb[j][k] && !yet[j][k]){
					hCount++;
					hSum++;
					yet[j][k] = true;
				}
			}
			if(hCount > hHighest){
				hHighest = hCount;
				hHighestPlace = j;
				hHighestPlaceNum = hCount;
			}
			else if(h - hSum <= hHighest){
				break;
			}
			hCount = 0;
		}
		for(int j = 0; j < w; j++) {
			for(int k = 0; k < h; k++) {
				if(bomb[k][j] && !yet[k][j]){
					wCount++;
					wSum++;
					yet[k][j] = true;
				}
			}
			if(wCount > wHighest){
				wHighest = wCount;
				wHighestPlace = j;
				wHighestPlaceNum = wCount;
			}
			else if(w - wSum <= wHighest){
				break;
			}
			wCount = 0;
		}
		System.out.println(hHighestPlaceNum + wHighestPlaceNum);
	}
}