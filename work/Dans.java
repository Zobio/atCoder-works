import java.util.HashMap;
import java.util.Scanner;
 
public class Dans {
 
  public static void main(String[] args) {
 
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
 
    long lim = (long) Math.sqrt(n);
    long res = 0;
    HashMap<Long, Integer> map = new HashMap<Long, Integer>();
 
    if (isPrime(n)) {
      System.out.println(1);
      return;
    }
 
    long devideNum = 2;
 
    while ((n != 1) && (devideNum <= lim)) {
      if (isPrime(devideNum)) {
        while (n % devideNum == 0) {
          if (map.containsKey(devideNum)) {
            map.put(devideNum, (map.get(devideNum)) + 1);
          } else {
            map.put(devideNum, 1);
          }
          n /= devideNum;
        }
      }
      devideNum++;
    }
 
    if (n != 1) {
      map.put(n, 1);
    }
 
    for (long key : map.keySet()) {
      int tmp = map.get(key);
      int i = 1;
      while (true) {
        if (tmp - i >= 0) {
          tmp -= i;
          i++;
          res++;
        } else {
          break;
        }
      }
    }
    System.out.println(res);
 
  }
 
  static boolean isPrime(long n) {
 
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