class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        // I can go like start from blue -> 1, 3, 5, so on
        // then red -> 2, 4, 6, 8 ...
        // we will see how many rows of blue can I have in that scenario
        // blue has to be sum of odd numbers
        // sum = row ^ 2
        int blueRow = sqrt(blue);
        

        // we will see how many rows of red can I have in that scenario
        // red has to be sum of even numbers
        // sum = row * (row + 1);
        int redRow = 0;
        for(int row = 9; row >= 0; row--) {
            if(red >= row*(row+1)) {
                redRow = row;
                break;
            }
        }

        int res1 = 0;
        if(blueRow > redRow) {
            res1 = min(blueRow, redRow) * 2 + 1;
        } else {
            res1 = 2*blueRow;
        }

        // trying the same with the other way around
        int redRow2 = sqrt(red);

        int blueRow2 = 0;
        for(int row = 9; row >= 0; row--) {
            if(blue >= row*(row+1)) {
                blueRow2 = row;
                break;
            }
        }

        int res2 = 0;
        if(redRow2 > blueRow2) {
            res2 = min(blueRow2, redRow2) * 2 + 1;
        } else {
            res2 = 2*redRow2;
        }

        // cout<<"blueRow : "<<blueRow<<endl;
        // cout<<"blueRow2 : "<<blueRow2<<endl;
        // cout<<"redRow : "<<redRow<<endl;
        // cout<<"redRow2 : "<<redRow2<<endl;
        return max(res1, res2);
    }
};
