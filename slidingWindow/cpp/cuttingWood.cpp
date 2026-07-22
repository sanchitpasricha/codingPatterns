/*
height

8   |                           +---+
7   |                           |###|
6   |         +---+             |###|
5   |         |###|             |###|
4   |         |###|             |###|
H=3 --+---------+---+-------------+---+---------
2   |  +---+  |   |     +---+   |   |
1   |  |   |  |   |     |   |   |   |
0   +----------------------------------------> i
         0      1         2       3   

heights = [2, 6, 3, 8]
k = number of wood pieces required
*/

#include<iostream>
#include<vector>

using namespace std;

bool enoughWood(int mid, int k, vector<int> heights){
    int collection = 0;
    for(auto height : heights){
        if(mid < height){
            collection += height - mid;
        }
    }
    return collection >= k;
}

int cutWood(vector<int> heights, int k){
    int left = 0;
    int right = *max_element(heights.begin(), heights.end()); // 8
    
    // [0 1 2 3 4 5 6 7 8]

    while(left < right){
        int mid = left + (right - left + 1) / 2;

        if(enoughWood(mid, k, heights)){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return right;

}

int main(){
    vector<int> heights = {2,6,3,8};
    int maxHeight = cutWood(heights, 7);
    cout<<maxHeight;

    return 0;
}