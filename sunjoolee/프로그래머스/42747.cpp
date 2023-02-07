#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    
    int N = citations.size();
    sort(citations.begin(), citations.end());
    
    int answer = 0;
    for(int h = N; h >0; --h ){
        //lowerBound: 같거나 큰 숫자 처음 등장하는 위치
        //h번 이상 인용된 논문의 개수: N - lowerBound
        int lowerBound = lower_bound(citations.begin(), citations.end(), h) - citations.begin();
        if((N - lowerBound) >= h){
            answer = h;
            break;
        }
    }
    return answer;
}
