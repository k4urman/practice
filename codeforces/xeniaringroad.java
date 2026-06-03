import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int m = s.nextInt();
        int x;

        long count = 0;
        int pos = 1;

        for(int i = 0; i < m; i++) {
            x = s.nextInt();

            if (x >= pos) {
                count += x - pos;
            } else {
                count += (n-pos) + x;
            }
            pos = x;
        }
        System.out.println(count);
        s.close();

    }
}
