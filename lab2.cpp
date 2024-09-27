#include <iostream>
#include <locale>
//using namespace std;

// 1.���������� ����������� ���, ���������� ��������� ����:
struct Student { 
    char name[50]; //1.1 ���������� ������ ��� �������� ������
    char* surname; //1.2 ��������� surname �� ��� char
    	//�������������� ���� �� ��������
    float identifier; //���������� ���� float
    float* dynamicArray; //��������� dynamicArray �� ��� float
    unsigned int arraySize; 
    	//�������������� ���� �� �������
    int age;
};
//� �������� ������� ����� �� ���������� ������ ���� ��������� �� ����������� ���, � ������ �������� - ������. 
// 2. ���������� �������:
	//2.1 ������������� ���������
		// -> ������������ ��� ��������� � ������ ��������� ��� �������, ����� ������� ��������� �� ���� ������
void initializeStudent(Student* student) { 		//�-��� ��������� �����. Student ����� ���������
    student->surname = nullptr;                         //���. ��������� ������ �����. �� nullptr(���������� ������ � ��������� surname)
    student->dynamicArray = nullptr;			//���. ��������� ������ �����. �� nullptr(���������� ������)
    student->arraySize = 0;				//���. ��������� ������ �����. �� ������ ������� � 0
}
	//2.2 ���������� ������� �����
void fillArray(Student& student) {			//�-��� ��������� �����. Student �� ������(&), � �� �� ���������
    student.dynamicArray = new float[student.arraySize];
    for (int i = 0; i < student.arraySize; ++i) {
        student.dynamicArray[i] = i * 1.5;              // ��������� �����(1.5) ��������
    }
}
	//2.3 ����� �� ����� ������� �����
void printArray(const Student& student) {		//
    for (int i = 0; i < student.arraySize; ++i) {
        std::cout << student.dynamicArray[i] << " ";
    }
    std::cout << std::endl;
}
	//2.4 ���� ���������� � ������ ����� � ������� � ������ ����
void inputData(Student& student) {
    std::cout << "������� ���: ";
    std::cin >> student.name;
    delete[] student.surname;                           // ����������� ���������� ������(���� �� ����)
    student.surname = new char[50];                     // �������� ������ � ��������� �������
    std::cout << "������� �������: ";
    std::cin >> student.surname;
    std::cout << "������� �������: ";
    std::cin >> student.age;
    std::cout << "������� ������������� (double): ";
    std::cin >> student.identifier;
    std::cout << "������� ������ �������: ";
    std::cin >> student.arraySize;
}
	//2.5 ����� �� ����� ���� ����� ���������, ����� ������� ����� 
void printStudentInfo(const Student& student) {		//�-��� �� ����� �������� ������ student
    setlocale(LC_ALL,"RUS");
    std::cout << "���: " << student.name << std::endl;
    std::cout << "�������: " << student.surname << std::endl;
    std::cout << "�������: " << student.age << std::endl;
    std::cout << "�������������: " << student.identifier << std::endl;
}
	//2.6 ������� ������������ ������������ ������
void freeMemory(Student* student) {
    delete[] student->surname;
    delete[] student->dynamicArray;
}
//3. ���������� ������� main(), � ������� �������:
int main() {
    setlocale(LC_ALL,"RUS");

    const int numStudents = 2; //���-�� ������ ������

    Student* studentsArray = new Student[numStudents];  // ��������� �� ������ �������� 
    for (int i = 0; i < numStudents; ++i) {
        initializeStudent(&studentsArray[i]);           // �������������� ������ ���������
        fillArray(studentsArray[i]);                    // ��������� ������ �����
        inputData(studentsArray[i]);                    // ������ ���������� ������ 
    }

    for (int i = 0; i < numStudents; ++i) {             // ���������� ����������� ������ ���������
        printStudentInfo(studentsArray[i]);
    }

    for (int i = 0; i < numStudents; ++i) {             // ����������� ������ ��� ������ ���������
        freeMemory(&studentsArray[i]);
    }

    delete[] studentsArray;                             // ������������ ������ ��������
    
    return 0;
}