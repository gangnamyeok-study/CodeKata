#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>

using namespace std;

int main(int argc, char** argv){
	int T;
	cin>>T;
	
	for(int test_case = 1; test_case <= T; ++test_case){
		int N, K;
        cin >> N >> K;
        
        string input;
        cin >> input;
        
        //input 문자열 4등분 -> 사각형의 네 변
        int pwLen = N/4;
        vector<string> fourSides;
        fourSides.push_back(input.substr(0, pwLen));
        fourSides.push_back(input.substr(pwLen, pwLen));
        fourSides.push_back(input.substr(pwLen * 2, pwLen));
        fourSides.push_back(input.substr(pwLen * 3, pwLen));
        
        //만들 수 있는 모든 비밀번호 집합
        set<string> pwSet;
        for(int i = 0; i<4; ++i){
        	pwSet.insert(fourSides[i]);
        }
        
        //pwLen-1만큼 사각형의 네 변 회전 가능
        for(int i = 0; i<pwLen; ++i){
            //꼬리 떼기
            vector<char>tails;
            for(int j = 0; j<4; ++j){
            	tails.push_back(fourSides[j][pwLen-1]);
                fourSides[j] = fourSides[j].substr(0, pwLen-1);
            }
            //꼬리 머리에 붙이기
           for(int j = 0; j<4; ++j){
               if(j == 0){
           	   		fourSides[j] = tails[3] + fourSides[j];
               }
               else{
           			fourSides[j] = tails[j-1] + fourSides[j];
               }
           }
           //회전 후 비밀번호 집합에 추가
           for(int j = 0; j<4; ++j){
        		pwSet.insert(fourSides[j]);
       		}
        }
        
        //K번째로 큰 비밀번호 정렬 이용하여 구하기
        vector<string> pwVec(pwSet.begin(), pwSet.end());
        string answerPw = pwVec[pwVec.size() - K];
 		//cout << answerPw <<"\n";
        
        //16진수 -> 10진수
        int answer = 0;
        int digit = 0;
        for(int i = pwLen-1; i >= 0; --i){
            int n = answerPw[i] - '0';
        	if(answerPw[i] == 'A') n= 10;
        	else if(answerPw[i] == 'B') n = 11;
        	else if(answerPw[i] == 'C') n = 12;
        	else if(answerPw[i] == 'D') n = 13;
        	else if(answerPw[i] == 'E') n = 14;
        	else if(answerPw[i] == 'F') n = 15;
            
            answer += (pow(16,digit) * n) ;
            digit++;
        }
        
        cout <<"#"<<test_case<<" "<<answer<<"\n";
	}
	return 0;
}
