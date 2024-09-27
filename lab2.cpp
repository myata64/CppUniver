#include <iostream>
#include <locale>
//using namespace std;

// 1.Определить структурный тип, содержащий следующие поля:
struct Student { 
    char name[50]; //1.1 символьный массив для хранения строки
    char* surname; //1.2 указатель surname на тип char
    	//дополнительные поля из варианта
    float identifier; //переменная типа float
    float* dynamicArray; //указатель dynamicArray на тип float
    unsigned int arraySize; 
    	//дополнительные поля из задания
    int age;
};
//У половины функций одним из аргументов должен быть указатель на структурный тип, у другой половины - ссылка. 
// 2. Определить функции:
	//2.1 Инициализация структуры
		// -> используется для обращения к членам структуры или объекта, когда имеется указатель на этот объект
void initializeStudent(Student* student) { 		//ф-ция принимает стркт. Student через указатель
    student->surname = nullptr;                         //Уст. указатель внутри стркт. на nullptr(отсутствие данных у указателя surname)
    student->dynamicArray = nullptr;			//Уст. указатель внутри стркт. на nullptr(отсутствие данных)
    student->arraySize = 0;				//Уст. указатель внутри стркт. на начало массива с 0
}
	//2.2 Заполнение массива чисел
void fillArray(Student& student) {			//ф-ция принимает стркт. Student по ссылке(&), а не по указателю
    student.dynamicArray = new float[student.arraySize];
    for (int i = 0; i < student.arraySize; ++i) {
        student.dynamicArray[i] = i * 1.5;              // Указываем любое(1.5) значение
    }
}
	//2.3 Вывод на экран массива чисел
void printArray(const Student& student) {		//
    for (int i = 0; i < student.arraySize; ++i) {
        std::cout << student.dynamicArray[i] << " ";
    }
    std::cout << std::endl;
}
	//2.4 Ввод информации в строки имени и фамилии и другие поля
void inputData(Student& student) {
    std::cout << "Введите имя: ";
    std::cin >> student.name;
    delete[] student.surname;                           // Освобождаем предыдущий массив(если он есть)
    student.surname = new char[50];                     // Выделяем память и считываем фамилию
    std::cout << "Введите фамилию: ";
    std::cin >> student.surname;
    std::cout << "Введите возраст: ";
    std::cin >> student.age;
    std::cout << "Введите Идентификатор (double): ";
    std::cin >> student.identifier;
    std::cout << "Введите размер массива: ";
    std::cin >> student.arraySize;
}
	//2.5 Вывод на экран всех полей структуры, кроме массива чисел 
void printStudentInfo(const Student& student) {		//ф-ция не будет изменять объект student
    setlocale(LC_ALL,"RUS");
    std::cout << "Имя: " << student.name << std::endl;
    std::cout << "Фамилия: " << student.surname << std::endl;
    std::cout << "Возраст: " << student.age << std::endl;
    std::cout << "Идентификатор: " << student.identifier << std::endl;
}
	//2.6 Функция освобождения динамической памяти
void freeMemory(Student* student) {
    delete[] student->surname;
    delete[] student->dynamicArray;
}
//3. Определить функцию main(), в которой создать:
int main() {
    setlocale(LC_ALL,"RUS");

    const int numStudents = 2; //кол-во таблиц данных

    Student* studentsArray = new Student[numStudents];  // Указатель на массив структур 
    for (int i = 0; i < numStudents; ++i) {
        initializeStudent(&studentsArray[i]);           // Инициализируем каждую структуру
        fillArray(studentsArray[i]);                    // Заполняем массив чисел
        inputData(studentsArray[i]);                    // Вводим оставшиеся данные 
    }

    for (int i = 0; i < numStudents; ++i) {             // Отображаем содерждимое каждой структуры
        printStudentInfo(studentsArray[i]);
    }

    for (int i = 0; i < numStudents; ++i) {             // Освобождаем память для каждой структуры
        freeMemory(&studentsArray[i]);
    }

    delete[] studentsArray;                             // Осовобождаем массив структур
    
    return 0;
}