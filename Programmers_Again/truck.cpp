// 다리를 지나는 트럭
// 2020.05.07

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 1; // 시간
    queue<int> bridge; // 다리
    int arrive_truck = 0; // 도착한 트럭
    int next_truck = 1;
    int on_bridge_truck_weight = truck_weights[0];

    bridge.push(1);

    while(1)
    {
        if(arrive_truck == truck_weights.size())
        {
            return answer;
        }

        answer += 1;

        if(answer == bridge.front() + bridge_length)
        {
            //cout << "out" << bridge.front() << '\n';
            arrive_truck += 1;
            on_bridge_truck_weight -= truck_weights[arrive_truck-1];
            //cout << "weight is " << on_bridge_truck_weight << '\n';
            bridge.pop();
        }
        
        if(on_bridge_truck_weight + truck_weights[next_truck] <= weight)
        {
            //cout << "in" << answer << '\n';
            bridge.push(answer);
            on_bridge_truck_weight += truck_weights[next_truck];
            next_truck += 1;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int bridge_length = 100;
    int weight = 100;

    vector<int> truck_weights;
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);

    int result = solution(bridge_length,weight,truck_weights);

    cout << result << '\n';

    return 0;
}