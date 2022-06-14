// 001 - Yokan Party
/**
 * 「最小値の最大化」は二分探索で解けることが多い
 * 「答えはM以上か？」⇔「K+1個以上の『長さM以上のピース』に分割可能か？」
 */
#include <iostream>
using namespace std;

long long N, K, L;
long long A[1 << 18];

bool solve(long long M)
{
    // K+1個のピースがすべてMより大きいかどうかを
    // 貪欲法で判定
    long long cnt = 0, pre = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (A[i] - pre >= M && L - A[i] >= M)
        {
            cnt += 1;
            pre = A[i];
        }
    }
    if (cnt >= K)
        return true;
    return false;
}

int main()
{
    // 入力
    cin >> N >> L;
    cin >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    // 答えで二分探索
    long long left = -1;
    long long right = L + 1;
    while (right - left > 1)
    {
        long long mid = left + (right - left) / 2;
        if (solve(mid) == false)
            right = mid;
        else
            left = mid;
    }
    cout << left << endl;
    return 0;
}