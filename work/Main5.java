import java.util.*;
import java.lang.*;

public class Main5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		Integer[] num = new Integer[n];
		for(int a = 0; a < n; a++){
			num[a] = sc.nextInt();
		}
		Arrays.sort(num);
		int multi1 = num[0];
		int multi2 = num[n - 1];
		for(int b = 0; b < k; b++){
		multi1 *= num[b];
		multi2 *= num[n - 1 - b]; 
		System.out.println(multi1);
		System.out.println(multi2);
		}
		if(multi1 >= multi2){
			System.out.println(multi1);
		}
		else if(multi1 < multi2){
			System.out.println(multi2);
		}
    }
}