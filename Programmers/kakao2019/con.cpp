#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string change = "";

//
// 올바른 괄호 문자열인지 확인
//
bool checkString(string _p)
{
    stack<int> s;

    for(int i=0;i<_p.length();i++)
    {
        if(_p[i] == '(')
        {
            s.push(1);
        }
        else if(_p[i] == ')')
        {
            if(s.empty())
            {
                return false;
            }
            s.pop();
        }   
    }
    return true;
}

// 
// 주어진 문자열을 u와 v로 나눠주고, 균형잡힌 괄호 문자열인 u에 대해서 재귀함수를 수행
// ch : v
// return : 더해진 문자열을 반환
//
void changeString(string ch) 
{
    //cout << "This is input : " << ch << endl;
    string u = "";
    string v = "";
    int cnt = 0;
    
    // 1. u와 v를 나눈다.
    if(ch[0] == '(')
    {
        cnt += 1;
        u += "(";
    }
    else if(ch[0] == ')')
    {
        cnt -= 1;
        u += ")";
    }
    else
    {
        return;
    }

    for(int i=1;i<ch.length();i++)
    {
        if(cnt == 0)
        {
            v += ch[i];
        }
        else
        {
            if(ch[i] == '(')
            {
                cnt += 1;
                u += "(";
            }
            else if(ch[i] == ')')
            {
                cnt -= 1;
                u += ")";
            }
        }
    }
    //cout << "u is " << u << " & v is " << v << endl;
    // 2. u를 확인한다.
    if(checkString(u)) // 2-1. u가 올바른 괄호 문자열이라면, v에 대해서 재귀적으로 처리
    {
        change += u;
        
        changeString(v);
    }
    else // 2-2. u가 균형잡힌 괄호 문자열이라면, u에 대해 올바른 괄호 문자열로 만든 후, v에 대해서 재귀적으로 처리
    {
        //3-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
        change += "(";
        //3-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        changeString(v);
        //3-3. ')'를 다시 붙입니다.
        change += ")";
        //3-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        for(int j=1;j<u.length()-1;j++)
        {
            if(u[j] == '(')
            {
                change += ")";
            }
            else if(u[j] == ')')
            {
                change += "(";
            }
        }
        //3-5. 생성된 문자열을 반환합니다.
        return;
    }
}

string solution(string p) {
    string answer = "";

    if(checkString(p)) //올바른 괄호 문자열인 경우
    {
        answer = p;
    }
    else //균형잡힌 괄호 문자열인 경우
    {
        changeString(p);
        answer = change;
    }
    return answer;
}

int main(void)
{
    string result = "";
    /*
    result = solution("(()())()");
    cout << result << endl;
    result = "";
    */
    /*
    result = solution(")(");
    cout << result << endl;
    result = "";
    */
    
    result = solution("()))((()");
    cout << result << endl;
    
    return 0;
}