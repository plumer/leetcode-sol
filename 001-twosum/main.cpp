#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;

class Solution {
    public:
        vector<int> twoSum(vector<int>&nums, int target) {
            vector<int> copy(nums.size());
            std::copy(nums.begin(), nums.end(), copy.begin());
            std::sort(nums.begin(), nums.end());
            vector<int> res;
            for (int i = 0; i < nums.size(); ++i) {
                int s = search(nums, target - nums[i]);
                if (s != -1) {
                    //cout << "right:" << nums[i] << ',' << nums[s] << "\n";
                    res.push_back( std::find(copy.begin(), copy.end(), nums[i]) - copy.begin() );
                    if (nums[i] == nums[s])
                        res.push_back( std::find(copy.begin()+res[0]+1, copy.end(), nums[s]) - copy.begin() );
                    else
                        res.push_back( std::find(copy.begin(), copy.end(), nums[s])-copy.begin() );
                    //res.push_back( search(copy, nums[s]) );
                    if (res[0] > res[1]) {
                        int t = res[1];
                        res[1] = res[0];
                        res[0] = t;
                    }
                    res[0]++;
                    res[1]++;
                    return res;
                }
            }
            //cout << "wrong\n";
            return res;
        }

        int search(vector<int> &nums, int key) {
            int high = nums.size(), low = 0, med;
            while (low < high) {
                med = (low + high) / 2;
                if (nums[med] == key)
                    return med;
                else if (nums[med] < key)
                    low = med+1;
                else
                    high = med;
            }
            //cout << key << " not found\n";
            return -1;
        }
};

int main() {
    int array[] = {3,2,4};
    vector<int> input(array, array + 3);

    Solution sol;
    vector<int> answer = sol.twoSum(input, 6);
    cout << answer[0] << ' ' << answer[1] << std::endl;
    return 0;
}
