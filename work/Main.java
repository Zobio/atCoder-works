import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lengh = sc.nextInt();
        String[] commands = new String[lengh];
        for(int i = 0 ; i < lengh ; i++) {
            commands[i] = sc.nextLine();
        }
        int[] hole = new int[];
        for(int i = 0 ; i < lengh ; i++) {
            String command = commands[i];
            String[] commandargs = command.split(" ");
            int type = Integer.valueOf(commandargs[0]);
            int score = Integer.valueOf(commandargs[1]);
            if(type == 1) {
                int count = Integer.valueOf(commandargs[2]);
                hole += score * count;
            } else {
                System.out.println(hole);
            }

        }

    }
}