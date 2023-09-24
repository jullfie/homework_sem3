#include <iostream>
#include <string>
#include <algorithm>
/*
1) strlen - в C++ есть аналогичная функция std::strlen() из библиотеки <cstring>.
2) strcpy - в C++ есть аналогичная функция std::strcpy() из библиотеки <cstring>.
3) strcmp - в C++ есть аналогичная функция std::strcmp() из библиотеки <cstring>.
4) strcat - в C++ есть аналогичная функция std::strcat() из библиотеки <cstring>.
5) someString[index] - в C++ можно использовать оператор [] для доступа к символам строки, например, someString[index].
6) push_back - в C++ для добавления символов в конец строки можно использовать функцию std::string::push_back().
7) pop_back - в C++ для удаления последнего символа из строки можно использовать функцию std::string::pop_back().

Разница между строками в C и C++ заключается в том, что в C строки представлены массивами символов, где конец
строки обозначается нулевым символом ('\0'). В C++ строки представлены классом std::string, который позволяет
работать со строками более удобным и безопасным способом без необходимости явного учета нулевого символа.
Класс std::string предоставляет множество методов для работы со строками, таких как конкатенация, копирование,
сравнение, доступ к символам и т.д., что облегчает и упрощает работу со строками в C++.
*/

int main() {
    std::string inputString, sortedString;

    // Ввод строки от пользователя
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);

    // Удаление пробелов и пунктуационных знаков из строки
    inputString.erase(std::remove_if(inputString.begin(), inputString.end(), [](char c) {
        return std::isspace(c) || std::ispunct(c);
        }), inputString.end());

    // Копирование строки для сортировки
    sortedString = inputString;

    // Сортировка строки в алфавитном порядке
    std::sort(sortedString.begin(), sortedString.end());

    // Вывод отсортированной строки
    std::cout << "Отсортированная строка: " << sortedString << std::endl;

    return 0;
}
