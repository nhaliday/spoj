#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef ull num;

const int MAXT = 50, MAXN = 200005;
int T, N, K;
num A[MAXN], B[MAXN];

inline int mod(int i, int m) {
    return (i%m+m)%m;
}

ifstream fin("andround.in");
ofstream fout("andround.out");

void solve(int t) {
    fin >> N >> K;
    for (int i = 0; i < N; ++i)
        fin >> A[i];
    copy(A, A+N, B);
    for (int k = 0; k < K; ++k) {
        copy(B, B+N, A);
        for (int i = 0; i < N; ++i) {
            B[i] = A[mod(i - 1, N)] & A[i] & A[mod(i + 1, N)];
        }
    }
}

int main() {
    fin >> T;
    for (int t = 0; t < T; ++t) {
        solve(t);
        fout << B[0];
        for (int i = 1; i < N; ++i)
            fout << ' ' << B[i];
        fout << '\n';
    }

    fout << flush;
    return 0;
}
