#include <iostream>

class IntArray
{
private:
    int *data;
    int size;
    int dummy;

public:
    IntArray() : data(nullptr), size(0), dummy(0) {}

    IntArray(int length) : size(length), dummy(0)
    {
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = 0;
    }

    IntArray(const int *arr, int length) : size(length), dummy(0)
    {
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = arr[i];
    }

    IntArray(const IntArray &other) : size(other.size), dummy(0)
    {
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    IntArray &operator=(const IntArray &other)
    {
        if (this == &other)
            return *this;

        delete[] data;

        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];

        return *this;
    }

    void resize(int newSize)
    {
        int *newData = new int[newSize];
        int limit = (newSize < size) ? newSize : size;

        for (int i = 0; i < limit; ++i)
            newData[i] = data[i];

        for (int i = limit; i < newSize; ++i)
            newData[i] = 0;

        delete[] data;
        data = newData;
        size = newSize;
    }

    int getSize() const { return size; }

    int &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            std::cerr << "[Warning] Invalid index: " << index << "\n";
            return dummy;
        }
        return data[index];
    }

    const int &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            std::cerr << "[Warning] Invalid index: " << index << "\n";
            return dummy;
        }
        return data[index];
    }

    void append(const IntArray &other)
    {
        int newSize = size + other.size;
        int *newData = new int[newSize];

        for (int i = 0; i < size; ++i)
            newData[i] = data[i];

        for (int i = 0; i < other.size; ++i)
            newData[size + i] = other.data[i];

        delete[] data;
        data = newData;
        size = newSize;
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }

    ~IntArray()
    {
        delete[] data;
    }
};

class FloatArray
{
private:
    float *data;
    int size;
    float dummy;

public:
    FloatArray() : data(nullptr), size(0), dummy(0.0f) {}

    FloatArray(int length) : size(length), dummy(0.0f)
    {
        data = new float[size];
        for (int i = 0; i < size; ++i)
            data[i] = 0.0f;
    }

    FloatArray(const float *arr, int length) : size(length), dummy(0.0f)
    {
        data = new float[size];
        for (int i = 0; i < size; ++i)
            data[i] = arr[i];
    }

    FloatArray(const FloatArray &other) : size(other.size), dummy(0.0f)
    {
        data = new float[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    ~FloatArray()
    {
        delete[] data;
    }

    FloatArray &operator=(const FloatArray &other)
    {
        if (this == &other)
            return *this;

        delete[] data;

        size = other.size;
        data = new float[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];

        return *this;
    }

    int length() const { return size; }

    void resize(int newSize)
    {
        float *newData = new float[newSize];
        for (int i = 0; i < newSize; ++i)
            newData[i] = (i < size) ? data[i] : 0.0f;

        delete[] data;
        data = newData;
        size = newSize;
    }

    float &operator[](int index)
    {
        if (index >= 0 && index < size)
            return data[index];

        std::cout << "[Warning] Invalid index: " << index << "\n";
        dummy = 0.0f;
        return dummy;
    }

    const float &operator[](int index) const
    {
        if (index >= 0 && index < size)
            return data[index];

        std::cout << "[Warning] Invalid index: " << index << "\n";
        return dummy;
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};

void testIntArray()
{
    IntArray a(5);
    for (int i = 0; i < a.getSize(); ++i)
        a[i] = i * 10;

    std::cout << "Array a:\n";
    for (int i = 0; i < a.getSize(); ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";

    IntArray b = a;
    b.resize(8);

    std::cout << "Array b (resized to 8):\n";
    for (int i = 0; i < b.getSize(); ++i)
        std::cout << b[i] << " ";
    std::cout << "\n";

    int raw[] = {9, 8, 7, 6};
    IntArray c(raw, 4);

    std::cout << "Array c from raw array:\n";
    for (int i = 0; i < c.getSize(); ++i)
        std::cout << c[i] << " ";
    std::cout << "\n";

    a = c;
    std::cout << "Array a after assignment from c:\n";
    for (int i = 0; i < a.getSize(); ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";
}

void testFloatArray()
{
    FloatArray a(5);
    for (int i = 0; i < a.length(); ++i)
        a[i] = i * 1.5f;

    std::cout << "Array a:\n";
    a.print();

    FloatArray b = a;
    b.resize(7);
    std::cout << "Array b (resized to 7):\n";
    b.print();

    float raw[] = {9.1f, 8.2f, 7.3f};
    FloatArray c(raw, 3);
    std::cout << "Array c from raw array:\n";
    c.print();

    a = c;
    std::cout << "Array a after assignment from c:\n";
    a.print();
}

void testAppendIntArray()
{
    std::cout << "Testing append() for IntArray:\n";

    IntArray a(3);
    for (int i = 0; i < 3; ++i)
        a[i] = i;

    IntArray b(2);
    b[0] = 100;
    b[1] = 200;

    std::cout << "Array a before append:\n";
    a.print();

    std::cout << "Array b:\n";
    b.print();

    a.append(b);

    std::cout << "Array a after append:\n";
    a.print();
}

int main()
{
    testIntArray();
    std::cout << "------------------------------------------------" << std::endl;
    testFloatArray();
    std::cout << "------------------------------------------------" << std::endl;
    testAppendIntArray();

    return 0;
}
