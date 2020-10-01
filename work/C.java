import java.util.*;
import java.io.*;

public class C {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
	long a = sc.nextLong();
	double b = sc.nextDouble();
	sc.close();
	long c = (long)Math.round(b * 100);
	long d = a * c;
	System.out.println(d / 100);
    }
}