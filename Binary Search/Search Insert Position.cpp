int searchInsert(int* nums, int numsSize, int target){
    int lb,ub,mid,f=0;
    lb=0;
    ub=numsSize-1;
    
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(target == nums[mid])
        {
            f=1;
            break;
        }
        
        else if(target < nums[mid])
        {
            ub=mid-1;
        }
        
        else
        {
            lb=mid+1;
        }
    }
    
    if(f==1)
    return mid;
    
    else if(target<nums[mid])
    return mid;
    
    else
    return mid+1;
}


LEETCODE 35
  
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.




