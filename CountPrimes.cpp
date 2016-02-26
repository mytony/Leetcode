// Hint is detailed
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> nums (n, true);
        for(int i = 2; i < n; i++){
            if(nums[i]){
                cnt++;
                // 只需要找到根號n，因為如果要去刪i的倍數，i以下的前面已經刪完了，可以直接從i*i開始
                // 但是i如果大於根號n，那i*i就大於n，超出範圍
                if(i >= (double)n / i){ 
                    continue;
                }
                for(int j = i * i; j < n; j += i){
                    nums[j] = false;
                }
            }
        }
        return cnt;
    }
};
