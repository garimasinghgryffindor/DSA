

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct nodetype{
    int data;
    struct nodetype *next;
}node;

inline unsigned int hash_value(int val);
bool hash_table_insert(node **hash_table, node *x);
void initialize_table(node **hash_table);

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res;
    int n, count=0,i;
    n = nums1Size>nums2Size ? nums1Size : nums2Size;
    node *hash_table1[1001];
    node *hash_table2[1001];
    initialize_table(hash_table1);
    initialize_table(hash_table2);
    
    for(i=0 ; i<nums1Size ; i++)
    {
        node *temp = (node*)malloc(sizeof(node));
        temp->data=nums1[i];
        temp->next=NULL;
        hash_table_insert(hash_table1,temp);
    }
    
    for(i=0 ; i<nums2Size ; i++)
    {
        node *temp = (node*)malloc(sizeof(node));
        temp->data=nums2[i];
        temp->next=NULL;
        hash_table_insert(hash_table2,temp);
    }    
    
    res = (int*)malloc(n*sizeof(int));
    
    int small = nums1Size<nums2Size ? nums1Size : nums2Size;
    
    for(i=0 ; i<1001 ; i++)
    {
        node *x=hash_table1[i];
        node *y=hash_table2[i];
        
        while(x!=NULL && y!=NULL)
        {
            res[count++]=x->data;
            x=x->next;
            y=y->next;
        }
    }
    
    res = realloc(res, count*(sizeof(int)));
    *returnSize = count;
                         
    return res;
    
}

inline unsigned int hash_value(int val)
{
    return val;
}

bool hash_table_insert(node **hash_table, node*x)
{
    if(x==NULL)
        return false;
    
    int index=hash_value(x->data);
    x->next = hash_table[index];
    hash_table[index]=x;
    
    return true;
}

void initialize_table(node **hash_table)
{
    int i;
    for(i=0 ; i<1001 ; i++)
    {
        hash_table[i]=NULL;
    }
}

