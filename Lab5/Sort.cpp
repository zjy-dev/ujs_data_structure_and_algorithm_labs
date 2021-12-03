#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;
	int i = left - 1, j = right + 1, flag = arr[left + right >> 1];
	while (i < j)
	{
		while (arr[++i] < flag);
		while (arr[--j] > flag);
		if (i < j)
			swap(arr[i], arr[j]);
	}
	quick_sort(arr, left, j);
	quick_sort(arr, j + 1, right);
}

void sell_sort(vector<int>& arr) 
{
    int j;
    for (int gap = arr.size() >> 1; gap >  0; gap >>= 1) 
        for (int i = gap; i < arr.size(); i++) 
        {
            int tmp = arr[i];
            for (j = i; j >= gap and tmp < arr[j - gap]; j -= gap) 
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }   
}

void merge_sort(vector<int>& arr, int left, int right, vector<int>& temp)
{
	if(left >= right)
		return;
	int mid = left + right >> 1;
	merge_sort(arr, left, mid, temp), merge_sort(arr, mid + 1, right, temp);
	int i = left, j = mid + 1, k = 0;
	while(i <= mid and j <= right)
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];

	while(i <= mid)
		temp[k++] = arr[i++];
	while(j <= right)
		temp[k++] = arr[j++];

	for(int i = left; i <= right; i++)
		arr[i] = temp[i - left];
}

//¶ÑÅÅÐò
const int maxn = 1e+5 + 10;

int* h;
int n;

void down(int u, int n)
{
    int t = u;
    if(u * 2 <= n and h[2 * u] < h[t])
        t = u * 2;
    if(u * 2 + 1 <= n and h[2 * u + 1] < h[t])
        t = u * 2 + 1;
    if(u != t)
    {
        swap(h[u], h[t]);
        down(t, n);
    }
}

int top()
{
    return h[1];    
}

void del_top(int& n)
{
    h[1] = h[n];
    n--;
    down(1, n);
}

int main()
{
    vector<int> v{5, 99, 55, 262, 66, 262, 8948, 22, 11, 22, 56, 47, 52};
    cout << "Ô­Ê¼Êý¾Ý: " << endl;
    for(const auto& val : v)
        cout << val << " ";
    puts("");

    cout << "¿ìËÙÅÅÐò" << endl;
    vector<int> arr = v;
    quick_sort(arr, 0, arr.size() - 1);
    for(const auto& val : arr)
        cout << val << " ";
    puts("");

    cout << "Ï£¶ûÅÅÐò" << endl;
    arr = v;
    sell_sort(arr);
    for(const auto& val : arr)
        cout << val << " ";
    puts("");

    cout << "¹é²¢ÅÅÐò" << endl;
    arr = v;
    vector<int> t(arr.size());
    merge_sort(arr, 0, arr.size() - 1, t);
    for(const auto& val : arr)
        cout << val << " ";
    puts("");

    cout << "¶ÑÅÅÐò" << endl;

    int a[] = {5, 99, 55, 262, 66, 262, 8948, 22, 11, 22, 56, 47, 52};
    h = a;
    n = 13;
    
    //½¨¶Ñ(O(n))
    for(int i = n / 2; i; i--)
        down(i, n);
    
    for(int i = 0; i < 13; i++)
    {
        cout << top() << " ";
        del_top(n);
    }
}