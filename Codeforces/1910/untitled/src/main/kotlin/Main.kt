fun main() {
    val T = readInt();
    for (_t in 0 until T) {
        val s = readLn();
        var a = IntArray(s.length);
        // keep the prefix >= 0
        var plus = 0;
        var minus = 0;
        for (i in 0 until s.length) {
            if (s[i] == '-') {
                ++minus;
                a[i] = -1;
            };
            else {
                ++plus;
                a[i] = 1;
            };
        }
        if (minus > plus) println(-1);
        else {
            var prf = 0;
            var l = -1;
            var r = -1;
            for (i in 0 until s.length) {
                prf += a[i];
                if (prf < 0 && l == -1) {
                    l = i;
                }
                if (a[i] == 1) r = i;
            }
            // plausible
            if (l == -1) println("1 1");
            else if (r == -1) println("-1");
            else {
                if (l < r) {
                    a[l] = 1;
                    a[r] = -1;
                }
                var prf = 0;
                var ans = 1;
                for (i in 0 until s.length) {
                    prf += a[i];
                    if (prf < 0) {
                        ans = 0;
                    }
                }
                if (ans == 1) println("${l + 1} ${r + 1}");
                else println("-1");
            }
        }
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() }  // list of doubles
