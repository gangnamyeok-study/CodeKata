#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    //1번 1 2 3 4 5 1 2 3 4 5    
    //1 2 3 4 5 반복
    vector<int> vec1;
    while(vec1.size() < answers.size()){
        vec1.push_back(1);
        vec1.push_back(2);
        vec1.push_back(3);
        vec1.push_back(4);
        vec1.push_back(5);
    }
    
    //2번 2 1 2 3 2 4 2 5 2 1 2 1
    //2 사이에 2를 제외한 숫자 1번씩
    vector<int> vec2;
    vec2.push_back(2);
    while(vec2.size() < answers.size()){
        for(int i = 1; i<= 5; ++i){
            if(i == 2) continue;
            vec2.push_back(i);
            vec2.push_back(2);
        }
    }
    
    //3번 3 3 1 1 2 2 4 4 5 5 3 3 1 1 2 2 4 4 5 5 
    //3 2번
    //3 제외한 숫자 2번씩
    vector<int> vec3;
    while(vec3.size() < answers.size()){
        vec3.push_back(3);
        vec3.push_back(3);
        for(int i = 1; i<= 5; ++i){
            if(i == 3) continue;
            vec3.push_back(i);
            vec3.push_back(i);
        }
    }
    
    int correct1 = 0;
    int correct2 = 0;
    int correct3 = 0;
    for(int i = 0; i<answers.size(); ++i){
        if(answers[i] == vec1[i]) correct1++;
        if(answers[i] == vec2[i]) correct2++;
        if(answers[i] == vec3[i]) correct3++;
    }
    
    int maxCorrect = max(correct1, max(correct2, correct3));
    if(correct1 == maxCorrect) answer.push_back(1);
    if(correct2 == maxCorrect) answer.push_back(2);
    if(correct3 == maxCorrect) answer.push_back(3);
    
    return answer;
}
