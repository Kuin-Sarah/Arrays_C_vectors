/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <iostream>
#include <vector>
#include <numeric> //For iota()
#include<algorithm> 

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int numsSize = nums.size();

        //a vector of indexes of nums ( 0__nums.size() ) O(n)
        vector<int> indexes(numsSize);
        iota(indexes.begin(), indexes.end(), 0);

        //sorting indexes according to nums O(nlogn)
        sort(indexes.begin(), indexes.end(), [&](int A, int B) -> bool {
                return nums[A] < nums[B];
         });

        //sorting nums O(nlogn)
        sort(nums.begin(), nums.end());

        for (auto i = 0; i < numsSize - 1; i++) {//O(n)

            vector<int>::iterator itr1 = find(nums.begin(), nums.begin() + i, (target - nums[i])); //O(logn) because nums is sorted
            vector<int>::iterator itr2 = find(nums.begin() + i + 1, nums.end(), (target - nums[i])); //O(logn) because nums is sorted

            int j;

            if (itr1 != nums.begin() + i ) {
                j = distance(nums.begin(), itr1); //O(1) because vector::iterator is a RandomAccessIterator.
                return vector<int>({ indexes[i], indexes[j] });
            }
            if (itr2 != nums.end()) {
                j = distance(nums.begin(), itr2);//O(1) because vector::iterator is a RandomAccessIterator.
                return vector<int>({ indexes[i], indexes[j] });
            }
            
        }

        return vector<int>({});
    }
};
int main()
{
    //complexity O(nlogn)
    vector<int> v = { 3,3 };
    int target = 6;

    cout << "V :\t";
    for (auto i : v) {
        cout << i << "\t";
    }
    cout << endl;
    cout << "Target :\t " << target << endl;
    
    Solution S;
    cout << "Indexes :\t";
    for (auto i : S.twoSum(v, target)) {
        cout << i << "\t";
    }
    cout << endl;
}

