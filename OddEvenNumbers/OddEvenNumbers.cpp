#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void PrintNumbers(string title, const vector<int>& numbers)
{
    cout << title << "[ ";
    for (const auto& num : numbers)
    {
        cout << num << " ";
    }
    cout << "]\n";
}

bool IsEven(int number)
{
    return number % 2 == 0;
}

bool IsOdd(int number)
{
    return !IsEven(number);
}

int main()
{
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const int size = sizeof(numbers) / sizeof(numbers[0]);

    vector<int> evenNumbers;
    vector<int> oddNumbers;

    copy_if(numbers, numbers + size, back_inserter(evenNumbers), IsEven);
    copy_if(numbers, numbers + size, back_inserter(oddNumbers), IsOdd);

    PrintNumbers("All Numbers: ", vector<int>(numbers, numbers + size));
    PrintNumbers("Even Numbers: ", evenNumbers);
    PrintNumbers("Odd Numbers: ", oddNumbers);

    return 0;
}
