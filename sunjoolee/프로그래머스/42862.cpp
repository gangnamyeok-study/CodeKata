#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N; //학생 수
vector<int> stat; //학생 체육복 현황

int maxAnswer = 0;

//startIdx부터 체육복이 없는 학생 탐색 시작
void lend(int startIdx){
    
    //startIdx 이후 체육복 없는 학생 찾기
    int noSuitIdx = -1;
    for(int i = startIdx; i<N; ++i){
        if(stat[i] == 0){
            noSuitIdx = i;
            break;
        }
    }
    
    //체육복 없는 학생 더이상 없는 경우
    if(noSuitIdx == -1){
        //체육시간에 참여할 수 있는 학생 수
        int answer = 0;
        for(int i = 0; i<N; ++i){
            if(stat[i] >= 1) answer++;
        }
        maxAnswer = max(maxAnswer, answer);
        return;
    }
    
    //체육복 빌리지 않고 그냥 넘어가는 경우
    lend(noSuitIdx+1);
        
    //체육복 없는 학생 앞 사람한테 빌리는 경우
    if((noSuitIdx > 0) && (stat[noSuitIdx - 1] == 2)){
        stat[noSuitIdx - 1] = 1;
        stat[noSuitIdx] = 1;
        
        //다음 인덱스부터 탐색 재개
        lend(noSuitIdx+1);
        
        stat[noSuitIdx - 1] = 2;
        stat[noSuitIdx] = 0;
    }
    //체육복 없는 학생 뒷 사람한테 빌리는 경우
    if((noSuitIdx < N-1) && (stat[noSuitIdx + 1] == 2)){
        stat[noSuitIdx + 1] = 1;
        stat[noSuitIdx] = 1;
        
        //다음 인덱스부터 탐색 재개
        lend(noSuitIdx+1);
        
        stat[noSuitIdx + 1] = 2;
        stat[noSuitIdx] = 1;
    }
    return;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    N = n;
    for(int i = 0; i<n; ++i){
        stat.push_back(1);
    }
    for(int i = 0; i<lost.size(); ++i){
        stat[lost[i]-1]--;
    }
    for(int i = 0; i<reserve.size(); ++i){
        stat[reserve[i]-1]++;
    }
    
    for(int i = 0; i<N; ++i){
        if(stat[i] >= 1) maxAnswer++;
    }
    lend(0);
    
    int answer = maxAnswer;
    return answer;
}
