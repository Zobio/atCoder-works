import java.util.*;

public class Main2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 0;
        int[] a = new int[n];
        int[] b = new int[n];
        boolean[] success = new boolean[n];
        Arrays.fill(success, false);
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        if(a[0] == b[0]){
        success[0] = true;
        count++;
        }

        for(int i = 1; i < n; i++) {
            if(count == 3) {
                System.out.println("Yes");
                System.exit(0);
            }
            if(a[i] == b[i] && (count == 0 || success[i - 1])){
            count++;
            success[i] = true;
            }
            else if(a[i] == b[i]) {
                success[i] = true;
            }
            else if(a[i] != b[i]) {
                count = 0;
            }
            if (count == 3) {
                System.out.println("Yes");
                System.exit(0);
            }
        }
        System.out.println("No");
    }
}