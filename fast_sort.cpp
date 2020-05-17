////
////  fast_sort.cpp
////  CPP_TEST
////
////  Created by miaozb on 2020/5/16.
////  Copyright © 2020 miaozb. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <iostream>
//#include <stack>
//using namespace std;
//
//int find_med(vector<int> &a, int l, int r)
//{
//    int index = rand()%(r-l+1)+l;
//    int temp = a[index];
//    swap(a[index], a[l]);
//    while (l < r)
//    {
//        while (l < r && a[r] >= temp) --r;
//        a[l] = a[r];
//        while (l < r && a[l] <= temp) ++l;
//        a[r] = a[l];
//    }
//    a[r] = temp;
//    return r;
//};
//
//void fast_sort(vector<int>& a) {
//    srand((unsigned int)time(NULL));
//    int left = 0, right = (int)a.size() - 1;
//    int med;
//    stack<int> s;
//    s.push(left);
//    s.push(right);//后入的right，所以要先拿right
//    while(!s.empty())//栈不为空
//    {
//        right = s.top();
//        s.pop();
//        left = s.top();
//        s.pop();
//        
//        med = find_med(a, left, right);
//        
//        if((med - 1) > left)//左子序列
//        {
//            s.push(left);
//            s.push(med - 1);
//        }
//        if((med + 1) < right)//右子序列
//        {
//            s.push(med + 1);
//            s.push(right);
//        }
//    }
//};
//
//int main()
//{
//    vector<int> a{0,5,10,7,34,23,58,2,55,35,45};
//    int len = (int)a.size() - 1;
//    fast_sort(a);
//    for (int i=1;i<=len;i++)
//        cout << a[i] << " ";
//    return 0;
//}
