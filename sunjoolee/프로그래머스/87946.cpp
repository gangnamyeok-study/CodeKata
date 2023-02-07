#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    queue<pair<int, string>> q;
    string visited = "";
    for(int i = 0; i<dungeons.size(); ++i){
        visited+= "0";
    }
    
    q.push({k, visited});
    while(!q.empty()){
        int curStrength = q.front().first;
        string curVisited = q.front().second;
        q.pop();
        
        int curVisitedCnt = 0;
        for(int i = 0; i<dungeons.size(); ++i){
            if(curVisited[i] == '1') curVisitedCnt++;
        }
        answer = max(answer, curVisitedCnt);
        
        for(int i = 0; i<dungeons.size(); ++i){
            if(dungeons[i][0] <= curStrength){
                if(curVisited[i] == '0'){
                    curVisited[i] = '1';
                    q.push({curStrength - dungeons[i][1], curVisited});
                    curVisited[i] = '0';
                }
            }
        }
    }
    
    return answer;
}
