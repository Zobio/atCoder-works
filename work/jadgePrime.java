import java.util.HashMap;
import java.util.Scanner;


public class jadgePrime {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
	long n = sc.nextLong();
	boolean p = isPrime(n);
	if(p == true)
	System.out.println("Prime Number");
	if(p == false)
	System.out.println("Not Prime Number");
  }
  public static boolean isPrime(long n) {
  if (n == 2) {
    return true;
  } else if ((n < 2) || (n % 2 == 0)) {
    return false;
  } else {
	long lim = (long) Math.sqrt(n);
	System.out.println("lim:" + lim);
    for (int i = 3; i <= lim; i += 2) {
		System.out.println("i:" + i);
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}

}