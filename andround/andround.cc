#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef int num;

#define pw(i) (1<<(i))

const int MAXT = 50, MAXN = 200005, MAXLOGA = 32;
int T, N, K;
num A[3 * MAXN], B[MAXN], psum[MAXLOGA][3 * MAXN];
int loga;

ifstream fin("andround.in");
ofstream fout("andround.out");

inline num q(int b, int i, int j) {
    return psum[b][j + N] - psum[b][i + N];
}

bool on(int b, int i) {
    int k = K;
    if (2 * k + 1 >= N)
        k = N / 2;
    int x = i - k, y = i + k + 1;
    return q(b, x, y) == y - x;
}

void solve(int t) {
    fin >> N >> K;
    for (int i = 0; i < N; ++i)
        fin >> A[i];
    copy(A, A+N, A+N);
    copy(A, A+N, A+2*N);

    int ma = *max_element(A, A+N);
    for (loga = 0; pw(loga) <= ma; ++loga);
    for (int b = 0; b < loga; ++b)
        for (int i = 0; i < 3 * N; ++i)
            psum[b][i + 1] = psum[b][i] + ((pw(b)&A[i])!=0);

    for (int b = 0; b < loga; ++b)
        for (int i = 0; i < N; ++i)
            if (on(b, i))
                B[i] |= pw(b);
}

int main() {
    fin >> T;

    for (int i = 0; i < T; ++i) {
        solve(i);
        fout << B[0];
        for (int j = 1; j < N; ++j)
            fout << ' ' << B[j];
        fout << '\n';
    }

    fout << flush;
    return 0;
}
