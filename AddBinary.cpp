class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            return add(b, a);
        else
            return add(a, b);
    }
    string add(string& a, string& b){
        int ia = a.size()-1, ib = b.size()-1;
        bool carry = false;
        while(ib > -1){
            if(!carry && a[ia] == '0' && b[ib] == '1'){
                a[ia] = '1';
            } else if(!carry && a[ia] == '1' && b[ib] == '1'){
                a[ia] = '0';
                carry = true;
            } else if(carry && a[ia] == '0' && b[ib] == '0'){
                a[ia] = '1';
                carry = false;
            } else if(carry && a[ia] == '0' && b[ib] == '1'){
                a[ia] = '0';
            } else if(carry && a[ia] == '1' && b[ib] == '0'){
                a[ia] = '0';
            } else if(carry && a[ia] == '1' && b[ib] == '1'){
                a[ia] = '1';
            }
            ia--;
            ib--;
        }
        if(carry){
            if(ia == -1){ // a and b have same length
                a.insert(0, "1");
            } else {
                do{
                    if(a[ia] == '0'){
                        a[ia] = '1';
                        carry = false;
                    } else {
                        a[ia] = '0';
                        ia--;
                        carry = true;
                    }
                } while(carry && ia > -1);
                if(carry){
                    a.insert(0, "1");
                }
            }
        }
        return a;
    }
};
