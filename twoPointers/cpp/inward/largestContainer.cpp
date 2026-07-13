#include<iostream>
#include<vector>

using namespace std;

int maxContainer(vector<int> heights){
    int start = 0;
    int end = heights.size() - 1;
    int maxWater;

    while(start < end){
        int water = min(heights[start], heights[end]) * (end - start);
        maxWater = max(maxWater, water);

        if(heights[start] < heights[end]){
            start ++;
        }
        else if(heights[start] > heights[end]){
            end--;
        }
        else{
            start++;
            end--;
        }
    }
    return maxWater;
}

int main(){
    vector<int> heights = {2,7,8,3,7,6};
    cout<<maxContainer(heights);
    return 0;
}