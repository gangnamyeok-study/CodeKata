#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int COL;
bool cmp(const vector<int>& a,const vector<int>& b){
    if(a[COL-1] < b[COL-1]) return true;
    if(a[COL-1] > b[COL-1]) return false;
    return (a[0] > b[0]);
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    COL = col;
    
    sort(data.begin(), data.end(), cmp);
    
    vector<int> S_i;
    for(int i = 0; i<data.size(); ++i){
        int sum = 0;
        for(int j = 0; j<data[i].size(); ++j){
            sum += (data[i][j] % (i+1));
        }
        S_i.push_back(sum);
    }
    
    int answer = S_i[row_begin-1];
    for(int i = row_begin; i<row_end; ++i){
        answer = answer ^ S_i[i];
    }
    return answer;
}
