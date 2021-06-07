/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，
则最小的4个数字是1、2、3、4。


示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

*/

/*方法一：排序

对原数组从小到大排序后取出前 kk 个数即可。

时间复杂度：O(n\log n)O(nlogn)，其中 nn 是数组 arr 的长度。算法的时间复杂度即排序的时间复杂度。

空间复杂度：O(\log n)O(logn)，排序所需额外的空间复杂度为 O(\log n)O(logn)。
*/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            vec[i] = arr[i];
        }
        return vec;
    }
};


/*
方法二：堆
我们用一个大根堆实时维护数组的前 kk 小值。首先将前 kk 个数插入大根堆中，
随后从第 k+1k+1 个数开始遍历，如果当前遍历到的数比大根堆的堆顶的数要小，就把堆顶的数弹出，
再插入当前遍历到的数。
最后将大根堆里的数存入数组返回即可。
在下面的代码中，由于 C++ 语言中的堆（即优先队列）为大根堆，我们可以这么做。
而 Python 语言中的堆为小根堆，因此我们要对数组中所有的数取其相反数，才能使用小根堆维护前 k 小值

*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }
        priority_queue<int> Q;  //默认大根堆
        for (int i = 0; i < arr.size(); ++i) {
            Q.push(arr[i]);
            if(Q.size()>k)
                Q.pop();
        }

        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
    
};

/*
方法三：快排思想
我们可以借鉴快速排序的思想。我们知道快排的划分函数每次执行完后都能将数组分成两个部分，
小于等于分界值 pivot 的元素的都会被放到数组的左边，大于的都会被放到数组的右边，然后返回分界值的下标。
与快速排序不同的是，快速排序会根据分界值的下标递归处理划分的两侧，而这里我们只处理划分的一边。

我们定义函数 randomized_selected(arr, l, r, k) 表示划分数组 arr 的 [l,r] 部分，
使前 k 小的数在数组的左侧，在函数里我们调用快排的划分函数，
假设划分函数返回的下标是 pos（表示分界值 pivot 最终在数组中的位置），
即 pivot 是数组中第 pos - l + 1 小的数，那么一共会有三种情况：

如果 pos - l + 1 == k，表示 pivot 就是第 kk 小的数，直接返回即可；

如果 pos - l + 1 < k，表示第 kk 小的数在 pivot 的右侧，因此递归调用 randomized_selected(arr, pos + 1, r, k - (pos - l + 1))；

如果 pos - l + 1 > k，表示第 kk 小的数在 pivot 的左侧，递归调用 randomized_selected(arr, l, pos - 1, k)。


*/
#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    int partition(vector<int> &arr, int left, int right){
        int i=left, j=right;
        // 先以最右侧元素为基准
        while (i < j) {
            // 先从左往右遍历
            while (i < j && arr[i] <= arr[right]) i++;
            // 再从右往左遍历
            while (i < j && arr[j] >= arr[right]) j--;
            // i所指元素小于基准，j所指元素大于基准
            // 交换i和j的元素
            swap(arr[i], arr[j]);
            // 循环进行，直到i和j指向同一个位置
        }
        swap(arr[i], arr[right]); // 将基准元素换到循环停止的位置
        // 此时基准左边全小于它的数，右边全是大于它的数
        return i; 
    }

    int randomized_partition(vector<int> &arr, int left, int right){
        int rd = rand()%(right-left+1)+left;
        swap(arr[right],arr[rd]);
        return partition(arr,left,right);

    }

    void randomized_selected(vector<int> &arr, int left, int right, int k) {
        if (left >= right) {
            return;
        }
        int pos = randomized_partition(arr, left, right);
        int num = pos - left + 1;
        if (k == num) {
            return;
        } else if (k < num) {
            randomized_selected(arr, left, pos - 1, k);
        } else {
            randomized_selected(arr, pos + 1, right, k - num);
        }
    }



    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        randomized_selected(arr,0,arr.size()-1,k);
        for(int i=0;i<k;++i){
            res.push_back(arr[i]);
        }
        return res;
    }

};

int main(){

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(5);

    int k = 4;
    vector<int> res = solution().getLeastNumbers(arr,k);
    for(int i=0;i<k;++i){
        cout<<res[i]<<" ";
    }

    return 0;
}