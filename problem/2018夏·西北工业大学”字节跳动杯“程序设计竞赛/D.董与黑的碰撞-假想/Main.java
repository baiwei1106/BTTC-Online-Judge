import java.util.*;
import java.math.*;

public class Main{
    public static void main(String[] args) {
        BigInteger d[] = new BigInteger[100005];
        BigInteger one = new BigInteger("1");
        BigInteger ten = new BigInteger("10");
        BigInteger MOD = new BigInteger("100000000");
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        for (int kase = 1; kase <= T; kase++) {
            int N = cin.nextInt();
            for(int i = 0; i < N; i++) {
                int a = cin.nextInt();
                int b = cin.nextInt();
                d[i] = BigInteger.valueOf(b-a+1);
            }
            boolean flag = true;
            while (N > 1) {
                N = (N + 1) / 2;
                for (int i = 0; i < N; i++) {
                    if(!d[i*2].gcd(d[i*2+1]).equals(one)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int i = 0; i < N; i++) {
                        d[i] = d[i*2].multiply(d[i*2+1]);
                    }
                }
                else {
                    break;
                }
            }
            if(!flag) {
                System.out.println("inf");
            }
            else {
                BigInteger ans = d[0].subtract(one).multiply(ten).mod(MOD);
                System.out.println(String.format("%08d", ans));
            }
        }
    }
}
