// Q3085
// 사탕 게임
// 시간복잡도 - O()

#include <iostream>

using namespace std;

int n;
int max_Candy;
char candy[50][50];

void swap(int _i, int _j, int tar_i, int tar_j)
{
    int temp = candy[_i][_j];
    candy[_i][_j] = candy[tar_i][tar_j];
    candy[tar_i][tar_j] = temp;
}

void Horizontal() // 가로 방향 이어진 캔디 계산
{
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (candy[i][j] == candy[i][j + 1]) // 같은 캔디수 만큼 카운트 증가
			{
				count++;
			}
			else 
			{
				if (max_Candy < count) // 최댓값 갱신
				{
					max_Candy = count;
				}
				count = 1; // 카운트 초기화
			}
		}
	}
}

void Vertical()
{
	for (int i = 0; i < n; i++) // 세로 방향 이어진 캔디 계산
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (candy[j][i] == candy[j + 1][i]) // 같은 캔디수 만큼 카운트 증가
			{
				count++;
			}
			else
			{
				if (max_Candy < count) // 최댓값 갱신
				{
					max_Candy = count;
				}
				count = 1; // 카운트 초기화
			}
		}
	}
}

void checkRow(int _n)
{
    for(int i=0;i<_n;i++)
    {
        for(int j=0;j<(_n-1);j++)
        {
            if(candy[i][j] != candy[i][j+1])
            {
                swap(i,j,i,j+1);
                Horizontal();
                Vertical();
                swap(i,j,i,j+1);
            }
        }
    }
}

void checkCol(int _n)
{
    for(int j=0;j<_n;j++)
    {
        for(int i=0;i<(_n-1);i++)
        {
            if(candy[i][j] != candy[i+1][j])
            {
                swap(i,j,i+1,j);
                Horizontal();
                Vertical();
                swap(i,j,i+1,j);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> candy[i][j];
        }
    }

    checkRow(n);
    checkCol(n);

    cout << max_Candy;

    return 0;
}