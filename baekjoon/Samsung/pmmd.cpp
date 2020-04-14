// Q14888
// 연산자 끼워넣기

#include <iostream>
#include <vector>

using namespace std;

int N; // 수의 개수
vector<int> number(11); // 수가 들어있는 벡터
vector<int> total_result; // 결과값을 저장할 벡터

void make_result(int cal_num, vector<int> copy_calc, int cal_result, int count) // 연산을 진행할 재귀함수
{
    //각 결과값을 계산
    if(cal_num == 0)
    {
        cal_result += number[count];
    }
    else if(cal_num == 1)
    {
        cal_result -= number[count];
    }
    else if(cal_num == 2)
    {
        cal_result *= number[count];
    }
    else if(cal_num == 3)
    {
        cal_result /= number[count];
    }
    
    copy_calc[cal_num] -= 1; // 쓰인 연산자는 지워준다.

    // 연산자가 비어있는지 확인한다.
    bool flag = true;
    for(int i=0;i<4;i++)
    {
        if(copy_calc[i] != 0)
        {
            flag = false;
        }
    }

    // 비어있다면 저장
    if(flag == true)
    {
        total_result.push_back(cal_result);
        return;
    }

    // 각 연산자 별로 한번씩 계산을 진행
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<copy_calc[i];j++)
        {
            make_result(i,copy_calc,cal_result,count+1);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> calc(4); // 각 연산자의 개수가 들어감

    // 입력
    cin >> N;

    for(int i=0;i<N;i++)
    {
        cin >> number[i];
    }

    for(int i=0;i<4;i++)
    {
        cin >> calc[i];
    }

    int result = number[0];

    // 각 연산자 별로 한번씩 계산을 진행
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<calc[i];j++)
        {
            make_result(i,calc,result,1);
        }
    }

    // 최대, 최소값을 확인
    int biggest = -99999999;
    int smallest = 999999999;
    for(int i=0;i<total_result.size();i++)
    {
        if(total_result[i] > biggest)
        {
            biggest = total_result[i];
        }

        if(total_result[i] < smallest)
        {
            smallest = total_result[i];
        }
    }

    cout << biggest << '\n';
    cout << smallest << '\n';

    return 0;
}