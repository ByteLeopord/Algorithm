/* 不使用运算符实现加减乘除 */

//加法
long long add(long long a, long long b)
{
	unsigned int carry = (unsigned int)(a & b) << 1;
	long long res = a ^ b;
	while(carry != 0){
		res = a ^ b;
		carry = (unsigned int)(a & b) << 1;
		a = res;
		b = carry;
	}
	return res;
}

//减法
//c = a - b 即 c = a + (-b)
//1.整数的相反数等于该数按位取反再加1
long long help(long long n)
{
	return add(~n, 1);
}
long long sub(long long a, long long b)
{
	return add(a, help(b));
}
//2.位运算
long long sub(long long a, long long b)
{
	while(b != 0){
		int sambit = a & b;
		a ^= sambit;
		b ^= sambit;
		a |= b;
		b <<= 1; 
	}
	return a;
}

//乘法
