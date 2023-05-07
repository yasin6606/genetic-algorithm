void swap(int *arr, size_t firstIdx, size_t secondIdx) {
    int temp = arr[firstIdx];

    arr[firstIdx] = arr[secondIdx];
    arr[secondIdx] = temp;
}