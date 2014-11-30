import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class BinomialTheorm {
    static long[][] C = new long[55][55];
 
    public static long C(int n, int r) {
        if (n < 0 || r < 0)
            return 0;
        else if (r > n)
            return C[n][r] = 0;
        else if (C[n][r] != -1)
            return C[n][r];
        else
            return C[n][r] = C(n - 1, r - 1) + C(n - 1, r);
    }
 
    public static void main(String[] args) throws IOException {
        int cc = 1;
        for (int i = 0; i < 55; i++)
            for (int j = 0; j < 55; j++)
                C[i][j] = -1;
        C[0][0] = 1;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        while (n-- > 0) {
            String input = in.readLine();
            String a = input.substring(input.indexOf('(') + 1, input
                    .indexOf('+'));
            String b = input.substring(input.indexOf('+') + 1, input
                    .indexOf(')'));
            int c = Integer.parseInt(input.substring(input.indexOf('^') + 1,
                    input.length()));
            StringBuilder res = new StringBuilder("");
            for (int i = 0; i <= c; i++) {
                int ea = c - i;
                if (C(c, i) > 1) {
                    res.append(C(c, i));
                    if (ea >= 1)
                        res.append('*');
                }
                if (ea >= 1) {
                    res.append(a);
                    if (ea > 1)
                        res.append("^" + ea);
                    if (i >= 1)
                        res.append('*');
                }
                if (i >= 1) {
                    res.append(b);
                    if (i > 1)
                        res.append("^" + i);
                }
                if (i != c)
                    res.append('+');
            }
            System.out.printf("Case %d: %s\n", cc++, res);
        }
    }
}