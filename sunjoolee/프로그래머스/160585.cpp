#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> b;

//이겼는지 안이겼는지 검사
bool getWin(char me){
    //가로 세로
    for(int i = 0; i<3; ++i){
        if((b[i][0] == me)&&(b[i][0] == b[i][1])&&(b[i][1] == b[i][2]))
            return true;
        if((b[0][i] == me)&&(b[0][i] == b[1][i])&&(b[1][i] == b[2][i]))
            return true;
    }
    //대각선
    if((b[0][0] == me)&&(b[0][0] == b[1][1]) && (b[1][1] == b[2][2]))
        return true;
    if((b[0][2] == me)&&(b[0][2] == b[1][1]) && (b[1][1] == b[2][0]))
        return true;
    
    return false;
}

int solution(vector<string> board) {   
    b = board;
    // o선공, x 후공 -> (x의 개수 > o의 개수)인 경우 있을 수 없음
    // o의 개수와 x의 개수 차이 1보다 클 수 없음
    
    // 동시에 둘 다 이길 수 없음
    // o가 이겼다면 x는 둘 수 없음 -> (o의 개수 == x의 개수 + 1)
    // x가 이겼다면 o는 둘 수 없음 -> (x의 개수 == o의 개수)
    
    int o_cnt = 0;
    int x_cnt = 0;
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j){
            if(board[i][j] == 'O') o_cnt++;
            else if(board[i][j] == 'X') x_cnt++;
        }
    }
    //x의 개수 > o의 개수인 경우 불가능
    if(x_cnt > o_cnt) return 0;
    //x의 개수와 o개수의 차이 1보다 클 수 없음
    if((o_cnt - x_cnt) > 1) return 0;
    
    bool o_win = getWin('O');
    bool x_win = getWin('X');
    //cout << o_win << " " << x_win;
    
    //o도 이기고 x도 이긴 경우 -> 불가능
    if(o_win && x_win) return 0;
    //o이 이기고 x가 진 경우
    if(o_win && !x_win) return o_cnt > x_cnt;
    //o이 지고 x가 이긴 경우
    if(!o_win && x_win) return o_cnt == x_cnt;
    
    //o와 x 둘다 이기지 않고, o의 개수와 x의 개수도 적절한 경우
    return 1;
}
