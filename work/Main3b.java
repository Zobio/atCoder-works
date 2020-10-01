import java.util.*;

public class Main3b {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int k = sc.nextInt();
	if(k % 2 == 0){
		System.out.println("-1");
		System.exit(0);
	}
	if(k == 7 || k == 1){
		System.out.println("1");
		System.exit(0);
	}
	boolean finish = false;
	int count = 2;
	final int num = 7 % k;
	int amari = num;
	boolean[] al = new boolean[1000000]; // kが7未満対策で配列の要素数を上限まで確保
	al[7] = true;
	while(finish == false){
		if((amari * 10 + num) % k == 0) {
			finish = true;
		}
		else if(al[(amari * 10 + num) % k]) {
			System.out.println("-1");
			System.exit(0);
		}
		else if(!((amari * 10 + num) % k == 0)){
			amari = (amari * 10 + num) % k;
			al[amari] = true;
			System.out.println(amari);
			count++;
		}
	}
	System.out.println(count);
	sc.close();
	}
}