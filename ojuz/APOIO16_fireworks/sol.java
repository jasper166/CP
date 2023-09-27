import java.io.*;
import java.util.*;
// @Jasper

public class sol {
    static long LINF = (long) 1e18 + 5;
    static int INF = (int) 1e9 + 5;
    static int MOD = (int) 1e9 + 7;
    static int MAX = (int) 3e5 + 5;

    static long n, m, ans = 0, a, b;
    static long[] plague = new long [MAX];
    static long[] root = new long [MAX];

    static List <Integer>[] edges = new List[MAX];
    static PriorityQueue <Long>[] q = new PriorityQueue [MAX];

    public static void dfs(int u){
        root[u] = u;
        if (u > n){
            q[u].add(plague[u]);
            q[u].add(plague[u]);
            return;
        }

        for (int v : edges[u]){
            dfs(v);
            if (q[(int) root[v]].size() > q[(int) root[u]].size())
                root[u] = root[v];
        }

        for (int v : edges[u]){
            if (root[u] != root[v]){
                while (q[(int) root[v]].size() > 0){
                    long tmp = q[(int) root[v]].poll();
                    q[(int) root[u]].add(tmp);
                }
            }
        }
        for (int i = 1; i < edges[u].size(); i++) 
            q[(int) root[u]].poll();

        a = q[(int) root[u]].poll();
        b = q[(int) root[u]].poll();
        a += plague[u];
        b += plague[u];
        q[(int) root[u]].add(b);
        q[(int) root[u]].add(a);
    }


    //------------------Solution------------------------------------------------  
    private static void run_case() throws Exception {
        n = io.nextInt();
        m = io.nextInt();
        m += n;
        ans = 0; 
        for (int i = 0; i < MAX; ++i){
            edges[i] = new ArrayList <Integer> (); 
            q[i] = new PriorityQueue <Long> ();
        }
        for (int i = 2; i <= m; i++){
            a = io.nextInt();
            b = io.nextInt();
            edges[(int) a].add(i);
            plague[i] = b;
            ans += b;
        }
        System.out.println(ans);
        
        dfs(1);
       
        System.out.println(a + " " + b);

        long tmp = q[(int)root[1]].poll();
        a = q[(int)root[1]].peek();
        q[(int)root[1]].add((long) 0);
        b = 0;
        
        while (q[(int) root[1]].size() > 0){
            ans -= (a - q[(int) root[1]].peek()) * b;
            b++;
            a = q[(int) root[1]].poll();
        }
        System.out.println(ans);
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

        public static void swap(int data[], int left, int right) {
            int temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }

        public static void reverse(int data[], int left, int right){
            while (left < right) {
                int temp = data[left];
                data[left++] = data[right];
                data[right--] = temp;
            }
        }
 
        public static boolean nextPermutation(int data[]){
            if (data.length <= 1)
                return false;
 
            int last = data.length - 2;
            while (last >= 0) {
                if (data[last] < data[last + 1]) 
                    break;
                last--;
         }
            if (last < 0)
                return false;
 
            int nextGreater = data.length - 1;
 
            for (int i = data.length - 1; i > last; i--) {
                if (data[i] > data[last]) {
                    nextGreater = i;
                    break;
                }
            }
 
            swap(data, nextGreater, last);
            reverse(data, last + 1, data.length - 1);
 
            return true;
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






