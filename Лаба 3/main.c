#include <stdio.h>
#include <math.h>
#define YES 1
#define NO 0
#define MAXLINE 1000
void 
process_line(char buffer[]);
int main(void)
{
char line[MAXLINE];
gets(line);
process_line(line);
puts(line);
return 0;
}
void process_line(char buffer[])
{
char c;
int prev_c,flag,found,i,cnt,pos,start,j;
flag = NO;
found = NO;
prev_c = ' ';
start = 0;
i = 1;
pos = 0;
cnt = 1;
do
{
c = buffer[i];
if (c == ' ' || c == '.' || c == ',' ||
c == '\n' || c == '\0')
{
if (flag == YES)
{
cnt++;
if (found == NO)
{
for (j = start; j < i; j++)
buffer[pos++] = buffer[j];
}
}
flag = NO;
buffer[pos++] = c;
}
else
{
if (flag == NO)
start = i;
if (cnt % 2 == 0)
found = YES;
else
found = NO;
flag = YES;
}
i++;
} while (c != '\0');
}
