#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;

// Функция для генерации случайного имени
string generateRandomName() {
    vector<string> names = { "Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Hannah", "Isaac", "Julia", "Kate", "Liam", "Mia", "Noah", "Olivia", "Ethan", "Sophia", "Michael", "Ava", "Jacob" };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> nameDist(0, names.size() - 1);

    return names[nameDist(gen)];
}

// Функция для инициализации векторов случайными значениями
void initializeRandomVector(vector<string>& names, vector<int>& scores, int size) {
    for (int i = 0; i < size; ++i) {
        names.push_back(generateRandomName());

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> scoreDist(0, 100);
        scores.push_back(scoreDist(gen));
    }
}

// Функция для инициализации векторов значениями, введенными пользователем
void initializeUserVector(vector<string>& names, vector<int>& scores, int size) {
    for (int i = 0; i < size; ++i) {
        string name;
        cout << "Введите имя студента: ";
        getline(cin, name);
        names.push_back(name);

        int score;
        cout << "Введите оценку студента: ";
        cin >> score;
        scores.push_back(score);

        cin.ignore(); // Очистка входного потока для следующей итерации ввода имени
    }
}

// Функция для вывода векторов с помощью range-based for-loop
void printVectorRangeBased(const vector<string>& names, const vector<int>& scores) {
    cout << "Имена и оценки студентов (с помощью range-based for-loop):" << endl;
    for (const auto& name : names) {
        cout << name << " ";
    }
    cout << endl;
    for (const auto& score : scores) {
        cout << score << " ";
    }
    cout << endl;
}

// Функция для вывода векторов с помощью итератора
void printVectorIterator(const vector<string>& names, const vector<int>& scores) {
    cout << "Имена и оценки студентов (с помощью итератора):" << endl;
    for (auto it = names.begin(); it != names.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Функция для вывода векторов с помощью индексового цикла
void printVectorIndex(const vector<string>& names, const vector<int>& scores) {
    cout << "Имена и оценки студентов (с помощью индексового цикла):" << endl;
    for (int i = 0; i < names.size(); ++i) {
        cout << names[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < scores.size(); ++i) {
        cout << scores[i] << " ";
    }
    cout << endl;
}

// Функция для подсчета среднего значения оценок
float calculateAverage(const vector<int>& scores) {
    float sum = 0;
    for (const auto& score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// Функция для подсчета медианы оценок
float calculateMedian(vector<int>& scores) {
    sort(scores.begin(), scores.end());
    int size = scores.size();
    if (size % 2 == 0) {
        return (scores[size / 2 - 1] + scores[size / 2]) / 2.0;
    }
    else {
        return scores[size / 2];
    }
}

// Функция для подсчета моды оценок
vector<int> calculateMode(const vector<int>& scores) {
    unordered_map<int, int> countMap;
    int maxCount = 0;

    // Подсчитываем количество встречающихся оценок
    for (const auto& score : scores) {
        countMap[score]++;
        maxCount = max(maxCount, countMap[score]);
    }

    vector<int> modeList;

    // Находим оценки, которые встречаются максимальное количество раз (мода)
    for (const auto& score : scores) {
        if (countMap[score] == maxCount) {
            modeList.push_back(score);
        }
    }

    return modeList;
}

int main() {
    vector<string> names;
    vector<int> scores;

    int choice;
    cout << "Выберите вариант инициализации векторов:" << endl;
    cout << "1. Демонстрационный анализ на дефолтных входных значениях" << endl;
    cout << "2. Анализ на случайных входных значениях" << endl;
    cout << "3. Анализ на входных значениях от пользователя" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    cin.ignore(); // Очистка входного потока для следующей итерации ввода имени

    switch (choice) {
    case 1:
        cout << "Инициализация векторов на дефолтных значениях" << endl;
        initializeDefaultVector(names, scores);
        break;
    case 2:
        int size;
        cout << "Введите желаемый размер выборки: ";
        cin >> size;
        initializeRandomVector(names, scores, size);
        break;
    case 3:
        int userSize;
        cout << "Введите желаемый размер выборки: ";
        cin >> userSize;
        cin.ignore(); // Очистка входного потока перед инициализацией пользовательского вектора
        initializeUserVector(names, scores, userSize);
        break;
    default:
        cout << "Неверный выбор. Программа завершает работу." << endl;
        return 0;
    }

    // Вывод векторов
    printVectorRangeBased(names, scores);
    //printVectorIterator(names, scores);
    //printVectorIndex(names, scores);

    // Подсчет и вывод среднего значения оценок
    float average = calculateAverage(scores);
    cout << "Средняя оценка: " << average << endl;

    // Подсчет и вывод медианы оценок
    float median = calculateMedian(scores);
    cout << "Медиана оценок: " << median << endl;

    // Подсчет и вывод моды оценок
    vector<int> modeList = calculateMode(scores);
    cout << "Мода оценок: ";
    for (const auto& mode : modeList) {
        cout << mode << " ";
    }
    cout << endl;

    // Вывод имен студентов соответствующих моде
    cout << "Имена студентов соответствующие моде: ";
    for (int i = 0; i < scores.size(); ++i) {
        if (scores[i] == modeList[0]) {
            cout << names[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
//Программа предлагает пользователю выбрать вариант инициализации векторов.После выбора программа инициализирует векторы и выводит их содержимое.Затем программа подсчитывает и выводит среднее значение, медиану и моду оценок.Если список оценок является многомодальным, то программа выводит все моды.В конце программа также выводит имена студентов, оценки которых соответствуют моде.
