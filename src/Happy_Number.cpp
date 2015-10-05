#include <stdio.h>
					   //0    1     2      3,     4,   	 5,     6,     7,    8,     9
					   //0    1     0      0      0   	 0      0      1     0      0
bool predefined[10] = {false, true, false, false, false, false, false, true, false, false};

//bool isHappy(long long n, long long shallowN) {
//	long long sum = 0;
//	int digit;
//	int ret = 0;
//	do {
//		digit = (n % 10);
//		sum += digit * digit;
//		n /= 10;
//	} while (n);
//
//	if (sum == 1) {
//		return true;
//	}else if (sum == shallowN) {
//		return 0;
//	} else {
//		if (sum < 10) {
//			shallowN = sum;
//		}
//		ret += isHappy(sum, shallowN);
//	}
//	return ret;
//}

bool isHappy(long long n) {
	if (n < 10) {
		return predefined[n];
	}

	long long sum = 0;
	int digit;
	int ret = 0;
	do {
		digit = (n % 10);
		sum += digit * digit;
		n /= 10;
	} while (n);

	if (sum == 1) {
		return true;
	}else {
		ret += isHappy(sum);
	}
	return ret;
}

int main() {
	int printCase = 0;
	long long n;
	int tastCase;
//	FILE * fp;
//	fp = fopen("test.txt", "w");

//	for(int i = 0; i < 10; i++) {
//		predefined[i] = isHappy(i, i);
//		printf("%d\n", predefined[i]);
//	}

//		for(int i = 0; i < 729; i++) {
//			predefined[i] = isHappy(i);
//			printf("%d\n", isHappy(i));
//		}
	scanf("%d", &tastCase);
	while (tastCase--) {
		scanf("%lld", &n);
		printCase++;
		if (isHappy(n)) {
			printf("Case #%d: %lld is a Happy number.\n", printCase, n);
		} else {
			printf("Case #%d: %lld is an Unhappy number.\n", printCase, n);
		}
	}

}
