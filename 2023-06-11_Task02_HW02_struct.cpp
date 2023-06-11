#include <iostream>
#include <Windows.h>
#include <string>

struct person
{
    int account;
    std::string name;
    float sum;
};

int change_sum(person* p) {
    // person p;
    std::string s;
    float tmpf;

    std::cout << "Введите новый баланс: ";
    try {
        std::cin >> s;
        tmpf = static_cast<float>(std::stof(s));
    }
    catch (const std::invalid_argument& tmpf) {
        return 3;
    }
    p->sum = tmpf;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    person p;
    int tmpi;
    std::string str;
    float tmpf;

    std::cout << "Введите номер счёта: ";
    try {
        std::cin >> str;
        tmpi = static_cast<int>(std::stoi(str));
    }
    catch (const std::invalid_argument& tmpi) {
        std::cout << std::endl << "Некорректные данные" << std::endl;
        system("pause");
        return 1;
    }
    p.account = tmpi;

    std::cout << "Введите имя владельца: ";
    std::cin >> p.name;

    std::cout << "Введите баланс: ";
    try {
        std::cin >> str;
        tmpf = static_cast<float>(std::stof(str));
    }
    catch (const std::invalid_argument& tmpf) {
        std::cout << std::endl << "Некорректные данные" << std::endl;
        system("pause");
        return 2;
    }
    p.sum = tmpf;

    if (change_sum(&p)) {
        std::cout << std::endl << "Некорректные данные" << std::endl;
        system("pause");
        return 3;
    }

    std::cout << "Ваш счёт: " << p.name << ", " << p.account << ", " << p.sum << std::endl;

    system("pause");
}