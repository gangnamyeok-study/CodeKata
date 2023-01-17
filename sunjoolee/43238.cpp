#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

long long N;
vector<long long> Times;

//x시간 안에 n명의 사람들이 입국 심사를 마칠 수 있는가?
bool decision(long long x){
    long long cnt = 0;
    for(long long i = 0; i<Times.size(); ++i){
        cnt += (x/Times[i]);
        if(cnt >= N) return true;
    }
    return false;
}

long long solution(int n, vector<int> times) {
    
    N = n;
    Times.clear();
    Times.assign(times.begin(), times.end());
    //심사 시간 적게 걸리는 순으로 정렬
    sort(Times.begin(), Times.end());
    
    long long lo = 1;
    long long hi = N * Times.back();
    while(lo + 1 < hi){
        long long mid = (lo + hi)/2;
        if(decision(mid)) hi = mid;
        else lo = mid;
    }
    long long answer = hi;
    return answer;
}
