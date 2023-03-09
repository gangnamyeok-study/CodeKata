#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    sort(section.begin(), section.end());
    
    int rollerEnd = 0; //롤러의 우측 끝 위치
    for(int i = 0; i<section.size(); ++i){
        //이미 롤러가 칠한 위치
        if(section[i] <= rollerEnd) continue; 
        //롤러가 새로 칠해야 할 위치
        if(section[i] > rollerEnd){
            rollerEnd = section[i] + m - 1;
            answer++;
        }
    }
    return answer;
}
