#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    //현재 다리 위에 있는 트럭(트럭의 무게 삽입)
    queue<int> q;
    //q에 공백 삽입
    for(int i=0; i<bridge_length; ++i){
        q.push(0);
    }
    
    //현재 다리 위에 있는 트럭들의 무게 합
    int totalW = 0;
    //건넌 트럭의 수
    int cnt = 0;
    //다음으로 건널 트럭의 인덱스
    int idx = 0;
    
    //모든 트럭이 다리를 건널 때까지 loop
    while(cnt < truck_weights.size()){
        answer++;
        
        //q의 맨 앞이 공백이 아닌 경우 트럭이 다리를 건넌 것
        if(q.front() != 0){
            cnt++;
            totalW -= q.front();
        }
        q.pop();
        
        //다리 위에 다음 트럭이 올라갈 수 있는 경우 올라가기
        if(totalW + truck_weights[idx] <= weight){
            q.push(truck_weights[idx]);
            totalW += truck_weights[idx];
            idx++;
        }
        //올라갈 수 없는 경우 공백 삽입
        else{
            q.push(0);
        }
    }
    return answer;
}
