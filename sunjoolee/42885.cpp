#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //사람들 무게 오름차순 정렬
    sort(people.begin(), people.end());
    //사람들 무게 deque로 이동
    //양방향 pop 연산을 사용하기 위함
    deque<int> pp;
    for(int i = 0; i<people.size(); ++i){
        pp.push_back(people[i]);
    }
    
    while(!pp.empty()){
        //보트에 가장 무거운 사람 태우기
        int boat = pp.back();
        pp.pop_back();
        answer++;
        
        //보트 무게 제한이 허락하는 데까지 가장 가벼운 사람 태우기
        while((!pp.empty()) && (boat + pp.front() <= limit)){
            boat += pp.front();
            pp.pop_front();
        }
    }
    return answer;
}
