//source code myfuncs.h

long long TimesTwo(long long n)
{
	return n*2;
}

long long Factorial(long long n)
{
	long long fact = 1;
	for(long long i = 1; i <= n; i++){
		fact *= i;
	}
	return fact;
}

