import java.util.*;
import java.lang.*;
import java.math.*;
 
public class Main2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        double X1 = sc.nextDouble();
        double Y1 = sc.nextDouble();
        double X2 = sc.nextDouble();
        double Y2 = sc.nextDouble();
        System.out.println(X1 + Y1 * ((X2 - X1) / (Y1 + Y2)));
	}
}