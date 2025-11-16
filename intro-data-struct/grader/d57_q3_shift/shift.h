// Shift

void shift(int k) {
	// TODO: Add your code here
	node* newFirst = mHeader->next;
	while (k < 0) {
		k += mSize;
	}
	k = k % mSize;
	if (k == 0) {
		return;
	}
	while (k--) {
		newFirst = newFirst->next;
	}
	node* newLast = newFirst->prev;
	node* oldFirst = mHeader->next;
	node* oldLast = mHeader->prev;

	mHeader->next = newFirst;
	newFirst->prev = mHeader;

	mHeader->prev = newLast;
	newLast->next = mHeader;

	oldLast->next = oldFirst;
	oldFirst->prev = oldLast;
}
