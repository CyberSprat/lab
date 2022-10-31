#ifndef CUCBKU_H
#define CUCBKU_H

#include <stdio.h>
#include <stdlib.h>

int fibFunc(int x) {
	int fib1 = 0, fib2 = 1;
	for (int i = 1; i <= x; i++) {
		if (i % 2 == 0)
			fib2 += fib1;
		else
			fib1 += fib2;
	}
	if (fib1 > fib2)
		return fib1;
	else if (fib1 < fib2)
		return fib2;
}

#endif
