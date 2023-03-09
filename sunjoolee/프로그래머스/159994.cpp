#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    
    int idx1 = 0;
    int idx2 = 0;
    for(int i = 0; i<goal.size(); ++i){
        //카드 뭉치 1에서 가져올 수 있는 경우
        if((idx1 != cards1.size()) &&(cards1[idx1] == goal[i])){
            idx1++;
            continue;
        }
        //카드 뭉치 2에서 가져올 수 있는 경우
        if((idx2 != cards2.size())&&(cards2[idx2] == goal[i])){
            idx2++;
            continue;
        }
        //불가능
        return "No";
    }
    //가능
    return "Yes";
}
