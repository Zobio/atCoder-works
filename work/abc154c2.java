import java.util.*;

public class abc154c2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashSet<Integer> c = new HashSet<Integer>();
        for (int i = 0; i < n; i++) {
                c.add(sc.nextInt());
        }
        if(c.size() == n)
        System.out.println("YES");
        else
        System.out.println("NO");
    }
}