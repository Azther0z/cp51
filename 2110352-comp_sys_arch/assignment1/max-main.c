#include <stdio.h>
int max1(int a, int b) {
	return (a > b) ? a : b;
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int result;
	for (int i = 0; i < 1e8; i++) {
		result = max1(a, b);
	}
	printf("%d", result);
	return 1;
}