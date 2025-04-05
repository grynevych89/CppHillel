#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>

const int SIZE = 20;         // Розмір масиву A
const int HEAP_SIZE = 10000; // Великий масив на купі

void fillArray(int arr[], int size, int min = -50, int max = 100)
{
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % (max - min + 1) + min;
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void printEvenValues(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        if (arr[i] % 2 == 0)
            std::cout << arr[i] << " ";
    std::cout << "\n";
}

void printEvenIndexs(const int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

double average(const int arr[], int size)
{
    long long sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return static_cast<double>(sum) / size;
}

int findMax(const int arr[], int size)
{
    int maxVal = std::numeric_limits<int>::min();
    for (int i = 0; i < size; ++i)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

int findMin(const int arr[], int size)
{
    int minVal = std::numeric_limits<int>::max();
    for (int i = 0; i < size; ++i)
        if (arr[i] < minVal)
            minVal = arr[i];
    return minVal;
}

// Завдання №1
void staticAndHeapArrays()
{
    int A[SIZE];
    fillArray(A, SIZE);

    std::cout << "Array A printed three times:\n";
    for (int i = 0; i < 3; ++i)
        printArray(A, SIZE);

    int *heapArr = new int[HEAP_SIZE];
    fillArray(heapArr, HEAP_SIZE);

    std::cout << "\nheapArr[1000] = " << heapArr[1000]
              << ", heapArr[2000] = " << heapArr[2000] << "\n";
    std::cout << "Sum = " << heapArr[1000] + heapArr[2000] << "\n";

    delete[] heapArr;
}

// Завдання №2
void evenValuesOnly()
{
    int A[SIZE];
    fillArray(A, SIZE);

    std::cout << "Original array:\n";
    printArray(A, SIZE);

    std::cout << "Even values only:\n";
    printEvenValues(A, SIZE);
}

// Завдання №3
void evenIndexOnly()
{
    int A[SIZE];
    fillArray(A, SIZE);

    std::cout << "Original array:\n";
    printArray(A, SIZE);

    std::cout << "Elements with even indices:\n";
    printEvenIndexs(A, SIZE);
}

// Завдання №4
void statistics()
{
    int A[SIZE];
    fillArray(A, SIZE);

    std::cout << "Array:\n";
    printArray(A, SIZE);

    std::cout << "Average: " << average(A, SIZE) << "\n";
    std::cout << "Max: " << findMax(A, SIZE) << "\n";
}

void heapStatistics()
{
    const int BIG_SIZE = 500000;
    int *bigArray = new int[BIG_SIZE];
    fillArray(bigArray, BIG_SIZE, -1000, 1000);

    std::cout << "[Heap] Average: " << average(bigArray, BIG_SIZE) << "\n";
    std::cout << "[Heap] Max: " << findMax(bigArray, BIG_SIZE) << "\n";

    delete[] bigArray;
}

// Завдання №5
void calculateVarianceAndStdDev(const int arr[], int size)
{
    double avg = average(arr, size);
    double squaredSum = 0;

    for (int i = 0; i < size; ++i)
    {
        squaredSum += (arr[i] - avg) * (arr[i] - avg);
    }

    double variance = squaredSum / size;
    double stdDev = std::sqrt(variance);

    std::cout << "Variance: " << variance << "\n";
    std::cout << "Standard Deviation: " << stdDev << "\n";
}

void processArrays()
{
    int arr[SIZE];
    fillArray(arr, SIZE, -50, 100);

    printArray(arr, SIZE);
    printEvenValues(arr, SIZE);
    printEvenIndexs(arr, SIZE);

    std::cout << "Max value: " << findMax(arr, SIZE) << "\n";
    std::cout << "Min value: " << findMin(arr, SIZE) << "\n";
    std::cout << "Average: " << average(arr, SIZE) << "\n";
    calculateVarianceAndStdDev(arr, SIZE);
}

void processLargeArray()
{
    int *largeArray = new int[HEAP_SIZE];
    fillArray(largeArray, HEAP_SIZE, -100000, 100000);

    std::cout << "First 10 elements of large array: ";
    for (int i = 0; i < 10; ++i)
        std::cout << largeArray[i] << " ";
    std::cout << "\n";

    std::cout << "Sum of elements at indices 1000 and 2000: "
              << largeArray[1000] + largeArray[2000] << "\n";

    delete[] largeArray;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    staticAndHeapArrays();
    std::cout << "------------------------------------------------" << std::endl;
    evenValuesOnly();
    std::cout << "------------------------------------------------" << std::endl;
    evenIndexOnly();
    std::cout << "------------------------------------------------" << std::endl;
    statistics();
    std::cout << std::endl;
    heapStatistics();
    std::cout << "------------------------------------------------" << std::endl;
    processArrays();
    std::cout << std::endl;
    processLargeArray();
    return 0;
}
