import java.util.*;

public class Hitachia {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		String h = sc.nextLine();
		if(h.length() % 2 == 1){
		System.out.println("No");
		System.exit(0);
		}else{
        String[] hi = new String[h.length() / 2];
        int count = 0;
        for(int i = 0; i < h.length();i += 2) {
            hi[i / 2] = h.substring(i, i + 2);
            if (hi[i / 2].equals("hi"))
            count++;
        }
        if (count == h.length() / 2)
        System.out.println("Yes");
        else
		System.out.println("No");
		}
    }
}