// Forum solution
// 需要再更深的理解
// 解釋 [](int a, int b)
// It's lamada function,a new feature in the C++11.
// It compares 'a+b' with 'b+a',and then we sort the num in the criterion we define.
// If you want to know the detail,you can look up on the new edition <C++ Prime>.
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans;
        for(int i=0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        return ans[0]=='0' ? "0" : ans;
    }
};