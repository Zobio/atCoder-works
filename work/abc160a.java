import java.util.*;

public class abc160a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] c = sc.next().toCharArray();
        if (c[2] == c[3] && c[4] == c[5])
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}