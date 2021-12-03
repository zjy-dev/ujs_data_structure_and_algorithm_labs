//3. 有n（n>3）个硬币，其中一枚是假币，由于假币的重量较轻,
//可以采用天平称重的方式找到这枚假币。请设计算法模拟寻找假币的过程

#include<bits/stdc++.h>
using namespace std;

int findFakeCoin(vector<int>& coins, int l, int r)
{
    if(l == r)
        return l;
    if(l + 1 == r)
        return l < r ? l : r;

    int mid = (l + r) >> 1;
    double cntL = 0, cntR = 0;
    int lenL = mid - l, lenR = r - mid + 1;
    for(int i = 0; i < mid; i++)
        cntL += coins[i];
    for(int i = mid; i < r; i++)
        cntR += coins[i];

    if(cntL / lenL < cntR / lenR)
        return findFakeCoin(coins, l, mid);
    else
        return findFakeCoin(coins, mid, r);
}

int main(int argc, char const *argv[])
{
    vector<int> coins{1, 1, 1, 1, 1, 0, 1};//ans is supposed to be 5

    cout << "Fake Coin index is " << findFakeCoin(coins, 0, coins.size() - 1);
    return 0;
}