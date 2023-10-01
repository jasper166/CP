import java.io.*;
import java.util.*;
// @Jasper

public class Template {
    static long LINF = (long) 1e18 + 5;
    static int INF = (int) 1e9 + 5;
    static int MOD = (int) 1e9 + 7;
    static int MAX = (int) 1e5 + 5;



    //------------------Solution------------------------------------------------  
    private static void run_case() throws Exception {
        int [] per = new int [5];
        for (int i = 0; i < 5; i++) per[i] = i;
        do {
            for (int i = 0; i < 5; i++) System.out.print(per[i] + " ");
            System.out.println();
        }
        while (nextPermutation(per));

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


VÍ DỤ VỀ QUY HOẠCH ĐỘNG THÔNG QUA BÀI TOÁN  - XÂU CON CHUNG DÀI NHẤT
------
Đây là một bài toán kinh điển trong CP, được ứng dụng rộng rãi trong nhiều trường hợp. VD: là cơ sở của tính năng Diff trong Khoa học máy tính(việc so sánh sự khác biệt giữa hai files), áp dụng vào trong Tin sinh học (Bioinformatics) và Ngôn ngữ học tính toán (Computational Linguistics).

Bài toán này có nhiều cách giải khác nhau, nhưng điểm chung của chúng là đều sử dụng DP và trong bài viết này, MeLy giới thiệu đến cậu một số hướng giải và tối ưu. Hy vọng sẽ có ích với cậu!


