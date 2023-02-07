#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long priceSum = 0;
    for(int i = 1; i<=count; ++i){
        priceSum += (price * i);
        cout << priceSum<<" ";
    }
    
    answer = priceSum - money;
    if(answer < 0) answer = 0;
    return answer;
}
