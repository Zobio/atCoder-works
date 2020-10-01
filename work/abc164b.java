import java.util.*;

public class abc164b {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int a = sc.nextInt();
	int b = sc.nextInt();
	int c = sc.nextInt();
	int d = sc.nextInt();

	for(int i = 0; i < 100; i++) {
		c -= b;
		if(c <= 0)
		break;
		a -= d;
		if(a <= 0)
		break;
	}
	if(c <= 0)
	System.out.println("Yes");
	else
	System.out.println("No");
	sc.close();
	}
}