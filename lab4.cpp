#include <iostream>
#include <cstring>

struct Student {
    char name[50];
    char *surname;
    float id;
    float *marks;
    unsigned int size;
    Student* next; // Указатель на следующий элемент в списке
    Student* prev; 
};

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

// Функция для удаления элемента из списка по имени
void deleteNode(Student*& head, const char* nameToDelete) {
    Student* current = head;
    Student* prev = nullptr;

    while (current != nullptr && strcmp(current->name, nameToDelete) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Элемент с именем " << nameToDelete << " не найден.\n";
        return;
    }

    if (prev == nullptr) {
        // Если удаляем первый элемент
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete[] current->surname;
    delete[] current->marks;
    delete current;
}

// Функция для просмотра содержимого списка
void displayList(const Student* head) {
    const Student* current = head;

    while (current != nullptr) {
        std::cout << "Имя: " << current->name << ", Фамилия: " << current->surname << ", ID: " << current->id << ", Оценки: [";
        for (unsigned int i = 0; i < current->size; ++i) {
            std::cout << current->marks[i];
            if (i < current->size - 1) std::cout << ", ";
        }
        std::cout << "], Адрес: " << current << "\n";

        current = current->next;
    }
}

// Преобразование односвязного списка в двусвязный
void convertToDoublyLinkedList(Student*& head) {
    Student* current = head;
    Student* prev = nullptr;

    while (current != nullptr) {
        current->prev = prev;
        prev = current;
        current = current->next;
    }
}

// Преобразование односвязного списка в кольцевой
void convertToCircularLinkedList(Student*& head) {
    Student* current = head;

    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }

    if (current != nullptr) {
        current->next = head;
    }
}

int main() {
    Student* head = nullptr;

    // Пример использования функций
    insertNode(head, "John", "Doe", 1, new float[3]{90.5, 85.0, 92.3}, 3);
    insertNode(head, "Jane", "Smith", 2, new float[3]{88.0, 91.5, 89.2}, 3);
    insertNode(head, "Bob", "Johnson", 3, new float[3]{75.2, 80.5, 78.9}, 3);

    std::cout << "Исходный список:\n";
    displayList(head);

    deleteNode(head, "Jane");

    std::cout << "\nСписок после удаления элемента 'Jane':\n";
    displayList(head);

    convertToDoublyLinkedList(head);

    // Теперь вы можете использовать поле prev для двусвязного списка

    convertToCircularLinkedList(head);

    // Теперь список стал кольцевым

    return 0;
}
