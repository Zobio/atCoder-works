import java.util.*;

public class JOI20191a {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int oneCount = 0;
		int twoCount = 0;
		for(int i = 0; i < 3; i++) {
			if(sc.nextInt() == 1)
			oneCount++;
			else
			twoCount++;
		}
		System.out.println(oneCount > twoCount ? "1" : "2");
    }
}