import java.util.*;

public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 0;
        int x = 0;
        n = sc.nextInt();
        x = sc.nextInt();
		char[] result = sc.next().toCharArray();
        for(int i = 0; i < result.length; i++) {
            if(result[i] == 'x' && x > 0) {
                x--;
            }
            else if(result[i] == 'o') {
                x++;
            }
        }
        System.out.println(x);
    }
}