Nth Root of a Number using Binary Search

Code Studio

int NthRoot(int n, int m) {
  int l = 0, r = m, mid;
  bool flag = true;
  while(l<=r) {
    mid = l + (r-l)/2;
    int res = 1;
    flag = true;

    if(sqrt(INT_MAX) < mid) {
      r = mid-1;
      continue;
    }

    for(int i=0 ; i<n ; i++) {
      res*=mid;
      
      if(res > m) {
        flag = false;
        break;
      }
    }

    if(res == m) {
      return mid;
    } else if(res > m) {
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  return -1;
}
