// Q5543
// 상근날드
// 시간복잡도 - O(n)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int ham = 2100;
    int bev = 2100;
    int sum = 0;

    for(int i=0;i<5;i++)
    {
        cin >> n;

        if(i < 3)
        {
            if(ham > n)
            {
                ham = n;
            }
        }
        else
        {
            if(bev > n)
            {
                bev = n;
            }    
        }
    }

    cout << ham + bev - 50 << '\n';
    return 0;
}