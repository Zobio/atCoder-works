import java.util.*;

public class chartest {
    public static void main(String[] args) {
		Random rd = new Random();
		for(int i = 0; i < 10000000; i++){
			char c = (char)rd.nextInt(10000);
		System.out.print(c);
		}
    }
}