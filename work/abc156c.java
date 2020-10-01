import java.util.*;

public class abc156c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x = new int[n];
        for(int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
        }
        int sum = 0;
        int point = 0;
        for(int j = 0; j < n; j++) {
            sum += x[j];
        }
        double ave = (double)sum / n;
        if(ave % 1 >= 0.5){
        point = (int)ave + 1;
        }else{
            point = (int)ave;
        }
        long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += ((point - x[i]) * (point - x[i])); 
        }
        System.out.println(ans);
    }
}