class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_count=0;
        s+=" ";
        string x="";
        for(int i=0 ; i<s.length() ; i++)
        {
            if(s[i]!=' ')
            {
                x+=s[i];
            }
            else if(i-1>=0 && s[i-1]==' ' && s[i]==' ');
            
            else 
            {
                last_count=x.length();
                x="";
            }
        }
        
        return last_count;
    }
};
