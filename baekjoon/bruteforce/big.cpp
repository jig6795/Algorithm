#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int weight[n]; //무게
    int height[n]; //신장
    int grade[50] = {0};

    for(int i=0;i<n;i++)
    {
        cin >> weight[i] >> height[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == j)
            {
                grade[i] += 1;
            }

            if(weight[i] < weight[j])
            {
                if(height[i] < height[j])
                {
                    grade[i] += 1;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(grade[i] == 0)
        {
            break;
        }
        
        cout << grade[i] << ' ';
    }

    return 0;
}