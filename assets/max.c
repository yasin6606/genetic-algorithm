int max(int *arr, int size) {
    int temp = arr[0];

    for (int i = 0; i < size; i++)
        if (arr[i] > temp)
            temp = arr[i];

    return temp;
}