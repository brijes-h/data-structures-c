#include <stdio.h>

void toh(int n, char a, char b, char c)
{
	if(n>0){
		toh(n-1, a, c, b);
		printf("\n Move a disk from %c to %c", a, c);
		toh(n-1, b, a, c);
	}
}

int main(){
	int n;
	printf("Enter the number of disks: ");
	scanf("%d", &n);
	toh(n, 'A', 'B', 'C');
return 0;
}