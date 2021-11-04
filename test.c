#include <stdio.h>

void toh(int n, char from, char to, char aux)
{
    if (n==1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }

	toh(n-1, 'A', 'B', 'C');
	printf("Move disk %d from %c to %c\n", n, from, to);
	toh(n-1, 'B', 'C', 'A'); 
}

int main(){
	int n;
	printf("Enter the number of disks: ");
	scanf("%d", &n);
	toh(n, 'A', 'C', 'B');
return 0;
}