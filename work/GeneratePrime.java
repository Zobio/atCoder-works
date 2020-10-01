import java.util.HashMap;
import java.util.Scanner;


public class GeneratePrime {
  public static void main(String[] args) {
    for(long n = 2; n <= 9223372036854775807L; n++){
      if(isPrime(n) == true)
      System.out.println(n);
    }
  }
  public static boolean isPrime(long n) {
  if (n == 2) {
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

}