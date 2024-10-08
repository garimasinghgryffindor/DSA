class Solution {
public:
    bool chkPalindrome(long long num) {
        string n = to_string(num);
        for(int i = 0; i < n.length()/2; i++) {
            if(n[i] != n[n.length()-1-i]) return false;
        }
        
        return true;
    }
    
    long long to_decimal(string& number_str, int base)
    {
        long long decimal_value = 0;
        int power = 0;

        for (int i = number_str.length() - 1; i >= 0; i--)
        {
            int digit_value = number_str[i] - '0';
            decimal_value += (long long)digit_value * pow(base, power);
            power++;
        }

        return decimal_value;
    }

    void utils(int len, int&cnt, int base, long long&res, string str) {
        if(len == str.length()) {
            if(str[0] == '0') return;
            long long dec = to_decimal(str, base);
            if(!chkPalindrome(dec)) return;
            
            cnt--;
            res += (long long)dec;
            
            return;
        } else if(str.length()*2 == len) {
            string right = str;
            reverse(right.begin(), right.end());
            str = str + right;
            if(str[0] == '0') return;
            long long dec = to_decimal(str, base);
            if(!chkPalindrome(dec)) return;
            
            cnt--;
            res += (long long)dec;   
            
            return;
        }
        
        if(str.length() == 0) {
            for(int i = 1; i < base; i++) {
                utils(len, cnt, base, res, to_string(i));
                if(!cnt) return;
            }
        } else if(len - 2*str.length() > 1) {
            for(int i = 0; i < base; i++) {
                utils(len, cnt, base, res, str+to_string(i) );
                if(!cnt) return;
            }
        } else {
            
            
            for(int i = 0; i < base; i++) {
                string right = str;
                reverse(right.begin(), right.end());
                utils(len, cnt, base, res, str+to_string(i)+right );
                if(!cnt) return;
            }
        }

    }
    
    long long kMirror(int k, int n) {
        long long sm = 0;
        int tot = n;
        
        for(int i = 1;; i++) {
            long long res = 0;
            utils(i, tot, k, res, "");
            sm += (long long)res;
            if(tot == 0) return sm;
        }
        
        return sm;
    }
};







