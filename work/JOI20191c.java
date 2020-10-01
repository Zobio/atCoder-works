import java.util.*;

public class JOI20191c {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int m = sc.nextInt();
		ArrayList<Integer> a = new ArrayList<Integer>();
		ArrayList<Integer> b = new ArrayList<Integer>();
		for(int i = 0; i < h; i++) {
			a.add(sc.nextInt());
		}
		for(int i = 0; i < m; i++) {
			b.add(sc.nextInt());
		}
		ArrayList<Integer> c = new ArrayList<Integer>();
		while(!(a.size() == 0 && b.size() == 0)) {
			if(a.size() == 0) {
				c.add(b.get(0));
				b.remove(0);
				continue;
			}
			if(b.size() == 0) {
				c.add(a.get(0));
				a.remove(0);
				continue;
			}
				c.add(Math.min(a.get(0), b.get(0)));
				if(a.get(0) <= b.get(0)){
				a.remove(0);
				}else{
				b.remove(0);
				}
		}
		for(int q = 0; q < c.size(); q++) {
			System.out.println(c.get(q));
		}
    }
}