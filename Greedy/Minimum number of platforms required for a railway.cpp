// extension of activity selection problem

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int res = 1, count = 1;
    int i=1 , j=0;
    
    while(i<n && j<n) {
        if(at[i] <= dt[j]) {
            count++;
            i++;
        } else {
            count--;
            j++;
        }
        res = max(res,count);
    }

    return res;
    
}

