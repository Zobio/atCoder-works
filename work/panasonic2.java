import java.util.*;

public class panasonic2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long h = sc.nextLong();
        long w = sc.nextLong();
        if (h == 1 || w == 1) {
            System.out.println("1");
        } else if (h % 2 == 0 || w % 2 == 0) {
            System.out.println(h * w / 2);
        } else if (h % 2 == 1 && h % 2 == 1) {
            System.out.println((h / 2 + 1) * (w / 2 + 1) + (h / 2) * (w / 2));
        }
    }
}