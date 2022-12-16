#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //카펫 크기 = r * w
    //노랑 = (r-2)*(w-2)
    //갈색 = (r*w) - 노랑
    
    //노랑 세로 i = r-2
    //노랑 가로 j = w-2
    for(int i = 1; i <= 2000000; ++i){
        for(int j = i; j <= 2000000; ++j){
            if((i * j) > yellow) break;
            if((i * j) < yellow) continue;
            
            if(((i+2)*(j+2) - (i*j)) == brown){
                answer.push_back(j+2); //가로
                answer.push_back(i+2); //세로
                return answer;
            }
        }
    }
    return answer;
}
