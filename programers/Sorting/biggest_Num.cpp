#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) //두 개를 더해서 큰 쪽을 반환
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> numToStr; //숫자를 string으로 변환하여 저장
    for(int i=0;i<numbers.size();i++)
    {
        numToStr.push_back(to_string(numbers[i]));
    }

    sort(numToStr.begin(), numToStr.end(),cmp);

    for(int i=0;i<numToStr.size();i++)
    {
        answer += numToStr[i];
    }

    if(answer[0] == '0')
    {
        answer = "0";
    }

    return answer;
}

int main(void)
{
    vector<int> numbers;
    numbers.push_back(0);
    numbers.push_back(0);
    numbers.push_back(0);
    
    cout << solution(numbers) << endl;

    return 0;
}