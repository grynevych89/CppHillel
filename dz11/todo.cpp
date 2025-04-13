#include <iostream>
#include "glfwbgi.h"


int findMinIndexFrom(const int arr[], int size, int startIndex)
{
    int minIndex = startIndex;
    for (int i = startIndex + 1; i < size; ++i)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void swapWithMinInTail(int arr[], int size, int start)
{
    int minIndex = findMinIndexFrom(arr, size, start);
    std::swap(arr[start], arr[minIndex]);
}

void fullSelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        swapWithMinInTail(arr, size, i);
    }
}

// Завдання №1.1
void findMinIndexFrom()
{
    const int size = 13;
    int A[size] = {-10, 7, 2, -2, -9, -1, 4, -1, 8, -5, 6, -6, -4};

    int start = 3;
    int minIndex = findMinIndexFrom(A, size, start);

    std::cout << "Min element from index " << start << ": " << A[minIndex] << " (index " << minIndex << ")\n";
}

// Завдання №1.2
void printSwapWithMinInTail()
{
    const int size = 13;
    int A[size] = {-10, 7, 2, -2, -9, -1, 4, -1, 8, -5, 6, -6, -4};

    std::cout << "Before swap:\n";
    printArray(A, size);

    swapWithMinInTail(A, size, 3);

    std::cout << "\nAfter swap from index 3:\n";
    printArray(A, size);
}

// Завдання №1.3
void printFullSelectionSort()
{
    const int size = 13;
    int A[size] = {15, 24, -5, 12, 3, 27, 11, 14, 18, 21, 19, 31, 7};
    int B[size] = {9, -4, 27, 3, -12, 16, 0, -1, 8, 5, 14, -7, 11};

    std::cout << "Before sort:\n";
    printArray(A, size);
    printArray(B, size);

    fullSelectionSort(A, size);
    fullSelectionSort(B, size);

    std::cout << "\nAfter full selection sort:\n";
    printArray(A, size);
    printArray(B, size);
}

// Завдання №2

// Завдання №3

int main()
{
    // findMinIndexFrom();
    // std::cout << "------------------------------------------------" << std::endl;

    // printSwapWithMinInTail();
    // std::cout << "------------------------------------------------" << std::endl;

    // printFullSelectionSort();
    // std::cout << "------------------------------------------------" << std::endl;

    return 0;
}
