#include<stdio.h>

unsigned getbits(unsigned x,int p,int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x,int p,int n,unsigned y)
{
	//return (~(~0 << (p + 1 - n))) & x;
	//return (((x >> (p + 1 - n) & (~0 << (p + 1 - n))) + ~(~0 << n) & y) << (p + 1 - n)) + (~(~0 << (p + 1 - n)) & x);
	
	return ~(~(~0 << n) << (p + 1 - n)) & x | ((~(~0 << n) & y) << (p + 1 - n));
}

unsigned invert(unsigned x,int p,int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n)); 
}

unsigned rightrot(unsigned x,int n)
{
	unsigned l = sizeof(x) * 8;
	n %= l;
	return x << (l - n) | x >> n;
}

unsigned bitcount(unsigned x)
{
	int i = 0;
	for(; x != 0;x &= (x - 1))
		++i;
	return i;
}

main()
{
	unsigned x = 0xf5;
	unsigned y = 0x5f;
	printf("%d\n",bitcount(0));
	return 0

}
