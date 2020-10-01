import java.util.*;
 
public class ans167a{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
 
        String s = sc.next();
        String t = sc.next();
 
        System.out.println(t.substring(0, t.length() - 1).equals(s) ? "Yes" : "No");
    }
}