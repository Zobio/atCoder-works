import java.util.*;
 
public class Eans {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        
        if (n % 2 == 0) {
            double mid1 = (double)(a[n/2] + a[n/2-1]) / 2;
            double mid2 = (double)(b[n/2] + b[n/2-1]) / 2;
            
            double tmp = mid2 - mid1;
            // System.out.println(mid1);
            
            System.out.println((int)(tmp*2)+1);
        } else {
            int mid1 = a[n/2];
            int mid2 = b[n/2];
            
            System.out.println(mid2 - mid1 + 1);
        }
    }
}