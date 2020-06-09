#include <iostream> 
using namespace std; 	


int count_prime_div(int n)
{
    int k = 0;
    for(int i = 2; (i <= n) && (n > 1); i++)
    {
        if (n % i == 0) k++;
        while (n % i == 0)
        {
            n /= i;
        }
    }
	return k;
}


int main()
{
    
	int n, a, res, max_count_div = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		int cpd = count_prime_div(a);
		if ((max_count_div < cpd) || ((max_count_div == cpd) && (a < res)))
		{
			res = a;
			max_count_div = cpd; 
		}
	}
	
	cout << res << endl;

	return 0;
}
