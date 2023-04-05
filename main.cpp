//Задача №1. Объявить указатели на две переменные указанного типа(double). Используя указатели
//произвести операции сложения и вычитания над переменными. Вывести адреса
//указателей. Типы переменных указаны в таблице
#include <iostream>

int main()
{
    double a = 5.5, b = 3.2;
    double *ptr_a = &a, *ptr_b = &b;

    std::cout << "Адрес переменной a: " << ptr_a << std::endl;
    std::cout << "Адрес переменной b: " << ptr_b << std::endl;

    std::cout << "Результат сложения a и b: " << *ptr_a + *ptr_b << std::endl;
    std::cout << "Результат вычитания b из a: " << *ptr_a - *ptr_b << std::endl;

    return 0;
}

//Задача №2. Написать функцию для обмена значений переменных, указанных выше. Передача по
//указателю. Выполнить программу по шагам и выписать в тетрадь адреса указателей
//и величины переменных.

#include <iostream>

void swap(double* a, double* b){
    double mem = *a;
    *a = *b;
    *b = mem;
}

int main(){
    double a1 = 4.7;
    double b1 = 5.4;

    std::cout<<"Адресс переменной а1: "<< &a1 <<". Величина а1: "<< a1 <<std::endl;
    std::cout << "Aдресс переменной b1: " << &b1 << ", величина b1: " << b1 << std::endl;
    std::cout << "Aдресс указателя a1: " << &*(&a1) << ", величина указателя a1: " << *&a1 << std::endl;
    std::cout << "Aдресс указателя b1: " << &*(&b1) << ", величина указателя b1: " << *&b1 << std::endl;

    std::cout << "До: a1 = " << a1 << ", b1 = " << b1 << std::endl;

        swap(&a1, &b1);

    std::cout << "После: a1 = " << a1 << ", b1 = " << b1 << std::endl;

        return 0;
    }

//Задача №3. Объявить динамический массив. Размер массива задаёт пользователь. Заполнить
//массив случайными числами. Вывести на экран адреса и значения элементов
//массива
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    double *arr = new double[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = (double)rand() / RAND_MAX * 100.0;
        std::cout << "Адрес элемента " << i << ": " << &arr[i] << ", значение: " << arr[i] << std::endl;
    }

    delete[] arr;
    return 0;
}
//Задача №4. Объявить сущность и описать её свойства. Объявить динамический массив
//сущностей. Реализовать функцию, которая изменяет значения элемента (структура)
//массива. Заполнить атрибуты числовыми и текстовыми значениями (диапазон
//значений определить самостоятельно).
#include <iostream>
#include <string>

struct Shoe {
    std::string brand;
    std::string model;
    int size;
    double price;
};

void changeShoe(Shoe* shoes, int index, std::string newBrand, std::string newModel, int newSize, double newPrice) {
    shoes[index].brand = newBrand;
    shoes[index].model = newModel;
    shoes[index].size = newSize;
    shoes[index].price = newPrice;
}

int main() {
    const int n = 3;

    Shoe shoes[n] = {
        { "Brand 1", "Model 1", 36, 29.99 },
        { "Brand 2", "Model 2", 37, 59.99 },
        { "Brand 3", "Model 3", 38, 89.99 }
    };

    std::cout << "Исходный массив:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Обувь " << i+1 << ": Бренд - " << shoes[i].brand << ", Модель - " << shoes[i].model << ", Размер - "
            << shoes[i].size << ", Цена - " << shoes[i].price << std::endl;
    }

    int index;
    std::cout << "Введите индекс элемента, который хотите изменить: ";
    std::cin >> index;

    std::string newBrand;
    std::string newModel;
    int newSize;
    double newPrice;

    std::cout << "Введите новое значение бренда: ";
    std::cin >> newBrand;
    std::cout << "Введите новое значение модели: ";
    std::cin >> newModel;
    std::cout << "Введите новое значение размера: ";
    std::cin >> newSize;
    std::cout << "Введите новое значение цены: ";
    std::cin >> newPrice;

    changeShoe(shoes, index, newBrand, newModel, newSize, newPrice);

    std::cout << "Измененный массив:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Обувь " << i+1 << ": Бренд - " << shoes[i].brand << ", Модель - " << shoes[i].model << ", Размер - "
            << shoes[i].size << ", Цена - " << shoes[i].price << std::endl;
    }

    return 0;
}
