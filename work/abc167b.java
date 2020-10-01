import java.util.*;

public class abc167b { 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        int[] num = new int[A + B + C];
        for (int i = 0; i < A; i++){
            num[i] = 1;
        }
        for (int n = 0; n < B; n++) {
            num[A + n] = 0;
        }
        for (int t = 0; t < C; t++) {
            num[A + B + t] = -1;
        }
        int ans = 0;
        for (int a = 0; a < K; a++){
            ans = ans + num[a];
        }
        System.out.println(ans);
    }
}