import java.util.*;

public class Main1 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        if(s.equals("Y")) {
            System.out.println(t.toUpperCase());
        }else{
            System.out.println(t);
        }
	}
}