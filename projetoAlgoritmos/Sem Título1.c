#include <stdio.h>

int main()
{
	int n[3][5] = {{1,2,0,-4,3},{6,1,10,2,3}},x,y,pe=1,total=0;
	
	for(y=0;y<5;y++)
	{
		for(x=0;x<2;x++)
		pe=pe*n[x][y];

	total=total+pe;
	pe=1;
	}

printf("%i", total);
return 0;
}

