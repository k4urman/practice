import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        String x = s.next();
        String y = "";
        n--; 
        int team1 = 1;
        int team2 = 0;

        for(int i = 0; i < n; i++) {
            y = s.next();
            if (y.equals(x)) {
                team1++;
            } else {
                team2++;
            }
        }

        if (team1 > team2) {
            System.out.println(x);
        } else {
            System.out.println(y);
        }

        s.close();

    }
}
