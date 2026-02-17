class Solution {
public:
    string getString(int h, int m) {
        string temp = "";
        temp += to_string(h);
        temp = temp + ":";
        string min = to_string(m);
        if(m < 10) {
            min = "0"+min;
        }
        temp = temp + min;
        return temp;
    }

    void recur(vector<string>&res, int tot_bits, int rem, int hour, int min) {
        // cout<<"hour : "<<hour<<"   min: "<<min<<endl;
        if(min > 59 || hour > 11) return;
        if(tot_bits == 0) {
            if(rem == 0) {
                string temp = getString(hour, min);
                res.push_back(temp);
            }
            return;
        }
        // if(rem == 0) return;
 
        // cout<<"hour : "<<hour<<"   min: "<<min<<endl;
        if(tot_bits > 6)
            recur(res, tot_bits-1, rem, hour*2, min);
        else 
            recur(res, tot_bits-1, rem, hour, min*2);

        if(tot_bits > 6) {
            recur(res, tot_bits-1, rem-1, hour*2+1, min);
        } else 
        recur(res, tot_bits-1, rem-1, hour, min*2+1);
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>res;
        recur(res, 10, turnedOn, 0, 0);

        return res;
    }
};
