#include <iostream>
#include <string>
#include <vector>

using namespace std;

int group[201];

//
// 최초의 group 배영을 초기화하는 함수
//
void initGroup(int _n)
{
    for(int i=0;i<_n;i++)
    {
        group[i] = i;
    }
}

//
// 연결되어 있는 네트워크인 경우, 같은 group에 두는 함수 - 항상 작은 쪽으로 만들어준다.
//
void putSameGroup(int r, int c, int __n)
{
    if(group[r] < group[c])
    {
        for(int i=0;i<__n;i++)
        {
            if(group[i] == group[c])
            {
                group[i] = group[r];
            }
        }
    }
    else if(group[r] > group[c])
    {
        for(int i=0;i<__n;i++)
        {
            if(group[i] == group[r])
            {
                group[i] = group[c];
            }
        }
    }
}

//
// 네트워크의 수를 세어주는 함수
//
int countGroupNum(int ___n)
{
    int arr[200] = {0};
    int cnt = 0;
    for(int i=0;i<___n;i++)
    {
        arr[group[i]] = 1;
    }

    for(int j=0;j<___n;j++)
    {
        if(arr[j] == 1)
        {
            cnt += 1;
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;

    initGroup(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == j)
            {
                continue;
            }

            //같은 네트워크에 존재하지만 다른 그룹에 있는 경우
            if(group[i] != group[j])
            {
                if(computers[i][j] == 1)
                {
                    putSameGroup(i,j,n);
                }
            }
        }
    }

    answer = countGroupNum(n);

    return answer;
}

int main(void)
{
    int result = 0;
    vector<vector<int> > computer;

    vector<int> network1;
    network1.push_back(1);
    network1.push_back(1);
    network1.push_back(0);
    
    vector<int> network2;
    network2.push_back(1);
    network2.push_back(1);
    network2.push_back(0);

    vector<int> network3;
    network3.push_back(0);
    network3.push_back(0);
    network3.push_back(1);

    computer.push_back(network1);
    computer.push_back(network2);
    computer.push_back(network3);

    result = solution(3,computer);

    cout << "Result is " << result << endl;

    return 0;
}