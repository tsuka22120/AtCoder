// ABC420, problemb

#ifndef ONLINE_JUDGE
//#define _GLIBCXX_DEBUG  //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意
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
    // 問題文を挿入
    int N,M;
    cin >> N >> M;
    vs S(N);
    vl score(N);
    for(int i = 0;i < N;i++){
        cin >> S[i];
    }
    for(int i = 0;i < M;i++){
        int cntZero = 0,cntOne = 0;
        for(int j = 0;j < N;j++){
            if(S[j][i] == '0')cntZero++;
            else cntOne++;
        }
        if(cntZero == 0 || cntOne == 0){
            for(int j = 0;j < N;j++)score[j]++;
        }else if(cntZero > cntOne){
            for(int j = 0;j < N;j++){
                if(S[j][i] == '1')score[j]++;
            }
        }else{
            for(int j = 0;j < N;j++){
                if(S[j][i] == '0')score[j]++;
            }
        }
    }
    ll cntMax = *max_element(score.begin(),score.end());
    for(int i = 0;i < N;i++){
        if(score[i] == cntMax)cout << i + 1 << " ";
    }
    return 0;
}