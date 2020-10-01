import java.util.*;

public class Main1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double d = sc.nextDouble();
		double t = sc.nextDouble();
		double s = sc.nextDouble();
		if(d / s <= t)
		System.out.println("Yes");
		else
		System.out.println("No");
	}
}