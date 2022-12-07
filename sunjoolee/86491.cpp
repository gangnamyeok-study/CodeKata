#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxW = -1;
    int maxH = -1;
    for(int i = 0; i<sizes.size(); ++i){
        //명함의 긴 면이 Width가 되도록
        if(sizes[i][0] < sizes[i][1]){
            swap(sizes[i][0], sizes[i][1]);
        }
        
        maxW = max(maxW, sizes[i][0]);
        maxH = max(maxH, sizes[i][1]);
    }
    
    return answer = maxW*maxH;
}
