#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";

    if(s.length()%2 == 1) //글자수가 홀수
    {
        answer = s[s.length()/2];
    }
    else                  //글자수가 짝수
    {
        answer += s[s.length()/2 - 1];
        answer += s[s.length()/2];
    }
    return answer;
}

int main(void)
{
    string str;
    cin >> str;

    cout << solution(str) << endl;

    return 0;
}