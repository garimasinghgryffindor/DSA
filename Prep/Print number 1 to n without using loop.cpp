// using recursion
int main(){
    int N;
    printf("Enter a number\n");
    scanf("%d", &N);
     
    printNumber(N);
 
    return 0;
}
 
void printNumber(int N){
    if(N >= 1){
        printNumber(N-1);
        printf("%d ", N);
    }
}


// label and goto
int main()
{
    int n = 10, i = 1;
    here:
    cout<<i<<endl;
    i++;
    if(i <= n) {
        goto here;
    }

    return 0;
}

