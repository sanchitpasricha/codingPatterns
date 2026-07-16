#include <iostream>
#include <vector>

using namespace std;

int getNumber(int num){
    int sum = 0;

    while (num){
        int digit = num%10;
        num /= 10;

        sum = sum + (digit*digit);
    }

    return sum;
}

bool happyNumber(int n)
{
    int slow = n;
    int fast = n;

    while (true)
    {
        slow = getNumber(slow);
        fast = getNumber(getNumber(fast));

        if (fast == 1){
            return true;
        }
        else if (slow == fast){
            return false;
        }
    }
}


int main()
{
    cout<<happyNumber(116);
}