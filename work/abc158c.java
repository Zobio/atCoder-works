import java.util.*;

public class abc158c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double tax_8 = sc.nextDouble();
		double tax_10 = sc.nextDouble();
		boolean lowTax8 = false;
		if(tax_8 * 2 < tax_10) {
			System.out.println("-1");
			System.exit(0);
		}
		if(tax_8 * 12.5 < tax_10 * 10)
		lowTax8 = true;
        if(lowTax8 && tax_8 * 12.5 / 10 <= (int)tax_10) {
			System.out.println((int)(tax_8 * 12.5));
		}else if(lowTax8){
			System.out.println((int)(tax_10 * 10));
		}
		if(!lowTax8 && tax_10 * 10 / 8 <= (int)tax_8) {
			System.out.println((int)(tax_10 * 10));
		}else if(!lowTax8){
			System.out.println((int)(tax_8 * 12.5));
		}
	}
}