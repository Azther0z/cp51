// Split List
// Trick

void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    node *begin1 = mHeader->next;
    node *end1 = mHeader;
    for (size_t i = 0; i < (mSize + 1) / 2; i++) {
        end1 = end1->next;
    }
    node *begin2 = end1->next;
    node *end2 = mHeader->prev;

    // Somehow, these 2 if's are necessary to pass time limit
    if ((mSize + 1) / 2 > 0) {
        list1.mHeader->prev->next = begin1;
        begin1->prev = list1.mHeader->prev;
        list1.mHeader->prev = end1;
        end1->next = list1.mHeader;
        list1.mSize += (mSize + 1) / 2;
    }

    if (mSize / 2 > 0) {
        list2.mHeader->prev->next = begin2;
        begin2->prev = list2.mHeader->prev;
        list2.mHeader->prev = end2;
        end2->next = list2.mHeader;
        list2.mSize += mSize / 2;
    }

    mSize = 0;
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
}
