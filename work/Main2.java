import java.util.*;

public class Main2 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        char[][] bed = new char[h][w];
        char[] line = new char[w];
        for(int i = 0; i < h; i++) {
            line = sc.next().toCharArray();
            for(int j = 0; j < w; j++) {
                bed[i][j] = line[j];
            }
        }
        long count = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w - 1; j++) {
                if(bed[i][j] == ('.') && bed[i][j + 1] == ('.'))
                count++;
            }
        }
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h - 1; j++) {
                if (bed[j][i] == ('.') && bed[j + 1][i] == ('.'))
                    count++;
            }
        }
        System.out.println(count);
	}
}