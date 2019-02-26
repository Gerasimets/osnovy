#pragma warning(disable :4996)
#include <stdio.h>
int main(void)
{
	float v1;
	float v2;
	float t;
	float s;
	printf ("v1=");
	scanf ("%f", &v1);
	printf ("v2=");
	scanf ("%f", &v2);
	printf ("t=");
	scanf ("%f", &t);
	s = ((v2 * v2) - (v1 * v1)) / t;
	printf ("distance = %f\n", s);
	return 0;
}