#include <iostream>

#include "testlib.h"

#define free                                                   \
    freopen("/workspaces/CP/TestGen/output.txt", "w", stdout); \
    freopen("/workspaces/CP/TestGen/error.txt", "w", stderr);

using namespace std;

int main(int argc, char* argv[]) {
    free

        int n;
    cin >> n;

    registerGen(argc, argv, 1);
    // rnd.next(1, n)

    cout << n << " " << n << endl;
    for (int i = 0; i < n; i++) cout << rnd.next(0, 1);
    cout << endl;
    for (int qq = 0; qq < n; qq++) {
        int qType = rnd.next(1, 3);
        int l = rnd.next(1, n);
        int r = rnd.next(1, n);
        if (l > r) swap(l, r);
        cout << qType << " " << l << " " << r << endl;
    }

    return 0;
}