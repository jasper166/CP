/*
 * Outputs random number between 1 and 10^6, inclusive.
 * To generate different values, call "igen.exe" with different parameters.
 * For example, "igen.exe 1" returns 504077, but "igen.exe 3" returns 808747.
 * 
 * It is typical behaviour of testlib generator to setup randseed by command line.
 */

#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 17);
    println(n);

    for (int i = 0; i < n; ++i) {
        cout << rnd.next(-1000000, 1000000) << " \n"[i == n - 1]; 
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j)
            cout << rnd.next(-1000000, 1000000) << " \n"[j == n - 1]; 
    }
}