import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static class Pascal {
        private BigInteger[][] data;
        
        public Pascal() {
            data = new BigInteger[129][];
            for (int level = 0; level < data.length; level++) {
                data[level] = new BigInteger[level + 1];
                data[level][0] = data[level][level] = BigInteger.ONE;
                for (int i = 1; i < level; i++)
                    data[level][i] = data[level-1][i].add(data[level-1][i-1]);
            }
        }

        public String toString(int level) {
            StringBuilder pascal = new StringBuilder();
            for (int y = 0; y < level; y++)
                for (int x = 0; x < data[y].length; x++)
                    pascal.append(data[y][x].toString())
                          .append(x + 1 < data[y].length? " ": "\n");
            return pascal.toString();
        }
    }
    
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Pascal pascal = new Pascal();
        while (cin.hasNextInt()) {
            int n = cin.nextInt();
            if (n == 0)
                break;
            System.out.println(pascal.toString(n));
        }
    }
}
