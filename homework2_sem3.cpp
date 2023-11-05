#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;

// ������� ��� ��������� ���������� �����
string generateRandomName() {
    vector<string> names = { "Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Hannah", "Isaac", "Julia", "Kate", "Liam", "Mia", "Noah", "Olivia", "Ethan", "Sophia", "Michael", "Ava", "Jacob" };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> nameDist(0, names.size() - 1);

    return names[nameDist(gen)];
}

// ������� ��� ������������� �������� ���������� ����������
void initializeRandomVector(vector<string>& names, vector<int>& scores, int size) {
    for (int i = 0; i < size; ++i) {
        names.push_back(generateRandomName());

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> scoreDist(0, 100);
        scores.push_back(scoreDist(gen));
    }
}

// ������� ��� ������������� �������� ����������, ���������� �������������
void initializeUserVector(vector<string>& names, vector<int>& scores, int size) {
    for (int i = 0; i < size; ++i) {
        string name;
        cout << "������� ��� ��������: ";
        getline(cin, name);
        names.push_back(name);

        int score;
        cout << "������� ������ ��������: ";
        cin >> score;
        scores.push_back(score);

        cin.ignore(); // ������� �������� ������ ��� ��������� �������� ����� �����
    }
}

// ������� ��� ������ �������� � ������� range-based for-loop
void printVectorRangeBased(const vector<string>& names, const vector<int>& scores) {
    cout << "����� � ������ ��������� (� ������� range-based for-loop):" << endl;
    for (const auto& name : names) {
        cout << name << " ";
    }
    cout << endl;
    for (const auto& score : scores) {
        cout << score << " ";
    }
    cout << endl;
}

// ������� ��� ������ �������� � ������� ���������
void printVectorIterator(const vector<string>& names, const vector<int>& scores) {
    cout << "����� � ������ ��������� (� ������� ���������):" << endl;
    for (auto it = names.begin(); it != names.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// ������� ��� ������ �������� � ������� ����������� �����
void printVectorIndex(const vector<string>& names, const vector<int>& scores) {
    cout << "����� � ������ ��������� (� ������� ����������� �����):" << endl;
    for (int i = 0; i < names.size(); ++i) {
        cout << names[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < scores.size(); ++i) {
        cout << scores[i] << " ";
    }
    cout << endl;
}

// ������� ��� �������� �������� �������� ������
float calculateAverage(const vector<int>& scores) {
    float sum = 0;
    for (const auto& score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// ������� ��� �������� ������� ������
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

// ������� ��� �������� ���� ������
vector<int> calculateMode(const vector<int>& scores) {
    unordered_map<int, int> countMap;
    int maxCount = 0;

    // ������������ ���������� ������������� ������
    for (const auto& score : scores) {
        countMap[score]++;
        maxCount = max(maxCount, countMap[score]);
    }

    vector<int> modeList;

    // ������� ������, ������� ����������� ������������ ���������� ��� (����)
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
    cout << "�������� ������� ������������� ��������:" << endl;
    cout << "1. ���������������� ������ �� ��������� ������� ���������" << endl;
    cout << "2. ������ �� ��������� ������� ���������" << endl;
    cout << "3. ������ �� ������� ��������� �� ������������" << endl;
    cout << "��� �����: ";
    cin >> choice;
    cin.ignore(); // ������� �������� ������ ��� ��������� �������� ����� �����

    switch (choice) {
    case 1:
        cout << "������������� �������� �� ��������� ���������" << endl;
        initializeDefaultVector(names, scores);
        break;
    case 2:
        int size;
        cout << "������� �������� ������ �������: ";
        cin >> size;
        initializeRandomVector(names, scores, size);
        break;
    case 3:
        int userSize;
        cout << "������� �������� ������ �������: ";
        cin >> userSize;
        cin.ignore(); // ������� �������� ������ ����� �������������� ����������������� �������
        initializeUserVector(names, scores, userSize);
        break;
    default:
        cout << "�������� �����. ��������� ��������� ������." << endl;
        return 0;
    }

    // ����� ��������
    printVectorRangeBased(names, scores);
    //printVectorIterator(names, scores);
    //printVectorIndex(names, scores);

    // ������� � ����� �������� �������� ������
    float average = calculateAverage(scores);
    cout << "������� ������: " << average << endl;

    // ������� � ����� ������� ������
    float median = calculateMedian(scores);
    cout << "������� ������: " << median << endl;

    // ������� � ����� ���� ������
    vector<int> modeList = calculateMode(scores);
    cout << "���� ������: ";
    for (const auto& mode : modeList) {
        cout << mode << " ";
    }
    cout << endl;

    // ����� ���� ��������� ��������������� ����
    cout << "����� ��������� ��������������� ����: ";
    for (int i = 0; i < scores.size(); ++i) {
        if (scores[i] == modeList[0]) {
            cout << names[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
//��������� ���������� ������������ ������� ������� ������������� ��������.����� ������ ��������� �������������� ������� � ������� �� ����������.����� ��������� ������������ � ������� ������� ��������, ������� � ���� ������.���� ������ ������ �������� ��������������, �� ��������� ������� ��� ����.� ����� ��������� ����� ������� ����� ���������, ������ ������� ������������� ����.
