// Q1373
// 2진수 8진수
// 시간복잡도 - O(n)

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string numOfTwo;
    getline(cin, numOfTwo);

    stack<char> first;
    stack<int> second;

    int nam = numOfTwo.size()%3;
    if(nam == 1)
    {
        first.push('0');
        first.push('0');
    }
    else if(nam == 2)
    {
        first.push('0');
    }

    for(int i=0;i<numOfTwo.size();i++)
    {
        first.push(numOfTwo[i]);
    }

    int n = 0;
    int sum = 0;
    while(first.empty() != 1)
    {
        if(first.top() == '1' && n == 0)
        {
            sum += 1;
        }
        else if(first.top() == '1' && n == 1)
        {
            sum += 2;
        }
        else if(first.top() == '1' && n == 2)
        {
            sum += 4;
        }

        first.pop();
        n += 1;

        if(n == 3)
        {
            second.push(sum);
            sum = 0;
            n = 0;
        }
    }

    while(second.empty() != 1)
    {
        cout << second.top();
        second.pop();
    }

    return 0;
}