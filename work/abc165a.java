import java.util.*;

public class abc165a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        for(int i = 1; i < 1000; i++) {
            if (a <= (k * i) && (k * i) <= b){
                System.out.println("OK");
                return;
            }
            else if (b < (k * i)){
                System.out.println("NG");
                return;
            }
		}
		System.out.println("NG");
    }
}