#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 105;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    
    //각 알파벳을 입력하기 위해 키보드는 눌러야하는 최소 횟수 
    //입력할 수 없는 경우 INF
    vector<int> alpha(27, INF);
    for(int i = 0; i<keymap.size(); ++i){
        for(int j = 0; j < keymap[i].length(); ++j){
            int cur = keymap[i][j] - 'A';
            alpha[cur] = min(alpha[cur], j + 1);
        }
    }
    
    vector<int> answer;
    for(int i = 0; i<targets.size(); ++i){
        int ans = 0;
        bool possible = true;
        for(int j = 0; j<targets[i].length(); ++j){
            int cur = targets[i][j] - 'A';
            //문자를 입력할 수 없는 경우
            if(alpha[cur] == INF){
                answer.push_back(-1);
                possible = false;
                break;
            }
            else ans += alpha[cur];
        }
        if(possible) answer.push_back(ans);
    }
    return answer;
}
