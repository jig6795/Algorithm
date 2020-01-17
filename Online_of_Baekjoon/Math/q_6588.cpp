// Q6588
// 골드바흐의 추측
// 시간복잡도 - O(nlogn)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase = 0;
    while(cin >> testCase)
    {
        if(testCase == 0)
        {
            break;
        }

        int totalCheck = 0;

        for(int i=3;i<=testCase;i+=2)
        {
            int temp = testCase - i;
            int check = 1;
            
            for(int j=2;j*j<=i;j++)
            {
                if(i%j == 0)
                {
                    check = 0;
                    break;
                }
            }

            for(int j=2;j*j<=temp;j++)
            {
                if(temp%j == 0 || check == 0)
                {
                    check = 0;
                    break;
                }
            }

            if(check == 1)
            {
                cout << testCase << " = " << i << " + " << temp << '\n';
                totalCheck = 1;
                break;
            }
        }

        if(totalCheck == 0)
        {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}