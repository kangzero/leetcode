class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 0;
        int val = 0; 
        
        val = digits[len-1] + 1;
        if (val > 9) {
            digits[len-1] = 0;
            carry = 1;
        } else {
            digits[len-1] = val;
            carry = 0;
        }
        len--;
        
        while (len > 0) {
            val = digits[len-1] + carry;
            if (val > 9) {
                digits[len-1] = 0;
                carry = 1;
            } else {
                digits[len-1] = val;
                carry = 0;
            }
            len--;
        }
        
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
