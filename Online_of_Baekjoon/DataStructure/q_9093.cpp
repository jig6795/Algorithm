// Q9093
// 단어 뒤집기

#include <iostream>

using namespace std;

char stack[20];
int top = -1;

void push(char ch)
{
    if(top == 20)
    {
        return;
    }
    top += 1;
    stack[top] = ch;
}

void allpop(void)
{
    while(top != -1)
    {
        cout << stack[top];
        top -= 1;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    cin.ignore(); //다음 getline(cin, str)시 공백을 읽는 것을 방지

    string str;

    for(int i=0;i<testCase;i++)
    {
        getline(cin, str);

        for(int i=0;i<str.length();i++)
        {
            if(str[i] == ' ')
            {
                allpop();
                cout << " ";
            }
            else //띄워쓰기까지 STACK에 넣지 않도록 하기 위해
            {
                push(str[i]);
            }
        }
        allpop(); //마지막에 STACk에 남은 단어를 출력
        cout << '\n';
    }

    return 0;
}