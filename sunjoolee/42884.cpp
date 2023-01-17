#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    //시작 지점, 차량 번호
    vector<pair<int, int>> roadIn;
    //나간 지점, 차량 번호
    vector<pair<int, int>> roadOut;
    
    for(int i = 0; i < routes.size(); ++i){
        roadIn.push_back({routes[i][0], i});        
        roadOut.push_back({routes[i][1], i});
    }
    
    //시작 지점, 나간 지점 오름차순 정렬
    sort(roadIn.begin(), roadIn.end());
    sort(roadOut.begin(), roadOut.end());
    
    vector<bool> passing(routes.size(), false);
    vector<bool> camera(routes.size(), false);
    
    int answer = 0;
    int inIdx = 0; //roadIn 인덱스
    int outIdx = 0; //roadOut 인덱스
  
    while(outIdx < routes.size()){
        int outPos = roadOut[outIdx].first;
        
        //현재 지점이 진입 지점인 차량 확인
        if(inIdx < routes.size()){
            int inPos = roadIn[inIdx].first;
            if(inPos <= outPos){
                passing[roadIn[inIdx].second] = true;
                inIdx++;
                continue;
            }
        }
        
        //현재 지점이 진입 지점인 차량 확인
        //이미 단속 카메라 한번 만났을 경우
        if(camera[roadOut[outIdx].second]){
                //빠져나오기
                passing[roadOut[outIdx].second] = false;
        }
        //만나지 않은 경우 현재 지점에 카메라 설치
        else{
                answer++;
                //현재 지점을 지나가고 있는 모든 차량 camera = true
                for(int j = 0; j<routes.size(); ++j){
                    if(passing[j]) camera[j] = true;
                }
                //빠져나오기
                passing[roadOut[outIdx].second] = false;
        }
        outIdx++;
    }
    return answer;
}
