#include <stdio.h>
int main( void )
{
int L;
int v2,res,Z;
res=0;
printf("L = ");
scanf("%d", &L);
while( L > 0)
{
res=res+1;
Z=L%2;
L=L/2;
}
printf("pos =%d",res);
return 0;
}
