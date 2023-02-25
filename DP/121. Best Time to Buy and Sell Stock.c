
int maxProfit(int* prices, int pricesSize){
    int temp_profit=0 , i , temp=0 , profit=0;
    for(i=1 ; i<pricesSize ; i++)
    {
        temp = prices[i]-prices[i-1];
        temp_profit+=temp;
        if(temp_profit < 0 )
            temp_profit=0;
        temp=0;
        if(temp_profit>profit)
            profit=temp_profit;
    }
    
    return profit;
}
