import java.util.*;

public class JOI2019b {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] joi = sc.next().toCharArray();
		for(int i = 2; i < joi.length; i++) {
			if(joi[i - 2] == 'j' && joi[i - 1] == 'o' && joi[i] == 'i'){
				joi[i - 2] = 'J';
				joi[i - 1] = 'O';
				joi[i] = 'I';
			}
		}
		for(int j = 0; j < joi.length; j++) {
			System.out.print(joi[j]);
		}
		System.out.println();
    }
}