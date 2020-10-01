import java.util.*;

public class abc157b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer[][] num = new Integer[3][3];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                num[i][j] = sc.nextInt();
            }
        }
        int n = sc.nextInt();
        HashSet<Integer> bingo = new HashSet<Integer>();
        Iterator<Integer> it = bingo.iterator();
        boolean[][] already = new boolean[3][3];
        for(int i = 0; i < n; i++) {
            bingo.add(sc.nextInt());
        }
        int a = 0;
        while (it.hasNext()) {
            for(int i = 0; i < 3; i++) {
               for(int j = 0; j < 3; j++) {
                  if(num[i][j] == it.next()){
                    already[i][j] = true;
                  }
             }
          }
     }
        boolean ans = false;
        for(int i = 0; i < 3; i++) {
            if(already[i][0] && already[i][1] && already[i][2])
            ans = true;
        }
        for (int i = 0; i < 3; i++) {
            if (already[0][i] && already[1][i] && already[2][i])
                ans = true;
        }
        if(already[0][0] && already[1][1] && already[2][2])
        ans = true;
        if (already[0][2] && already[1][1] && already[2][0])
        ans = true;
        if(ans)
        System.out.println("Yes");
        else
        System.out.println("No");
    }
}