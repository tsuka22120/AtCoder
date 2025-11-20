// ABC420, problemc


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
    // 問題文を挿入
    ll N, Q;
    cin >> N >> Q;
    vl A(N),B(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    for(int i = 0;i < N;i++){
        cin >> B[i];
    }
    ll out = 0;
    vl minNum(N);
    for(int i = 0;i < N;i++){
        minNum[i] = min(A[i],B[i]);
        out += minNum[i];
    }
    while(Q--){
        char c;
        ll X,V;
        cin >> c >> X >> V;
        if(c == 'A')A[X - 1] = V;
        else B[X - 1] = V;
        out = out + (min(A[X - 1],B[X - 1]) - minNum[X - 1]);
        minNum[X - 1] = min(A[X - 1],B[X - 1]);
        cout << out << endl;
    }
    return 0;
}