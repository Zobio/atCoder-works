import java.util.*;

public class abc157c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int digit = -1;
        int num = -1;
        for(int i = 0; i < m; i++) {
            digit = sc.nextInt();
            num = sc.nextInt();
            if((ans[digit - 1] == -1 || ans[digit - 1] == num) && !(digit == 1 && num == 0)) {
                ans[digit - 1] = num;
            }else{
                System.out.println("-1");
                System.exit(0);
            }
        }
        
        if(ans[0] == -1 && n != 1) {
            System.out.print("1");
        }
        else if(ans [0] == -1 && n == 1) {
            System.out.print("0");
        }else{
            System.out.print(ans[0]);
        }

        if(ans.length == 1) {
            System.out.println();
            System.exit(0);
        }

        for(int j = 1; j < m; j++) {
            if(ans[j] == -1) {
                System.out.print("0");
            }else{
                System.out.print(ans[j]);
            }
        }
        System.out.println();
    }
}