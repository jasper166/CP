import java.util.Scanner;
import javax.swing.JOptionPane;

public class solve {
    public static void main(String [] args) {
        // JOptionPane gui;
        // String name = gui.showInputDialog("Your name?");
        // gui.showMessageDialog(null, "Hello " + name);

        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int test = 1; test <= t; test++) {
            solveEach();
        }

    } 
    private static void solveEach(){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int l = scan.nextInt();
        int r = scan.nextInt();
        String ans = "YES";
        int ret[] = new int[n + 1];
        for (int i = 1; i <= n; i++){
            if (((l - 1) / i + 1) <= r / i){
                ret[i] = ((l - 1) / i + 1) * i;
                // System.out.println(ret[i]);
            }
            else {
                ans = "NO";
                break;
            }
        }
        System.out.println(ans);
        if (ans == "YES"){
            for (int i = 1; i <= n; i++){
                System.out.println(ret[i] + " ");
            }
        }
    }
}