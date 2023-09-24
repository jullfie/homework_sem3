#include <iostream>
#include <string>
#include <algorithm>
/*
1) strlen - � C++ ���� ����������� ������� std::strlen() �� ���������� <cstring>.
2) strcpy - � C++ ���� ����������� ������� std::strcpy() �� ���������� <cstring>.
3) strcmp - � C++ ���� ����������� ������� std::strcmp() �� ���������� <cstring>.
4) strcat - � C++ ���� ����������� ������� std::strcat() �� ���������� <cstring>.
5) someString[index] - � C++ ����� ������������ �������� [] ��� ������� � �������� ������, ��������, someString[index].
6) push_back - � C++ ��� ���������� �������� � ����� ������ ����� ������������ ������� std::string::push_back().
7) pop_back - � C++ ��� �������� ���������� ������� �� ������ ����� ������������ ������� std::string::pop_back().

������� ����� �������� � C � C++ ����������� � ���, ��� � C ������ ������������ ��������� ��������, ��� �����
������ ������������ ������� �������� ('\0'). � C++ ������ ������������ ������� std::string, ������� ���������
�������� �� �������� ����� ������� � ���������� �������� ��� ������������� ������ ����� �������� �������.
����� std::string ������������� ��������� ������� ��� ������ �� ��������, ����� ��� ������������, �����������,
���������, ������ � �������� � �.�., ��� ��������� � �������� ������ �� �������� � C++.
*/

int main() {
    std::string inputString, sortedString;

    // ���� ������ �� ������������
    std::cout << "������� ������: ";
    std::getline(std::cin, inputString);

    // �������� �������� � �������������� ������ �� ������
    inputString.erase(std::remove_if(inputString.begin(), inputString.end(), [](char c) {
        return std::isspace(c) || std::ispunct(c);
        }), inputString.end());

    // ����������� ������ ��� ����������
    sortedString = inputString;

    // ���������� ������ � ���������� �������
    std::sort(sortedString.begin(), sortedString.end());

    // ����� ��������������� ������
    std::cout << "��������������� ������: " << sortedString << std::endl;

    return 0;
}
