#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c = 0;
	scanf("%d%d", &a, &b);
	b -= a;
	c = (-0.999999 + sqrt(1 + 4.0 * b)) / 2.0;
	b -= c * (c + 1);
	if (b > 0) { b -= c + 1; c = c * 2 + 1; }
	else c = c * 2;
	if (b > 0) c++;
	printf("%d\n", c);
}