class Solution {
public:
    int bulbSwitch(int n) {
        int base = 1;
        while(n / (base*base) > 0){
            base++;
        }
        return base - 1;
    }
};
