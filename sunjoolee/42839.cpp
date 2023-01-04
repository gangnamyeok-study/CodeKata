#include <string>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

string globalnumbers;
set<int> primeNums;

bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i<= sqrt(num); ++i){
        if((num%i) == 0) return false;
    }
    return true;
}

void makeNums(int startidx, string num){    
    if(num != ""){
        sort(num.begin(), num.end());
        do{
            int numInt = stoi(num);
            if(primeNums.find(numInt) != primeNums.end()) continue;
            
            if(isPrime(numInt)){
                cout << numInt <<"\n";
                primeNums.insert(numInt);
            }
        }while(next_permutation(num.begin(), num.end()));
    }
    if(startidx == globalnumbers.length()) return;
    
    //현재 숫자 선택하지 않는 경우
    makeNums(startidx + 1, num);
    //현재 숫자 선택하는 경우
    makeNums(startidx + 1, num + globalnumbers[startidx]);
}

int solution(string numbers) {
    globalnumbers.assign(numbers);
    
    makeNums(0,"");
    
    int answer = primeNums.size();
    return answer;
}
