#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
void main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

	int n, b= 0, nl =0;
	char str[MAX];
	printf("Enter a string: ");
	gets(str);
	n = strlen(str);
	for(int i = 0 ; i < n ; i++){
		if(str[i] == ' ')
			b++;
	}
	 printf("blank = %d , newline = %d\n",b, nl);
}