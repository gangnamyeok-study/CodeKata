#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;
const ll M = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    //isPuddle[i][j]: 좌표(i, j)가 물에 잠겼는지 아닌지
    vector<vector<int>> isPuddle(n, vector<int>(m, 0));
    for(int i = 0; i<puddles.size(); ++i){
        isPuddle[puddles[i][1]-1][puddles[i][0]-1] = 1;
    }
    
    //n*m개의 모든 좌표의 정보 유지할 필요 없음
    //현재 구하고자하는 좌표의 정보 downPathCnt
    //현재 구하고자하는 좌표의 한 칸 위 정보 upPathCnt
    vector<ll> upPathCnt(m,0);
    vector<ll> downPathCnt(m,0);
    
    //(0, 0)부터 경로 시작
    upPathCnt[0] = 1;
    for(int i = 1; i<m; ++i){
        //좌표 (0, i)까지 이동할 수 있는 경로의 수 계산
        //현재 좌표 물에 잠긴 경우 경로 0개
        if(isPuddle[0][i]){
                upPathCnt[i] = 0; 
                continue;
        }
        
        //왼쪽에서 현재 좌표까지 온 경우
        upPathCnt[i] += upPathCnt[i-1];
        upPathCnt[i] %= M;
    }
    
    //높이 1부터 좌표 경로 정보 구하기 시작
    //높이 h-1인 좌표의 경로 정보 upPathCnt에 저장되어있음
    //현재 높이 h인 좌표의 경로 정보 downPathCnt에 저장할 것
    for(int h = 1; h<n; ++h){
        //좌표 (h, i)까지 이동할 수 있는 경로의 수 계산
        for(int i = 0; i<m; ++i){
            //현재 좌표 물에 잠긴 경우 경로 0개
            if(isPuddle[h][i]){
                downPathCnt[i] = 0; 
                continue;
            }
        
            //왼쪽에서 현재 좌표까지 온 경우
            if(i>0){
                downPathCnt[i] += downPathCnt[i-1];
                downPathCnt[i] %= M;
            }
        
            //위쪽에서 현재 좌표까지 온 경우
            downPathCnt[i] += upPathCnt[i];
            downPathCnt[i] %= M;
        }
        
        upPathCnt.clear();
        upPathCnt.assign(downPathCnt.begin(), downPathCnt.end());
        
        downPathCnt.clear();
        downPathCnt = vector<ll>(m, 0);
    }
        
    int answer = upPathCnt[m-1];
    return answer;
}
