// 4.二项式(a+b)n展开后，其系数构成杨辉三角形，写出利用队列实现打印杨辉三角形的前n行的算法。

#include<bits/stdc++.h>
using namespace std;

void YHTriangle(int n)
{
    printf("YangHui Triangle with %d floor:\n", n);
    cout << R"(
1
1 1
)";
    queue<int> q({1, 1, 1});
    for(int i = 1; i < n - 1; i++, puts(""))
    {
        //Remove duplicated 1
        q.pop();
        printf("1 ");
        q.push(1);
        for(int j = 0; j < i; j++)
        {
            auto t = q.front();
            q.pop();
            t += q.front();
            cout << t << " ";
            q.push(t);
        }
        printf("1 ");
        q.push(1);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    YHTriangle(n);
    return 0;
}