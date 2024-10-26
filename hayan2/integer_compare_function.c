int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2) {
		return -1;
	}
	if (num2 < num1) {
		return 1;
	}

	return 0;
}

int compare(const void* a, const void* b) {
	const int* A = a, * B = b;

	return (*A > *B) - (*A < *B);
}