#include<stdio.h> 
#define Z 1 
int main(void) 
{ 
long int N; 
int i, j, k; 
i = j = 0; 
scanf_s("%x", &N); 
for (int i = 0; i < 32; i++) { 
if ((((Z � i) & N))) k = i; 
} 
printf("%d\n", k); 
system("pause"); 
return 0; 
}
