#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

void fillArray(int arr[], int size, int min = -50, int max = 100)
{
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % (max - min + 1) + min;
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void ClearValue(int arr[], int size, int badValue)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == badValue)
        {
            arr[i] = 0;
        }
    }
}

// Завдання №1
void printAlternatingFromEnds(const int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        if (left == right)
        {
            std::cout << arr[left] << " ";
        }
        else
        {
            std::cout << arr[left] << " " << arr[right] << " ";
        }
        ++left;
        --right;
    }
    std::cout << "\n";
}

void alternatingFromEnds()
{
    int arr12[12];
    int arr13[13];

    fillArray(arr12, 12);
    fillArray(arr13, 13);

    std::cout << "Array with 12 elements:\n";
    for (int i = 0; i < 12; ++i)
        std::cout << arr12[i] << " ";
    std::cout << "\nOutput:\n";
    printAlternatingFromEnds(arr12, 12);

    std::cout << "\nArray with 13 elements:\n";
    for (int i = 0; i < 13; ++i)
        std::cout << arr13[i] << " ";
    std::cout << "\nOutput:\n";
    printAlternatingFromEnds(arr13, 13);
}

// Завдання №2
void printClearValue()
{
    const int size = 13;
    // я спеціально не використовував рандом, для наглядності чисел по прикладу.
    int A[size] = {-10, 7, 2, -2, -10, -1, 4, -1, 8, -12, 6, -13, -4};

    std::cout << "Before clearing:\n";
    printArray(A, size);

    ClearValue(A, size, 8);

    std::cout << "\nAfter clearing value 8:\n";
    printArray(A, size);
}

// Завдання №3
int countWords(const char *text)
{
    int wordCount = 0;
    bool inWord = false;

    while (*text != '\0')
    {
        if (*text == ' ' || *text == '\t' || *text == '\n')
        {
            inWord = false;
        }
        else if (!inWord)
        {
            inWord = true;
            wordCount++;
        }

        text++;
    }

    return wordCount;
}

void displayWordCount(const char *text)
{
    std::cout << "Number of words: " << countWords(text) << std::endl;
}

// Завдання №4
void countVowelsAndConsonants(const char *str)
{
    int vowels = 0;
    int consonants = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        char ch = tolower(str[i]);
        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                ++vowels;
            }
            else
            {
                ++consonants;
            }
        }
    }
    std::cout << "Vowels: " << vowels << std::endl;
    std::cout << "Consonants: " << consonants << std::endl;
}

// Завдання №5
void swapMinWithFirst(int arr[], int size)
{
    if (size <= 1)
        return;

    int minIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    if (minIndex != 0)
    {
        int temp = arr[0];
        arr[0] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printSwapMinWithFirst()
{
    int arr[] = {15, 24, -5, 12, 3, 27, 11, 14, 18, 21, 19, 31, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before swapping:\n";
    printArray(arr, size);

    swapMinWithFirst(arr, size);

    std::cout << "After swapping:\n";
    printArray(arr, size);
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(0)));

    alternatingFromEnds();
    std::cout << "------------------------------------------------" << std::endl;
    printClearValue();
    std::cout << "------------------------------------------------" << std::endl;
    displayWordCount("The quick brown fox jumps over the lazy dog");
    displayWordCount("The ");
    displayWordCount("    ");
    std::cout << "------------------------------------------------" << std::endl;
    countVowelsAndConsonants("The quick brown fox jumps over the lazy dog");
    std::cout << "------------------------------------------------" << std::endl;
    printSwapMinWithFirst();
    return 0;
}