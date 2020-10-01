import java.util.*;

public class Main3 {
	public static void main(String[] args) { //n未満の数の(素因数の個数)P2
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = 0;
		int num = 0;
		Integer[] sameCount = new Integer[316];
		Arrays.fill(sameCount, 0);
		ArrayList<Integer> source = new ArrayList<Integer>();
		long ans = 0;
		int nowNum = 0;
		boolean end = false;
		for(int i = 1; i < n; i++) {
			end = false;
			nowNum = i;
			while(!end){
				System.out.println(nowNum);
				System.out.println(isPrime(nowNum));
				System.out.println("ans:" + ans);
			if(isPrime(nowNum)){
				if (source.contains(nowNum)) {
					sameCount[nowNum]++;
				}
				source.add(nowNum);
				source.add(1);
				if(nowNum == 1)
				sameCount[1]++;
				Collections.sort(source);
				Arrays.sort(sameCount, Collections.reverseOrder());
				ans += source.size() * (source.size() - 1);
				System.out.println("source.size():" + source.size());
				System.out.println(sameCount[0]);
				while(sameCount[q] != 0) {
					System.out.println("minus:" + ((sameCount[q] + 1) - (sameCount[q]) - 1));
					ans -= (sameCount[q] + 1) * (sameCount[q]) - 1;
					q++;
				}
				source.clear();
				Arrays.fill(sameCount, 0);
				end = true;
			}else{
				num = newPrime(nowNum);
				if(source.contains(num)){
					sameCount[num]++;
				}
				source.add(num);
				nowNum /= num;
				System.out.println("nowNum:" + num);
			}
		}
		}
		System.out.println(ans);
	}

	public static boolean isPrime(int n) {
		if (n == 2 || n == 1) {
			return true;
		} else if ((n < 2) || (n % 2 == 0)) {
			return false;
		} else {
			long lim = (long) Math.sqrt(n);
			for (int i = 3; i <= lim; i += 2) {
				if (n % i == 0) {
					return false;
				}
			}
			return true;
		}
	}

	public static int newPrime(int n) {
			long lim = (long) Math.sqrt(n);
			for (int i = 2; i <= lim; i += 2) {
				if (n % i == 0) {
					return i;
				}
			}
			return 1;
	}
}