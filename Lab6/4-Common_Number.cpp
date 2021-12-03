//4. 给定一个整数序列，每个元素出现的次数称为重数，
//重数最大的元素称为众数。请设计算法对一个递增有序的整数序列寻找众数

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 2, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 7};
    int ans = 0, maxLen = 0;
    int dp = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        dp = nums[i] == nums[i - 1] ? dp + 1 : 1;
        if(maxLen < dp)
            maxLen = dp, ans = nums[i];
    }

    cout << "Common Number is " << ans << endl;
    return 0;
}