#include<iostream>
#include<vector>
#include<map>

using namespace std;

// 数组的相对排序
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> lookup;
        for (int i = 0; i < arr1.size(); ++i) {
            lookup[arr1[i]]++;
        }
        int position = 0;
        for (int i = 0; i < arr2.size(); ++i) {
            while (lookup[arr2[i]]-- > 0) {
                arr1[position++] = arr2[i];
            }
        }
        for (auto it: lookup) {
            while(it.second-- > 0) {
                arr1[position++] = it.first;
            }
        }
        return arr1;
    }
};

int main() {
    Solution solution;
    vector<int> arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2{2, 1, 4, 3, 9, 6};
    vector<int> ans = solution.relativeSortArray(arr1, arr2);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout <<endl;
    return 0;
}