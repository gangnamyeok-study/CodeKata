#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    
    //높이 1에서부터 시작하여 한 층씩 내려감 (루트 높이 생략)
    //현재 높이 h의 모든 위치 검사
    //그 위치까지 이동할 수 있는 방법들 중 가장 합이 큰 방법 구하기 = triangle에 저장
    for(int h = 1; h<triangle.size(); ++h){
        for(int i = 0; i<triangle[h].size(); ++i){
            int maxSum = triangle[h][i];
            //왼쪽 부모에서 내려오는 경우
            if(i > 0){
                maxSum = max(maxSum, triangle[h][i]+triangle[h-1][i-1]);
            }
            //오른쪽 부모에서 내려오는 경우
            if(i<triangle[h].size()-1){
                maxSum = max(maxSum, triangle[h][i]+triangle[h-1][i]);
            };
            
            //triangle[h][i]에 그 위치까지 이동할 수 있는 방법들 중 가장 합이 큰 방법 저장
            triangle[h][i] = maxSum;
            //cout << maxSum<<" ";
        }
        //cout << "\n";
    }
    
    int answer = 0;
    for(auto it = triangle.back().begin(); it != triangle.back().end(); ++it){
        answer = max(answer, *it);
    }
    return answer;
}
