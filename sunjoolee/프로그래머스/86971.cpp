#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int adj[101][101] = {0};

//방문한 노드의 수 반환
int bfs(int start){
    int cnt = 0;
    
    vector<int> visited(N, 0);
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(visited[cur]) continue;
        visited[cur] = 1;
        cnt++;
        
        for(int next = 0; next<N; ++next){
            if(adj[cur][next] == 0) continue;
            if(visited[next]) continue;
            
            q.push(next);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    N = n;
    
    for(int i =0; i<wires.size(); ++i){
        int a = wires[i][0]-1;
        int b = wires[i][1]-1;
        
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    int minDiff = 101;
    for(int i = 0; i<wires.size(); ++i){
        //i번 와이어를 끊었을 때 두 전력망의 개수의 차이 구하기
        int a = wires[i][0]-1;
        int b = wires[i][1]-1;
        
        adj[a][b] = 0;
        adj[b][a] = 0;
        int diff = abs(bfs(a) - bfs(b));
        adj[a][b] = 1;
        adj[b][a] = 1;
        
        minDiff = min(minDiff, diff);
    }
    
    int answer = minDiff;
    return answer;
}
