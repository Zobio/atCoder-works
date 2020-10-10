import java.util.*;

public class Main4 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); //散らかってないところが照らされる回数はnC2 / 2回
        int h = sc.nextInt();
        int w = sc.nextInt();
        char[][] bed = new char[h][w];
        char[] line = new char[w];
        int quiet = 0;
        for (int i = 0; i < h; i++) {
            line = sc.next().toCharArray();
            for (int j = 0; j < w; j++) {
                bed[i][j] = line[j];
                if(line[j] == '.'){
                quiet++;
                }
            }
        }
        for(int i = quiet; i > 2; i--) {
            
        }
	}
}