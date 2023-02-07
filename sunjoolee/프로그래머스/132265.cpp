#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    
    //map<topping 번호, topping 개수>
    map<int, int> cake1;
    map<int, int> cake2;
    
    int N = topping.size();
    
    //첫번째 조각 X, 두번째 조각 0~N-1 로 시작
    for(int i = 0; i< N; ++i){
        if(cake2.find(topping[i]) == cake2.end()){
            cake2[topping[i]] = 1;
        }
        else{
            cake2[topping[i]] = cake2[topping[i]] + 1;
        }
    }
    
    // cout << "cake2: ";
    // for(auto it = cake2.begin(); it!=cake2.end(); ++it){
    //     cout << "<"<<it->first<<","<<it->second<<"> ";
    // }
    // cout << "\n\n";
    
    int answer = 0;
    
    //첫번째 조각 0~i, 두번째 조각 i+1~N-1
    for(int i = 0; i<N-1; ++i){
        //i번째 토핑 두번째 조각에서 삭제
        cake2[topping[i]] = cake2[topping[i]] - 1;
        //토핑 개수 0개면 토핑 가짓수 줄이기 위해 map에서 삭제
        if(cake2[topping[i]] == 0){
            auto it = cake2.find(topping[i]);
            cake2.erase(it);
        }
        //i번째 토핑 첫번째 조각에 추가
        if(cake1.find(topping[i])==cake1.end()){
            cake1[topping[i]] = 1;
        }
        else cake1[topping[i]] = cake1[topping[i]] + 1;
        
        // cout << "cake1: ";
        // for(auto it = cake1.begin(); it!=cake1.end(); ++it){
        //     cout << "<"<<it->first<<","<<it->second<<"> ";
        // }
        // cout << "\n";
        // cout << "cake2: ";
        // for(auto it = cake2.begin(); it!=cake2.end(); ++it){
        //     cout << "<"<<it->first<<","<<it->second<<"> ";
        // }
        // cout << "\n\n";
        
        //첫번째 조각과 두번째 조각 토핑 가짓수 같은지 비교
        if(cake1.size() == cake2.size()) answer++;
    }
    
    return answer;
}

