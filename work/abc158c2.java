import java.util.*;

public class abc158c2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double tax_8 = sc.nextDouble();
		double tax_10 = sc.nextDouble();
		for(int i = 0; i <= 1250; i++) {
			if((int)(i * 0.08) == tax_8 && (int)(i * 0.1) == tax_10) {
				System.out.println(i);
				System.exit(0);
			}
		}
		System.out.println("-1");
	}
}