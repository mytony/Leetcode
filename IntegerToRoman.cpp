class Solution {
public:
    string intToRoman(int num) {
        string letter = "IVXLCDM";
        string result;
        int count, i;
        // 1000
        count = num / 1000;
        for(i=0; i<count; i++){
            result += "M";
        }
        num %= 1000;
        // 100
        count = num / 100;
        if(count == 4){
            result += "CD";
        } else if(count == 9){
            result += "CM";
        } else if(count >= 5){
            result += "D";
            for(i=0; i<count-5; i++){
                result += "C";
            }
        } else {
            for(i=0; i<count; i++){
                result += "C";
            }
        }
        num %= 100;
        // 10
        count = num / 10;
        if(count == 4){
            result += "XL";
        } else if(count == 9){
            result += "XC";
        } else if(count >= 5){
            result += "L";
            for(i=0; i<count-5; i++){
                result += "X";
            }
        } else {
            for(i=0; i<count; i++){
                result += "X";
            }
        }
        num %= 10;
        // 1
        count = num;
        if(count == 4){
            result += "IV";
        } else if(count == 9){
            result += "IX";
        } else if(count >= 5){
            result += "V";
            for(i=0; i<count-5; i++){
                result += "I";
            }
        } else {
            for(i=0; i<count; i++){
                result += "I";
            }
        }
        return result;
    }
};
