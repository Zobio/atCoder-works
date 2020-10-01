import java.util.*;

public class us1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p = sc.nextInt();
		if(p >= 400 && p <= 599) {
			System.out.println("8");
		}
		else if(p >= 600 && p <= 799) {
			System.out.println("7");
		}
		else if(p >= 800 && p <= 999) {
			System.out.println("6");
		}
		else if(p >= 1000 && p <= 1199) {
			System.out.println("5");
		}
		else if(p >= 1200 && p <= 1399) {
			System.out.println("4");
		}
		else if(p >= 1400 && p <= 1599) {
			System.out.println("3");
		}
		else if(p >= 600 && p <= 1799) {
			System.out.println("2");
		}
		else if(p >= 1800 && p <= 1999) {
			System.out.println("1");
		}
	}
}