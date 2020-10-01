import java.util.*;
import java.lang.*;

public class Main3a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
		StringBuilder dog = new StringBuilder();
		String[] name = new String[26];
		name[0] = "a";
		name[1] = "b";
		name[2] = "c";
		name[3] = "d";
		name[4] = "e";
		name[5] = "f";
		name[6] = "g";
		name[7] = "h";
		name[8] = "i";
		name[9] = "j";
		name[10] = "k";
		name[11] = "l";
		name[12] = "m";
		name[13] = "n";
		name[14] = "o";
		name[15] = "p";
		name[16] = "q";
		name[17] = "r";
		name[18] = "s";
		name[19] = "t";
		name[20] = "u";
		name[21] = "v";
		name[22] = "w";
		name[23] = "x";
		name[24] = "y";
		name[25] = "z";
		String num26 = Integer.toString(n, 26);


		if(n - 1 > Math.pow(26, 10)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 10)){
			dog.append("zzzzzzzzzz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n - 1 > Math.pow(26, 9)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 9)){
			dog.append("zzzzzzzzz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n - 1 > Math.pow(26, 8)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 8)){
			dog.append("zzzzzzzz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n - 1 > Math.pow(26, 7)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 7)){
			dog.append("zzzzzzz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n - 1 > Math.pow(26, 6)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 6)){
			dog.append("zzzzzz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n - 1 > Math.pow(26, 5)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 5)){
			dog.append("zzzzz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n - 1 > Math.pow(26, 4)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 4)){
			dog.append("zzzz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n - 1 > Math.pow(26, 3)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 3)){
			dog.append("zzz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n - 1 > Math.pow(26, 2)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 2)){
			dog.append("zz");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n > Math.pow(26, 1)){
			dog.append(name[(int)(n / Math.pow(26, 10) - 1)]);
			n = n / 26 + n % 26;
		}
		else if(n == Math.pow(26, 1)){
			dog.append("z");
			System.out.println(dog);
			return;
		}
		System.out.println(n);
		System.out.println(dog);

		if(n != 0){
		dog.append(name[(int)n - 1]);
		}
		System.out.println(dog);
    }
}