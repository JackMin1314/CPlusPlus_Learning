#include<iostream>
#include<stdlib.h> // srand, rand
#include<time.h>   // time, clock_t

// 全局变量用来计算程序运行的时间
static clock_t start, finish;
static double duration;

// 相关函数的声明
void makeRandomNum(int* arr, unsigned int n);
void randomNum(int* arr, unsigned int n);

void bubbleSort(int* arr, unsigned int n);// 冒泡排序
void quickSort(int* arr, unsigned int left, unsigned int right);// 快速排序


void printNum(int* arr, unsigned int n);// 打印一个数组

// getRuntime函数的参数是一个函数指针（将一个函数作为参数传递给另一个函数需要用到函数指针）
double getRuntime(int* arr, unsigned int n, void (*pfunc)(int*, unsigned int));
// 被调函数的声明和定义时，其参数需要给出函数指针的参数类型(int*,unsigned int)，具体值需要放在前面参数

// Main程序主入口
int main() {
    unsigned int n;
    std::cout << "请输入产生n个不重复的随机数默认为0~n-1: ";
    std::cin >> n;
    int* arr = new int[n];
    duration = getRuntime(arr, n, makeRandomNum);
    std::cout << "创建" << n << "个不重复的随机数总共用时为：" << duration << "秒" << std::endl;

    std::cout << "开始进行快速排序" << std::endl;
    quickSort(arr, 0, n - 1);
    printNum(arr, n);
    std::cout << "快速排序结束" << std::endl;

    std::cout << "开始进行冒泡排序" << std::endl;
    bubbleSort(arr, n);
    printNum(arr, n);

    std::cout << "冒泡排序结束" << std::endl;
    return 0;
}

// 【功能一】创建n个不重复的随机数
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
    std::cout << "所有随机数产生完毕" << std::endl;
}
void printNum(int* arr, unsigned int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 5 == 0) std::cout << "\n"; // 五个输出一行
    }
    std::cout << std::endl;
}

// 被调函数的声明和定义时，其参数需要给出函数指针的参数类型(int*,unsigned int)，具体值需要放在前面参数
double getRuntime(int* arr, unsigned int n, void (*pfunc)(int*, unsigned int)) {
    start = clock();
    pfunc(arr, n);// 这里就用到了实际函数所需要的参数了
    finish = clock();
    double t = double((finish - start)) / 1000;// 用CLOCKS_PER_SEC也是可以的
    return t;
}

// 【功能二】两种排序算法 冒泡和快排
void bubbleSort(int* arr, unsigned int n) {
    unsigned int i, j, temp; int swapped = 0;
    for (i = 1; i < n; i++) { // 外循环len(arr)-1次，这里i从1开始是因为，内循环第i趟时，需要比较n-i次;如果i=0会导致内循环n次，下标j会数组溢出
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0) { break; } // 如果有序则结束循环
    }
}

void quickSort(int* arr, unsigned int left, unsigned int right) {
    if (left >= right)
        return;
    int key = arr[left]; // 取最左边为基数
    int i = left;
    int j = right;
    while (i < j) { // 每次先走的是基数的对面(这里最左边是基数，因而右边先走)；为了保证每次i,j相遇的时候，要交换的元素和基数符合左小右大的原则
        while (i < j && arr[j] > key) {
            j--;
        }
        arr[i] = arr[j]; // 第一次因为key保存了arr[i]，所以可以用arr[i]存arr[j]
        while (i < j && arr[i] <= key) {
            i++;
        }
        arr[j] = arr[i]; // 因为上面的arr[i]保存了arr[j]，这里新找到的arr[i]可以被上面的arr[j]保存。

    }//完成小左大右替换工作;i,j相遇时候结束循环。
    arr[i] = key;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);

}
