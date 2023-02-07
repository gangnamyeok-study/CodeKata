#include <string>
#include <queue>
#include<map>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    
    //<만든 num, 사용한 N의 최소 개수>
    map<int, int> cntMap;
    
    //<지금까지 사용한 N의 수, 만든 num>
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({1, N});
    
    while(!q.empty()){
        int curCnt = q.front().first;
        int curNum = q.front().second;
        q.pop();
        
        if(curCnt > 8) continue;
        
        if(cntMap.find(curNum) != cntMap.end())
            cntMap[curNum] = min(cntMap[curNum], curCnt);
        else cntMap[curNum] = curCnt;
        
        int operand = N;
        for(int digit = 1; digit <= 8; ++digit){
            q.push({curCnt + digit, curNum + operand});
            q.push({curCnt + digit, curNum - operand});
            q.push({curCnt + digit, curNum * operand});
            q.push({curCnt + digit, curNum / operand});
                
            operand *= 10;
            operand += N;
        }
    }
    
    int answer = -1;
    if(cntMap.find(number) != cntMap.end()) {
        answer = cntMap[number];
        if(answer > 8) answer = -1;
    }
    return answer;
}
