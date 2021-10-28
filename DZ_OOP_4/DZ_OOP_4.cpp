
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <string>

using namespace std;
/*Добавить в контейнерный класс, который был написан в этом уроке, методы:
для удаления последнего элемента массива (аналог функции pop_back() в векторах)
для удаления первого элемента массива (аналог pop_front() в векторах)
для сортировки массива
для вывода на экран элементов.
*/
class ArrayInt
{
private:
    int* data;
    int length;
public:
    ArrayInt() : length(0), data(nullptr) {};

    ArrayInt(int inLength) : length(inLength)
    {
        assert(length >= 0);
        if (length > 0)
        {
            data = new int[length];
        }
        else
            data = nullptr;
    }

    void erase()
    {
        if (length > 0)
        {
            delete[] data;
            data = nullptr;
            length = 0;
        }
    }

    int getLength() const {
        return length;
    }

    int& operator[](int index)
    {
        return data[index];
    }

    void a_pop_back()
    {

        assert(length != 0);

        if (length == 1)
        {
            erase();
        }
        else
        {
            int* new_data = new int[length - 1];

            for (int i = 0; i < length - 1; i++) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            length--;
        }
    }

    void a_pop_up()
    {
        assert(length != 0);

        if (length == 1)
        {
            erase();
        }
        else
        {
            int* new_data = new int[length - 1];

            for (int i = 0; i < length - 1; i++) {
                new_data[i] = data[i + 1];
            }

            delete[] data;
            data = new_data;
            length--;
        }
    }

    void sort()
    {
        assert(length != 0);

        int tempIndex = 0;
        int lastIndex = length - 1;
        int temp;

        while (lastIndex > 0)
        {
            if (data[tempIndex] > data[tempIndex + 1])
            {
                temp = data[tempIndex];
                data[tempIndex] = data[tempIndex + 1];
                data[tempIndex + 1] = temp;
            }

            if (tempIndex == lastIndex - 1)
            {
                tempIndex = 0;
                lastIndex--;
            }
            else
            {
                tempIndex++;
            }
        }
    }

    void print() const {
        setlocale(LC_ALL, "rus");

        assert(length != 0);

        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << "Размер массива: " << length << endl;
    }

    ~ArrayInt() {
        delete[] data;
    }
};

/*Task 2
Дан вектор чисел, требуется выяснить, сколько среди них различных. 
Постараться использовать максимально быстрый алгоритм.*/

 void printVector(std::vector<int>& input)
 {
        cout << "\n";
         for (vector<int>::iterator it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";
}
 int countUniqueNumbers(std::vector<int> input)
{
    sort(input.begin(), input.end());
    vector<int>::iterator it;
    it = std::unique(input.begin(), input.end());
    input.resize(std::distance(input.begin(), it));
   
    return input.size();
}
 


int main()
{ 
    setlocale(LC_ALL, "rus");
    {
        
        int size = 0;
        cout << "Введите количество эллементов массива: ";
        cin >> size;
        ArrayInt array(size);
        for (int j = 0; j < size; j++)
        {
            array[j] = rand() % 50;
        }
        array.a_pop_back();
        array.a_pop_up();
        array.print();
    }


    //Task 2

   
    vector<int> array = { 2, 3, 6, 6, 25, 6, 7, 5, 1, 1, 2, 11, 66, 999 };
    cout << "\nНачальный массив: ";
    printVector(array);
    int count = countUniqueNumbers(array);
    cout << "\nУникальные номера: " << count;

   return 0;

}


