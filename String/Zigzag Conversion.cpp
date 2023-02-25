class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>temp(numRows, "");
        if(numRows == 1){
            return s;
        }
        string res="";
        int flow = 1;
        //1-> down and 0-> up
        int pos = 0;
        for(int i=0 ; i<s.length() ; i++) {
            temp[pos]+=s[i];
            if(i%(numRows-1)==0) {
                // requires the flow to be changed
                flow = 1-flow;
            }
            if(flow==0) {
                pos++;
            } else {
                pos--;
            }
        }
        
        for(int i=0 ; i<numRows ; i++) {
            res += temp[i];
        }
        return res;
    }
};

//  p  a  y  p  a  l  i  s  h  i  r  i  n  g
//  0  1  2  3  4  5  6  7  8  9 10  11 12 13  

// top =>   0 6 12
// mid =>   1 5 7 9 13
// mid2.0=> 2 4 8 10
// bottom=> 3 9



The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
