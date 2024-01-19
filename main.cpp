#include <iostream>

void printArray(int num[], int length) {
    std::cout << "Array: ";
    for (int i = 0; i < length; ++i) {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;
}

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertSort (int num[], int length) {
    if (num == NULL && length <= 0) {
        return;
    }

    for (int i = 1; i < length; ++i) {
        int j = i - 1;
        int temp = num[i];

        for (j; j >= 0 ; j-- ) {
            if (temp < num[j]) {
                num[j + 1] = num[j];
            } else {
                break;
            }
        }
        num[j + 1] = temp;
    }

}

void bubbleSort(int num[], int len) {
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = 1; j < len - i; j++) {
            if (num[j - 1] > num[j]) {
                int temp = num[j];
                num[j] = num[j - 1];
                num[j - 1] = temp;
            }
        }
    }
}


void quickSort (int num[], int length, int begin, int end) {
    int j, i;
    if (begin < end) {
        i = begin + 1;
        j = end;
        while (i < j) {
            if (num[i] > num[begin]) {
                swap(num[i], num[j]);
                j--;
            } else {
                i++;
            }
        }
        if (num[i] >= num[begin]) {
            i--;
        }
        swap(num[i], num[begin]);
        quickSort(num, length, begin, i);
        quickSort(num, length, j, end);
    }
}

void heapify (int num[], int length, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < length && num[left] > num[largest]) {
        largest = left;
    }

    if (right < length && num[right] > num[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(num[i], num[largest]);
        heapify(num, length, largest);
    }
}

void heapSort (int num[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(num, length, i);
    }

    for (int i = length - 1; i >= 0; i--) {
        swap(num[0], num[i]);
        heapify(num, i, 0);
    }
}

void mergeSort (int num[], int length) {
    int *n = num;
    int *b = new int[length];

    for (int seg = 1; seg < length; seg += seg) {
        for (int start = 0; start < length; start += seg + seg) {
            int low = start, mid = std::min(start + seg, length), high = std::min(start + seg + seg, length);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2) {
                b[k++] = n[start1] < n[start2] ? n[start1++] : n[start2++];
            }
            while (start1 < end1) {
                b[k++] = n[start1++];
            }
            while (start2 < end2) {
                b[k++] = n[start2++];
            }
        }
        int *temp = n;
        n = b;
        b = temp;
    }

    if (n != num) {
        for (int i = 0; i < length; i++) {
            b[i] = n[i];
        }
            b = n;
        }

        delete[] b;
}

int maxBit (const int num[]) {
    int max_num = num[0];
    for (int i = 1; i < 9; i++) {
        if (max_num < num[i]) {
            max_num = num[i];
        }
    }

    int a = 0;
    while (max_num > 0) {
        a++;
        max_num /= 10;
    }

    return a;
}

int getDigit (int num, int d) {
    int a = 1;
    while (d > 1) {
        a *= 10;
        d--;
    }
    return (num / a) % 10;
}

void radixSort (int num[]) {
    int d = maxBit(num);
    int *tmp = new int[9];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) {
        for (j = 0; j < 10; j++) {
            count[j] = 0;
        }
        for (j = 0; j < 9; j++) {
            k = getDigit(num[j], i);
            count[k]++;
        }
        for (j = 1; j < 10; j++) {
            count[j] = count[j - 1] + count[j];
        }
        for (j = 8; j >= 0; j--) {
            k = getDigit(num[j], i);
            tmp[count[k] - 1] = num[j];
            count[k]--;
        }
        for (j = 0; j < 9; j++) {
            num[j] = tmp[j];
        }
        radix = radix * 10;
    }
    delete[] tmp;
    delete[] count;
}

void selectSort (int num[], int length) {
    int i, j, k;
    for (i = 0; i < length; i++) {
        k = i;
        for (j = i + 1; j < length; j++) {
            if (num[j] < num[k]) {
                k = j;
            }
        }
        if (k != i) {
            swap(num[i], num[k]);
        }
    }
}

void shellSort (int num[], int length) {
    int i, j, k;
    for (i = length / 2; i > 0; i /= 2) {
        for (j = i; j < length; j++) {
            for (k = j - i; k >= 0 && num[k] > num[k + i]; k -= i) {
                swap(num[k], num[k + i]);
            }
        }
    }
}

int main() {
    int array1[] = {9,1,8,2,7,3,6,4,5};
    int length = 9;
    std::cout << "Original: ";
    printArray(array1, length);

    insertSort(array1, length);

    std::cout << "Insert sorted: ";
    printArray(array1, length);

    int array2[] = {9,1,8,2,7,3,6,4,5};
    std::cout << "Original: ";
    printArray(array2, length);

    bubbleSort(array2, length);

    std::cout << "Bubble sorted: ";
    printArray(array2, length);

    int array3[] = {9,1,8,2,7,3,6,4,5};
    std::cout << "Original: ";
    printArray(array3, length);

    quickSort(array3, length, 0, length - 1);

    std::cout << "Quick sorted: ";
    printArray(array3, length);

    int array4[] = {9,1,8,2,7,3,6,4,5};
    std::cout << "Original: ";
    printArray(array4, length);

    heapSort(array4, length);

    std::cout << "Heap sorted: ";
    printArray(array4, length);

    int array5[] = {9,1,8,2,7,3,6,4,5};
    std::cout << "Original: ";
    printArray(array5, length);

    mergeSort(array5, length);

    std::cout << "Merge sorted: ";
    printArray(array5, length);

    int array6[] = {19,111,84,2,70,31,6,4555,594};
    std::cout << "Original: ";
    printArray(array6, length);

    radixSort(array6);

    std::cout << "Radix sorted: ";
    printArray(array6, length);

    int array7[] = {9,1,8,2,7,3,6,4,5};
    std::cout << "Original: ";
    printArray(array7, length);

    selectSort(array7, length);

    std::cout << "Select sorted: ";
    printArray(array7, length);

    int array8[] = {9,1,8,2,7,3,6,4,5};
    std::cout << "Original: ";
    printArray(array8, length);

    shellSort(array8, length);

    std::cout << "Shell sorted: ";
    printArray(array8, length);

    return 0;

}
