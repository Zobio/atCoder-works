import java.util.*;

public class abc162d {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        long R = 0;
        long G = 0;
        long B = 0;
        char[] let = s.toCharArray();
        for (int i = 0; i < n; i++) {
            switch (let[i]) {
                case 'R':
                    R++;
                    break;
                case 'G':
                    G++;
                    break;
                case 'B':
                    B++;
                    break;
            }
        }
        long ans = R * G * B;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if ((a != b && (a + b) % 2 == 0) && (b - a >= 0)) {
                    if (let[a] == let[b] || let[a] == let[(a + b) / 2] || let[b] == let[(a + b) / 2]) {

                    } else {
                        ans--;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}