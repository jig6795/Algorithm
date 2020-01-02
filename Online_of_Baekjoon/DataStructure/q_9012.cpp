// Q9012
// 괄호

#include <iostream>
#include <stack>

using namespace std;

void solveProblem(string str)
{
    stack<int> number_loc; //STACK 선언

    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '(') // 여는 괄호가 나오는 경우, PUSH
        {
            number_loc.push(i);
        }
        else if(str[i] == ')') // 닫는 괄호가 나오는 경우, POP
        {
            if(number_loc.empty() == 1) // 비어있는 경우에 닫는 괄호면 종료
            {
                cout << "NO" << '\n';
                return;
            }
            number_loc.pop();
        }
    }

    if(number_loc.empty() == 1) // VPS를 이루는 경우
    {
        cout << "YES" << '\n';
        return;
    }
    else // 아닌 경우
    {
        cout << "NO" << '\n';
        return;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    cin.ignore();

    string str;

    for(int i=0;i<testCase;i++)
    {
        getline(cin, str);

        solveProblem(str);  
    }

    return 0;
}