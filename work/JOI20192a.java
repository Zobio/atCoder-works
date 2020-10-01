import java.util.*;

public class JOI20192a {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] exam = new int[3];
		exam[0] = sc.nextInt();
		exam[1] = sc.nextInt();
		exam[2] = sc.nextInt();
		Arrays.sort(exam);
		System.out.println(exam[1] + exam[2]);
    }
}