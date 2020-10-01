import java.util.*;

public class abc154c {
    public static void main(String[] args) { //素因数リストを作ってって、すでにcontainsだったらNO
        //重複のないListに順番にそれぞれの数の素因数を入れていって、4などの数の時に例外が出ないようにする
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] d = a.clone();
        HashSet<Integer> sourcePrime = new HashSet<Integer>();
        int num = 0;
        for(int i = 0; i < n; i++) {
            while(d[i] != 1){
            if(isPrime(d[i])){
                if(sourcePrime.contains(d[i])){
                System.out.println("NO");
                System.exit(0);
                }
                sourcePrime.add(d[i]);
                d[i] = 1;
            }else{
                for(int j = 2; j < Math.sqrt(d[i]); j++) {
                    if(d[i] / j == 0) {
                        if (sourcePrime.contains(j)) {
                            System.out.println("NO");
                            System.exit(0);
                        }
                        sourcePrime.add(j);
                        d[i] /= j;
                    }
                }
            }
        }
        }
        Iterator<Integer> it = sourcePrime.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
        System.out.println("YES");
    }

    public static boolean isPrime(int num) {
        for(int i = 2; i < Math.sqrt(num); i++) {
            if(num % i == 0)
            return false;
        }
        return true;
    }
}