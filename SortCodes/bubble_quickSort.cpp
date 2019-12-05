#include<iostream>
#include<stdlib.h> // srand, rand
#include<time.h>   // time, clock_t

// ȫ�ֱ�����������������е�ʱ��
static clock_t start, finish;
static double duration;

// ��غ���������
void makeRandomNum(int* arr, unsigned int n);
void randomNum(int* arr, unsigned int n);

void bubbleSort(int* arr, unsigned int n);// ð������
void quickSort(int* arr, unsigned int left, unsigned int right);// ��������


void printNum(int* arr, unsigned int n);// ��ӡһ������

// getRuntime�����Ĳ�����һ������ָ�루��һ��������Ϊ�������ݸ���һ��������Ҫ�õ�����ָ�룩
double getRuntime(int* arr, unsigned int n, void (*pfunc)(int*, unsigned int));
// ���������������Ͷ���ʱ���������Ҫ��������ָ��Ĳ�������(int*,unsigned int)������ֵ��Ҫ����ǰ�����

// Main���������
int main() {
    unsigned int n;
    std::cout << "���������n�����ظ��������Ĭ��Ϊ0~n-1: ";
    std::cin >> n;
    int* arr = new int[n];
    duration = getRuntime(arr, n, makeRandomNum);
    std::cout << "����" << n << "�����ظ���������ܹ���ʱΪ��" << duration << "��" << std::endl;

    std::cout << "��ʼ���п�������" << std::endl;
    quickSort(arr, 0, n - 1);
    printNum(arr, n);
    std::cout << "�����������" << std::endl;

    std::cout << "��ʼ����ð������" << std::endl;
    bubbleSort(arr, n);
    printNum(arr, n);

    std::cout << "ð���������" << std::endl;
    return 0;
}

// ������һ������n�����ظ��������
void makeRandomNum(int* arr, unsigned int n) {
    randomNum(arr, n);
    printNum(arr, n);
}
void randomNum(int* arr, unsigned int n) {
    int i, j;
    srand((unsigned int)time(NULL)); // get the random value is not equal everytime
    for (i = 0; i < n; i++) {
        arr[i] = rand() % n;  // create random number
        for (j = 0; j < i; j++) { // check number is repeated or not
            if (arr[i] == arr[j]) { --i; break; } // if the number is repeated

        }
    }
    std::cout << "����������������" << std::endl;
}
void printNum(int* arr, unsigned int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 5 == 0) std::cout << "\n"; // ������һ��
    }
    std::cout << std::endl;
}

// ���������������Ͷ���ʱ���������Ҫ��������ָ��Ĳ�������(int*,unsigned int)������ֵ��Ҫ����ǰ�����
double getRuntime(int* arr, unsigned int n, void (*pfunc)(int*, unsigned int)) {
    start = clock();
    pfunc(arr, n);// ������õ���ʵ�ʺ�������Ҫ�Ĳ�����
    finish = clock();
    double t = double((finish - start)) / 1000;// ��CLOCKS_PER_SECҲ�ǿ��Ե�
    return t;
}

// �����ܶ������������㷨 ð�ݺͿ���
void bubbleSort(int* arr, unsigned int n) {
    unsigned int i, j, temp; int swapped = 0;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0) { break; } // ������������ѭ��
    }

    printNum(arr, n);
}

void quickSort(int* arr, unsigned int left, unsigned int right) {
    if (left >= right)
        return;
    int key = arr[left]; // ȡ�����Ϊ����
    int temp;
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && arr[j] > key) {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= key) {
            i++;
        }
        arr[j] = arr[i];

    }
    arr[i] = key;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);

}
