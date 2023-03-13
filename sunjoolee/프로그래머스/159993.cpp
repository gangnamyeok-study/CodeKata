#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<string> board;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

bool inRange(int r, int c){
    if(r < 0 || r >= N) return false;
    if(c < 0 || c >= M) return false;
    return true;
}

int minPath(pair<int, int> start, pair<int, int> end){
    priority_queue<pair<int, pair<int, int>>> pq;
    int visited[101][101] = {0};
    
    pq.push({0, start});
    while(!pq.empty()){
        int curPath = -pq.top().first;
        pair<int, int> curPair = pq.top().second;
        pq.pop();
        
        if(curPair == end) return curPath;
        
        if(visited[curPair.first][curPair.second]) continue;
        visited[curPair.first][curPair.second] = 1;
        
        for(int d = 0; d<4; ++d){
            pair<int, int> nextPair = {curPair.first + dirR[d], curPair.second + dirC[d]};
            
            if(!inRange(nextPair.first, nextPair.second)) continue;
            if(visited[nextPair.first][nextPair.second]) continue;
            if(board[nextPair.first][nextPair.second] == 'X') continue;
            
            pq.push({-(curPath + 1), nextPair});
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].length();
    
    board.clear();
    board = maps;
    
    pair<int, int> start;
    pair<int, int> mid;
    pair<int, int> end;
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<M; ++j){
            if(board[i][j] == 'S') start = {i,j};
            if(board[i][j] == 'L') mid = {i,j};
            if(board[i][j] == 'E') end = {i,j};
        }
    }
    
    int result1 = minPath(start, mid);
    if(result1 == -1) return -1;
    
    int result2 = minPath(mid, end);
    if(result2 == -1) return -1;
    
    return result1 + result2;
}
