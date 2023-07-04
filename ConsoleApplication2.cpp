/*Find the subarray of a given integer array with the largest sum*/

#include <iostream>
#include <vector>
#include<tuple> // for tuple
#include <numeric> // for accumulate

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        auto numsSize = nums.size();

        if (numsSize >= 2) {

            int sum1, sum2;
            tuple <int, int> best1;
            tuple <int, int> best2;

            sum1 = nums[0];
            sum2 = nums[numsSize - 1];

            best1 = make_tuple(0, sum1);
            best2 = make_tuple(numsSize - 1, sum2);

            for (auto i = 1; i < numsSize; i++) {
                sum1 += nums[i];
                sum2 += nums[numsSize - 1 - i];
                if (sum1 >= get<1>(best1)) {
                    get<0>(best1) = i;
                    get<1>(best1) = sum1;
                }
                if (sum2 >= get<1>(best2)) {
                    get<0>(best2) = numsSize - 1 - i;
                    get<1>(best2) = sum2;
                }
            }

            cout << "SubVector :\t" << endl;
            for (auto i = get<0>(best2); i <= get<0>(best1); i++) cout << nums[i] << "\t";
            cout << endl;
            
           
            return [](vector<int> v, int a, int b) {
                int sum = 0;
                for (auto i = a; i <= b; i++) sum += v[i];
                return sum;
            }(nums, get<0>(best2), get<0>(best1));
        }
        else {
            if (numsSize == 0) return -1;
            else return nums[0];
        }
        
    }
};

int main()
{
    //complexity O(n)
    vector<int> v = { 5,4,-1,7,8 };

    cout << "V :\t";
    for (auto i : v) {
        cout << i << "\t";
    }
    cout << endl;

    Solution S;
    cout << "Solution :\t" << S.maxSubArray(v) << endl;

}