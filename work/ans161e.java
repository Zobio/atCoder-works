import java.util.Scanner;

public class ans161e {
    public static char[] getInvert(char[] array) {
        char[] res = new char[array.length];
        res = array;
        for (int i = 0; i < array.length / 2; i++) {
            char temp = res[i];
            res[i] = res[array.length - 1 - i];
            res[array.length - 1 - i] = temp;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int c = sc.nextInt();

        String s = sc.next();

        char[] sa = s.toCharArray();

        // i回目の最速の勤務日
        int[] l = new int[k + 1];
        l[0] = 0;

        int count = 0;
        for (int i = 0; i < n && count < k;) {
            if (sa[i] == 'o') {
                count++;
                l[count] = i + 1;
                i += c + 1;
            } else {
                i++;
            }
        }

        char[] saRev = getInvert(sa);
        int[] r = new int[k + 1];
        r[0] = 0;
        count = 0;
        for (int i = 0; i < n && count < k) {
            if (saRev[i] == 'o') {
                count++;
                r[k + 1 - count] = n - i;
                i += c + 1;
            } else {
                i++;
            }
        }
        for (int i = 1; i <= k; i++) {
            if (l[i] == r[i])
                System.out.println(l[i]);
        }
    }
}