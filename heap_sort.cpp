////
////  heap_sort.cpp
////  CPP_TEST
////
////  Created by miaozb on 2020/5/16.
////  Copyright © 2020 miaozb. All rights reserved.
////
//
//#include<iostream>
//#include<vector>
//using namespace std;
//void MaxSort(vector<int> &a, int i, int n)
//{
//    int father = a[i];//把当前结点的数赋给father变量，后面会发现这个变量很有用
//    int j = 2*i;//找到当前结点的左孩子
//    while(j <= n)//判断必须条件，大于或等于该结点都属于数组越界
//    {
//        if(j+1 <= n && a[j] < a[j+1])//判断条件，第一个条件是判断是不是最后一个结点。
//                                   //第二个判断条件是找出孩子结点最大的数方便与结点交换。
//            ++j;//如果后面的大，那么交换的变成后面的孩子。
//        if(father > a[j])//因为我们是MaxSort所以如果父结点本身就大不用判断直接跳出循环。
//            break;
//        else
//        {
//            a[i] = a[j];//判断过程，把最大的孩子结点的数赋给父结点。并利用递归思想找出子节点的子节点。
//            i = j;
//            j = 2*i;
//         }
//    }
//    a[i] = father;//i已经成为了孩子结点的下标，赋值temp，也就是原本父结点的值，达成交换。
//}
// 
// //堆排序
//void HeapSort(vector<int> &a, int n)
//{
//    for(int i= n/2;i>=1;i--)//从最后一个结点的父结点开始“向前遍历”。
//        MaxSort(a,i,n);
//    
//    for (int i=1;i<=n;i++)
//        cout << a[i] << " ";
//    
//    cout << endl;
//    
//    for(int i=n-1;i>=1;i--)
//    {
//        swap(a[i+1],a[1]);
//        MaxSort(a,1,i);
//    }//逆序
//}
//int main()
//{
//    vector<int> a{0,5,10,7,34,23,58,2,55,35,45};
//    int len = (int)a.size() - 1;
//    HeapSort(a, len);
//    for (int i=1;i<=len;i++)
//        cout << a[i] << " ";
//    
//    return 0;
//}
