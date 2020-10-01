import java.util.*;

public class Prime {
    public static void main(String[] args) {

        long[] Primes = new long[1000000];
        for(int i = 2; i <= 1000000; i++){
            Primes[i] = i * i;
        }
		long num = new Scanner(System.in).nextLong();
		long count = 0;
		for(int q = 2; q < 1000000; q++){
			if(num % Primes[q] == 0){
			num /= Primes[q];
			count++;
			}
		}
		System.out.println(count);
    }
}