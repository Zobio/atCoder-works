import java.util.*;

public class abc166d {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		for(int a = -100000; a <= 100000; a++){
			for(int b = -10000; b < a; b++){
				if(a*a*a*a*a - b*b*b*b*b == x){
					System.out.println(a + " " + b);
					return;
				}
			}
		}
    }
}