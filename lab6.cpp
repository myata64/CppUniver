#include <iostream>
#include <cstring>

struct Student {
    char name[50];
    char *surname;
    float id;
    float *marks;
    unsigned int size;
    Student* next;
};

// Линейный поиск в массиве
int linearSearch(const Student* array, int size, const char* key) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(array[i].name, key) == 0) {
            return i; // Вернуть индекс элемента, если найден
        }
    }
    return -1; // Вернуть -1, если элемент не найден
}

// Сортировка массива методом пузырька
void bubbleSort(Student* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(array[j].name, array[j + 1].name) > 0) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

// Двоичный поиск в отсортированном массиве
int binarySearch(const Student* array, int size, const char* key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int compareResult = strcmp(array[mid].name, key);

        if (compareResult == 0) {
            return mid; // Вернуть индекс элемента, если найден
        } else if (compareResult < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Вернуть -1, если элемент не найден
}

// Поиск в связном списке
int linkedListSearch(const Student* head, const char* key) {
    const Student* current = head;
    int index = 0;

    while (current != nullptr) {
        if (strcmp(current->name, key) == 0) {
            return index; // Вернуть индекс элемента, если найден
        }

        current = current->next;
        ++index;
    }

    return -1; // Вернуть -1, если элемент не найден
}

// Вывод содержимого массива
void displayArray(const Student* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Имя: " << array[i].name << ", Фамилия: " << array[i].surname << ", ID: " << array[i].id << "\n";
    }
}

// Функция для вставки нового элемента в начало списка
void insertNode(Student*& head, const char* name, const char* surname, float id, const float* marks, unsigned int size) {
    Student* newNode = new Student;
    strcpy(newNode->name, name);
    newNode->surname = strdup(surname); // используем strdup для динамического выделения памяти под surname
    newNode->id = id;
    newNode->marks = new float[size];
    memcpy(newNode->marks, marks, size * sizeof(float));
    newNode->size = size;

    newNode->next = head;
    head = newNode;
}

int main() {
    const int arraySize = 3;
    Student array[arraySize] = {
        {"John", "Doe", 1, new float[3]{90.5, 85.0, 92.3}, 3, nullptr},
        {"Jane", "Smith", 2, new float[3]{88.0, 91.5, 89.2}, 3, nullptr},
        {"Bob", "Johnson", 3, new float[3]{75.2, 80.5, 78.9}, 3, nullptr}
    };

    // Линейный поиск в массиве
    std::cout << "Линейный поиск в массиве:\n";
    int linearSearchResult = linearSearch(array, arraySize, "Jane");
    if (linearSearchResult != -1) {
        std::cout << "Элемент 'Jane' найден в массиве по индексу: " << linearSearchResult << "\n";
    } else {
        std::cout << "Элемент 'Jane' не найден в массиве.\n";
    }

    // Сортировка массива и вывод отсортированного массива
    bubbleSort(array, arraySize);
    std::cout << "\nОтсортированный массив:\n";
    displayArray(array, arraySize);

    // Двоичный поиск в отсортированном массиве
    std::cout << "\nДвоичный поиск в отсортированном массиве:\n";
    int binarySearchResult = binarySearch(array, arraySize, "Jane");
    if (binarySearchResult != -1) {
        std::cout << "Элемент 'Jane' найден в массиве по индексу: " << binarySearchResult << "\n";
    } else {
        std::cout << "Элемент 'Jane' не найден в массиве.\n";
    }

    // Создание связного списка
    Student* head = nullptr;
    for (int i = 0; i < arraySize; ++i) {
        insertNode(head, array[i].name, array[i].surname, array[i].id, array[i].marks, array[i].size);
    }

    // Поиск в связном списке
    std::cout << "\nПоиск в связном списке:\n";
    int linkedListSearchResult = linkedListSearch(head, "Jane");
    if (linkedListSearchResult != -1) {
        std::cout << "Элемент 'Jane' найден в связном списке по индексу: " << linkedListSearchResult << "\n";
    } else {
        std::cout << "Элемент 'Jane' не найден в связном списке.\n";
    }

    return 0;
}

