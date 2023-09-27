import java.io.*;
import java.util.*;

public class sol{
    
    public static int n, m, q;
    public static int MAX = 505;
    public static long [] best = new long[MAX];
    public static int [][] a = new int [MAX][MAX]; 

    static class Pair{
       int fi, se; 
       Pair (int fi, int se){
           this.fi = fi;
           this.se = se;
            }
        }
    
    public static void getRow(int r){
        long ans = 0;
        long [] f = new long[m + 5];
        f[1] = 0;
        for (int i = 2; i <= m + 1; i++){
            if (a[r][i - 1] == 1) 
                f[i] = f[i - 1] + 1;
            else 
                f[i] = 0;
        }
        for (int i = 1; i <= m + 1; i++) ans = Math.max(ans, f[i]);
        best[r] = ans;
    }
    
    
    private static void run_case() throws Exception {
        n = io.nextInt();
        m = io.nextInt();
        q = io.nextInt();

        for (int i = 0; i < MAX; i++) best[i] = 0;

        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) 
                a[i][j] = io.nextInt();
        
        for (int i = 1; i <= n; i++) 
            getRow(i);
        

        for (int i = 1; i <= q; i++){
            int r = io.nextInt();
            int c = io.nextInt();
            a[r][c] ^= 1;
            
            getRow(r);
            long ans = 0;
            for (int j = 1; j <= n; j++) ans = Math.max(ans, best[j]);
            System.out.println(ans);
        }

        

        /*
        for (int i = 1; i <= q; i++){
            System.out.println(query[i].fi + " " + query[i].se);
        }
        */


    }
    
    public static void main(String[] args) throws Exception {
        int Test = 1;
       // Test = io.nextInt();
        for (int i = 1; i <= Test; i++){
            run_case();
        }
        io.close();
    }

    //-----------PrintWriter for faster output---------------------------------
    public static FastIO io = new FastIO();

    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a) l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++) a[i] = l.get(i);
    }


    //-----------MyScanner class for faster input----------
    static class FastIO extends PrintWriter {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar, numChars;

        // standard input
        public FastIO() {
            this(System.in, System.out);
        }

        public FastIO(InputStream i, OutputStream o) {
            super(o);
            stream = i;
        }

        // file input
        public FastIO(String i, String o) throws IOException {
            super(new FileWriter(o));
            stream = new FileInputStream(i);
        }

        // throws InputMismatchException() if previously detected end of file
        private int nextByte() {
            if (numChars == -1) throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars == -1) return -1; // end of file
            }
            return buf[curChar++];
        }

        // to read in entire lines, replace c <= ' '
        // with a function that checks whether c is a line break
        public String next() {
            int c;
            do {
                c = nextByte();
            } while (c <= ' ');
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = nextByte();
            } while (c > ' ');
            return res.toString();
        }

        public String nextLine() {
            int c;
            do {
                c = nextByte();
            } while (c < '\n');
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = nextByte();
            } while (c > '\n');
            return res.toString();
        }

        public int nextInt() {
            int c;
            do {
                c = nextByte();
            } while (c <= ' ');
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = nextByte();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = 10 * res + c - '0';
                c = nextByte();
            } while (c > ' ');
            return res * sgn;
        }

        public long nextLong() {
            int c;
            do {
                c = nextByte();
            } while (c <= ' ');
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = nextByte();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = 10 * res + c - '0';
                c = nextByte();
            } while (c > ' ');
            return res * sgn;
        }


        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
    //--------------------------------------------------------
}




