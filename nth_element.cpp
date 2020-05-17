//
//  nth_element.cpp
//  CPP_TEST
//
//  Created by miaozb on 2020/5/17.
//  Copyright © 2020 miaozb. All rights reserved.
//

#include <stdio.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int solve(vector<int> &a, int k, int l, int r)
{
    int l_temp = l, r_temp = r;
    int index = rand()%(r-l+1)+l;
    int temp = a[index];
    swap(a[index], a[l]);
    while (l < r)
    {
        while (l < r && a[r] <= temp) --r;
        a[l] = a[r];
        while (l < r && a[l] >= temp) ++l;
        a[r] = a[l];
    }
    a[l] = temp;
    
    if (l == k) return a[l];
    else if (l > k) return solve(a, k, l_temp, l - 1);
    else return solve(a, k, l + 1, r_temp);
}

int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned int)time(NULL));
    --k;
    return solve(nums, k, 0, (int)nums.size()-1);
}


int main()
{
    vector<int> a = {5,10,7,34,23,58,2,55,35,45};
    // 2 5 7 10 23 34 35 45 55 58

    cout << findKthLargest(a, 3) << endl;

    return 0;
}
