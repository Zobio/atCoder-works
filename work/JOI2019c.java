import java.util.*;

public class JOI2019c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
		for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
		ArrayList<Integer> al = new ArrayList<Integer>();
		int count = 1;
		for(int j = 1; j < n; j++) {
			if(a[j] >= a[j - 1]){
				count++;
			}else{
				al.add(count);
				count = 1;
			}
		}
		al.add(count);
		Collections.sort(al);
		System.out.println(al.get(al.size() - 1));
    }
}