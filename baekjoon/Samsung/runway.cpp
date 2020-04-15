// Q14890
// 경사로
// 실패

#include <iostream>
#include <vector>

using namespace std;

int N, L;
int map[101][101]; // 전체 지도
int check_map[101]; // 경사로를 설치한 부분을 확인하기 위한 배열
int result = 0; // 지나갈 수 있는 길

void clear_check_map(void)
{
    for(int i=0;i<N;i++)
    {
        check_map[i] = 0;
    }
}

bool check_L_up_Row(int row, int col) // 앞이 높은 경우, 뒤를 확인
{
    for(int i=col;i<col+L;i++)
    {
        if((map[row][col] != map[row][i]) || (check_map[i] != 0))
        {
            return false;
        }
    }
    return true;
}

bool check_L_down_Row(int row, int col) // 뒤가 높은 경우, 앞을 확인
{
    for(int i=col;i>col-L;i--)
    {
        if((map[row][col] != map[row][i]) || (check_map[i] != 0))
        {
            return false;
        }
    }
    return true;
}

void check_Row(void) // 가로 길을 확인
{
    bool check = true;

    for(int i=0;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(map[i][j-1] != map[i][j]) // 층이 다르다면
            {
                if(map[i][j-1] > map[i][j]) // 앞이 높은 경우
                {
                    if(check_L_up_Row(i,j) == false) // 경사로를 놓는 것이 불가능한 경우
                    {
                        check = false;
                        break;
                    }
                    else // 놓는다면
                    {
                        for(int k=j;k<j+L;k++)
                        {
                            check_map[k] = 1;
                        }
                    }
                }
                else if(map[i][j-1] < map[i][j]) // 뒤가 높은 경우
                {
                    if(check_L_up_Row(i,j-1) == false) // 경사로를 놓는 것이 불가능한 경우
                    {
                        cout << "Impossible Row is " << i << '\n';
                        check = false;
                        break;
                    }
                    else // 놓는다면
                    {
                        for(int k=j-1;k>j-1-L;k--)
                        {
                            check_map[k] = 1;
                        }
                    }
                }
            }
        }

        clear_check_map();

        if(check == true)
        {
            cout << "Row is " << i << '\n';
            result += 1;
        }
    }
}

void check_Col(void)
{

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> map[i][j];
        }
    }

    clear_check_map();
    check_Row();
    clear_check_map();

    cout << result << '\n';

    return 0;
}