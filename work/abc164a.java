import java.util.*;

public class abc164a {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int s = sc.nextInt();
	int w = sc.nextInt();
	if(w  >= s)
	System.out.println("unsafe");
	else
	System.out.println("safe");
	sc.close();
	}
}