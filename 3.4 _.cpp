
#include<iostream>
#include<vector>
using namespace std;

template<typename T> void Find_max(vector<T> array)
{
    if(array.empty()) {
        cout << "Collection is empty!" << endl;
        return;
    }

    T max = array[0];
    for(size_t i = 1; i < array.size(); i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
    cout << "MAX: " << max << endl;
}

template<typename T> void Display(vector<T> array)
{
    if(array.empty()) {
        cout << "Collection is empty!" << endl;
        return;
    }

    for(size_t i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template<typename T> void Reverse(vector<T>& array)
{
    if(array.empty()) {
        cout << "Collection is empty!" << endl;
        return;
    }

    size_t i = 0, j = array.size() - 1;
    while(i < j)
    {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    int x;
    float f;
    char c;
    vector<int> array1;
    vector<float> array2;
    vector<char> array3;

    // Integer collection input
    cout << "Enter collection of integers (press 0 to stop):" << endl;
    while(true)
    {
        cin >> x;
        if(x == 0) break;
        array1.push_back(x);
    }

    // Float collection input
    cout << "Enter collection of floating point numbers (press 0 to stop):" << endl;
    while(true)
    {
        cin >> f;
        if(f == 0) break;
        array2.push_back(f);
    }

    // Char collection input
    cout << "Enter collection of characters (press enter to stop):" << endl;
    cin.ignore(); // Clear the input buffer
    while(true)
    {
        c = cin.get();
        if(c == '\n') break;
        array3.push_back(c);
    }

    int choice1, choice2;
    do
    {
        cout << "\nMenu Options:" << endl;
        cout << "1. Find max" << endl;
        cout << "2. Display collection" << endl;
        cout << "3. Reverse the collection" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice1;

        switch(choice1)
        {
            case 1:
                cout << "1. Collection of integers" << endl;
                cout << "2. Collection of floats" << endl;
                cout << "3. Collection of chars" << endl;
                cout << "Enter your choice: ";
                cin >> choice2;
                switch(choice2)
                {
                    case 1: Find_max(array1); break;
                    case 2: Find_max(array2); break;
                    case 3: Find_max(array3); break;
                    default: cout << "INVALID CHOICE" << endl;
                }
                break;

            case 2:
                cout << "1. Collection of integers" << endl;
                cout << "2. Collection of floats" << endl;
                cout << "3. Collection of chars" << endl;
                cout << "Enter your choice: ";
                cin >> choice2;
                switch(choice2)
                {
                    case 1: Display(array1); break;
                    case 2: Display(array2); break;
                    case 3: Display(array3); break;
                    default: cout << "INVALID CHOICE" << endl;
                }
                break;

            case 3:
                cout << "1. Collection of integers" << endl;
                cout << "2. Collection of floats" << endl;
                cout << "3. Collection of chars" << endl;
                cout << "Enter your choice: ";
                cin >> choice2;
                switch(choice2)
                {
                    case 1: Reverse(array1); Display(array1); break;
                    case 2: Reverse(array2); Display(array2); break;
                    case 3: Reverse(array3); Display(array3); break;
                    default: cout << "INVALID CHOICE" << endl;
                }
                break;

            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "INVALID CHOICE" << endl;
        }
    } while(choice1 != 0);

    return 0;
}
