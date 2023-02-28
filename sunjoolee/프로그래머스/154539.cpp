#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int N = numbers.size();
    vector<int> answer(N, -1);
    
    stack<pair<int, int>> st;
    
    for(int i = 0; i<N; ++i){
        while(!st.empty() && (st.top().first < numbers[i])){
            answer[st.top().second] = numbers[i];
            st.pop();
        }
        st.push({numbers[i], i});
    }
    /*
    while(!st.empty()){
        answer[st.top().second] = -1;
        st.pop();
    }
    */
    return answer;
}
