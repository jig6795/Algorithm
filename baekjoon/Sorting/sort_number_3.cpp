//10989번 - 수 정렬하기 3
//cin >> k; 와  cout << i << endl; 를 사용했을 때는 런타임 에러가 발생
#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n;

    int arr[10001] = {0};

    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        arr[k] += 1;
    }

    for(int i=1;i<=10000;i++)
    {
        for(int j=0;j<arr[i];j++)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}