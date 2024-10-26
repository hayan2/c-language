#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// char array "666"

int main(void) {
	char arr[10] = { '0', };
	char res[10] = { '0', };
	int count = 1, n;
	
	arr[0] = '6';
	arr[1] = '6';
	arr[2] = '6';	
	
	scanf("%d", &n);

	while (n != count) {
		int len = strlen(arr) - 1;		
		// increase 1 while
		while (1) {
			if (arr[len] == '9') {
				if (len != 0) {
					if (arr[len] == '9' && arr[len - 1] == '9') {
						arr[len--] = '0';
					}
					else {
						arr[len] = '0';
						arr[len - 1]++;
						break;
					}
				}	
				else {
					arr[len] = '1';
					len = strlen(arr);
					arr[len] = '0';
					break;
				}
			}
			else {
				arr[len]++;
				break;
			}
		}
		
		for (int i = strlen(arr) - 1; i > 1; i--) {
			if (arr[i] == '6' && arr[i - 1] == '6' && arr[i - 2] == '6') {
				count++;
				break;
			}
		}
	}

	for (int i = 0; i < strlen(arr); i++) {
		res[i] = arr[i];
	}

	printf("%s", res);

	return 0;
}