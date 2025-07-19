#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG  //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意
                        // ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

#define PRINT_VAR(x)  // 変数名を出力

template <typename T>
using vc = vector<T>;  // prioriy_queueに必要なのでここにこれ書いてます
template <typename T>
using vv = vc<vc<T>>;

//-------------1.型系---------------
using ll = long long;
ll INF = 2e18;

using ld = long double;

template <class T>
using pq = priority_queue<T, vc<T>>;  // 大きい順
template <class T>
using pq_g = priority_queue<T, vc<T>, greater<T>>;  // 小さい順

//-------------2.配列系--------------
using vl = vc<ll>;
using vvl = vv<ll>;
using vvvl = vv<vl>;
using vvvvl = vv<vvl>;
using vs = vc<string>;
using vvs = vv<string>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vector<pair<ll,ll>> A(M);
    for(int i = 0; i < M; ++i) {
        cin >> A[i].first >> A[i].second;
    }

    // costが小さい順にソート
    sort(A.begin(), A.end(), [](auto& a, auto& b){
        return a.first < b.first;
    });

    priority_queue<ll> pq; // 獲得スタミナ gain が大きい順
    ll ans = 0;
    int idx = 0;

    while (true) {
        // cost <= N なメニューを全部ヒープへ追加
        while (idx < M && A[idx].first <= N) {
            pq.push(A[idx].second);
            idx++;
        }
        if (pq.empty()) break;

        // 最大 gain を選んで実行
        ll gain = pq.top(); pq.pop();
        N += gain;
        ans++;
        // メニューは何度でも使えるので、もう一度ヒープへ戻す
        pq.push(gain);
    }

    cout << ans << "\n";
    return 0;
}