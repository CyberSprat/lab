#include "cucbku.h"

int main()
{
	int fibNum=0, n=0;
	scanf("%d", &n);
	for (int i = 1;; i++) {
		fibNum = fibFunc(i);
		if (fibNum > n) {
			printf("%d is first number in Fibonachi\'s table, when bigger n\n", fibNum);
			break;
		}
	}
	fibNum = 1;
	for (int i = 1; i <= 15; i++)
		fibNum += fibFunc(i);
	printf("%d is sum 1000 nubmers in Fibonachi\'s table\n", fibNum);
	return 0;
}