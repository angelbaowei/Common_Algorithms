#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


/**
 * Merge_Sort: 归并排序的递归实现
 * 注：算法导论上给出的合并排序算法
 * 递归过程是将待排序集合一分为二，
 * 直至排序集合就剩下一个元素为止，然后不断的合并两个排好序的数组
 * T(n) = O(nlgn)
**/
#include <stdio.h>

// 合并
void merge(vector<int> &a, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j, k;

    for (i = 0; i < n1; i++) /* left holds a[start..mid] */
        left[i] = a[start+i];
    for (j = 0; j < n2; j++) /* right holds a[mid+1..end] */
        right[j] = a[mid+1+j];

    i = j = 0;
    k = start;
    while (i < n1 && j < n2)
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];

    while (i < n1) /* left[] is not exhausted */
        a[k++] = left[i++];
    while (j < n2) /* right[] is not exhausted */
        a[k++] = right[j++];
}

// merge_sort()：先排序，再合并
void merge_sort(vector<int> &a, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) >> 1;

        // 分解 + 解决：Divide + Conquer
        merge_sort(a, start, mid); // 递归划分原数组左半边array[start...mid]
        merge_sort(a, mid+1, end); // 递归划分array[mid+1...end]
        // 合并：Combine
        merge(a, start, mid, end); // 合并

    }
}


/**
 * merge_sort: 非递归实现 --迭代
 * 非递归思想: 将数组中的相邻元素两两配对。用merge函数将他们排序，
 * 构成n/2组长度为2的排序好的子数组段，然后再将他们排序成长度为4的子数组段，
 * 如此继续下去，直至整个数组排好序。
**/

// merge_sort(): 非递归实现-自底向上
// 将原数组划分为left[min...max] 和 right[min...max]两部分
void merge_sort(vector<int> &list, int length)
{
    int i, left_min, left_max, right_min, right_max, next;
    vector<int> tmp(length, 0);

    for (i = 1; i < length; i *= 2) // i为步长，1,2,4,8……
    {
        for (left_min = 0; left_min < length - i; left_min = right_max)
        {
            right_min = left_max = left_min + i;
            right_max = left_max + i;

            if (right_max > length)
                right_max = length;

            next = 0;
            while (left_min < left_max && right_min < right_max)
                tmp[next++] = list[left_min] > list[right_min] ? list[right_min++] : list[left_min++];

            while (left_min < left_max)
                list[--right_min] = list[--left_max];

            while (next > 0)
                list[--right_min] = tmp[--next];
        }
    }

}

int main()
{
    vector<int> a = {5,10,7,34,23,58,2,55,35,45};
    int len = (int)a.size();
    merge_sort(a, 0, len-1);
    for (int i=0;i<len;i++)
        cout << a[i] << " ";
    return 0;
}
