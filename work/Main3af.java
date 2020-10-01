import java.util.*;

public class Main3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = Math.abs(sc.nextLong()); // 最初の座標
        long k = sc.nextLong(); // 回数
		long d = sc.nextLong(); // 移動距離
		long num = x / d;
		boolean plusOne = false;
		if(Math.abs(x - (x / d) * d) > Math.abs(x - (x / d + 1) * d))
		plusOne = true;
		if(plusOne && (num + 1) >= k){
		System.out.println(Math.abs(x - d * k));
		System.exit(0);
		}
		else if(plusOne == false && num >= k){
		System.out.println(Math.abs(x - d * k));
		System.exit(0);
		}
		else if(x - k * d == 0) {
			System.out.println("0");
			System.exit(0);
		}
		else if(plusOne == false && ((num % 2 == 0 && k % 2 == 0) || (num % 2 == 1 && k % 2 == 1))) {
			System.out.println(x - num * d);
			System.exit(0);
		}
		else if(plusOne && ((num % 2 == 0 && k % 2 == 1) || (num % 2 == 1 && k % 2 == 0))) {
			System.out.println(Math.abs(x - (x / d + 1) * d));
			System.exit(0);
		}
		else if(plusOne == false && ((num % 2 == 0 && k % 2 == 1) || (num % 2 == 1 && k % 2 == 0))) {
			long plusNum = Math.abs(Math.abs(x - num * d) + d);
			long minusNum = Math.abs(Math.abs(x - num * d) - d);
			System.out.println(Math.min(plusNum, minusNum));
		}
		else if(plusOne && ((num % 2 == 0 && k % 2 == 0) || (num % 2 == 1 && k % 2 == 1))) {
			long plusNum = Math.abs(Math.abs(x - (num + 1) * d) + d);
			long minusNum = Math.abs(Math.abs(x - (num + 1) * d) - d);
			System.out.println(Math.min(plusNum, minusNum));
		}
    }
}