class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    if(n == 0) return 1;
		    x %= M;
		    long long half = PowMod(x, n/2, M);
		    if(n%2 == 0) {
		        return (half * half)%M;
		    }
		    return (((half*half)%M)*x)%M;
		}
};
