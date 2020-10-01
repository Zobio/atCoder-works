import java.util.*;
import static java.lang.Math.*;

public class ans176d {
	static class Path {
		int x, y;
		int w;
		public Path(int y, int x, int w) {
			this.x = x;
			this.y = y;
			this.w = w;
		}
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int H = sc.nextInt();
		int W = sc.nextInt();
		int sy = sc.nextInt()-1;
		int sx = sc.nextInt()-1;
		int gy = sc.nextInt()-1;
		int gx = sc.nextInt()-1;
		boolean[][] map = new boolean[H][W];
		for(int i=0; i<H; i++) {
			char[] c = sc.next().toCharArray();
			for(int j=0; j<W; j++)
				map[i][j] = c[j]=='#';
		}
		
		int[][] warp = new int[H][W];
		for(int i=0; i<H; i++)
			Arrays.fill(warp[i], Integer.MAX_VALUE);
		
		LinkedList<Path> list = new LinkedList<>();
		list.add(new Path(sy, sx, 0));
		
		while(!list.isEmpty()) {
			Path cur = list.poll();
			if(warp[cur.y][cur.x] <= cur.w)
				continue;
			for(int dy=-2; dy<=2; dy++) {
				int ny = cur.y+dy;
				if(ny<0 || H<=ny)
					continue;
				for(int dx=-2; dx<=2; dx++) {
					int nx = cur.x+dx;
					if(nx<0 || W<=nx)
						continue;
					if(map[ny][nx])
						continue;
					int d = Math.abs(dy)+Math.abs(dx);
					if(d==0) {
						continue;
					} else if(d==1) {
						list.addFirst(new Path(ny, nx, cur.w));
					} else {
						list.addLast(new Path(ny, nx, cur.w+1));
					}
				}
			}
			warp[cur.y][cur.x] = cur.w;
		}
		
		System.out.println(warp[gy][gx]<Integer.MAX_VALUE ? warp[gy][gx] : -1);
		sc.close();
	}
}
