// Q2309
// 일곱 난쟁이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mini;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int sum = 0;
    for(int i=0;i<9;i++)
    {
        cin >> n;
        sum += n;
        mini.push_back(n);
    }

    sort(mini.begin(),mini.end());

    //전체에서 2개를 빼서 100을 만드는 것을 목표로 함
    for(int i=0;i<8;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(sum-(mini[i]+mini[j]) == 100)
            {
                for(int k=0;k<9;k++)
                {
                    if(k == i || k == j)
                    {
                        continue;
                    }
                    cout << mini[k] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}