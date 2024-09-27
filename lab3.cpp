#include <iostream>
#include <fstream>

#include <cstring>
#include <string>

using namespace std;

FILE *file2;  //2. Опред. глоб. указ. на тип FILE для ф-ций с дв.файлами.

struct Student {
    char name[50]; 
    char *surname; // = new char[50]; //дин.массив
    float id;
    float *marks; //дин.массив
    unsigned int size; //size идет уже после дин.массива?
}; //; нужна тут?

void InitStruct(Student &student) {
    student.surname = nullptr; 
    student.marks = nullptr; 
    student.id = 0.0;
}

void FillArrayOfMarks(Student &student){
    std::cout << "Введите кол-во оценок ->" << std::endl;
    std::cin >> student.size;
    
    student.marks = new float[student.size];
    std::cout << "Введите оценки ->" << std::endl;
    for(int i=0; i<student.size; i++){
        std::cin >> student.marks[i];
    }
}

void PrintArrayOfMarks(const Student &student){
    std::cout << "Оценки:" << std::endl;
    for(int i=0; i<student.size; i++){
        std::cout << student.marks[i] << std::endl;
    }
}

void InputInfo(Student *student){
    std::cout << "Введите имя студента ->" << std::endl;
    std::cin >> student->name;
    
    delete[] student->surname;
    student->surname =  new char[50]();
    std::cout << "Введите фамилию студента ->" << std::endl;
    std::cin >> student->surname;
    

    std::cout << "Введите id студента ->" << std::endl;
    std::cin >> student->id;
}

void PrintInfo(const Student *student){
    std::cout << "Имя: " << student->name << std::endl;
    std::cout << "Фамилия: " << student->surname << std::endl;
    std::cout << "Идентификатор: " << student->id << std::endl;
    std::cout << "Кол-во оценок: " << student->size << std::endl;
}

void FreeMemory(Student *student){
    delete[] student->surname;
    delete[] student->marks;
}
//Высокий уровень (текстовые файлы)
void writingTFile(struct Student &student, int count){
    setlocale(0, "Russian");
    std::ofstream wrt;
    wrt.open("textFormat.txt"); //  ,ios::app
    if(!wrt.is_open()){
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    for(int j=0; j<count; j++){
        wrt <<"Имя студента "<<student.name << '\n';
        wrt <<"Фамилия "<< student.surname << '\n';
        wrt <<"Идентификатор "<< student.id << '\n';
        wrt <<"Кол-во оценок "<< student.size << '\n';
        wrt <<"Оценки: ";
        for (int i = 0; i < student.size; ++i) {
            wrt << student.marks[i] << ' ';
        }
        wrt << '\n' << '\n';
    }
    
    wrt.close();
}
 
void readingTFile(struct Student *students, int count) {
    setlocale(0, "Russian");
    std::ifstream rd("textFormat.txt");
    if (!rd.is_open()) {
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    for (int i = 0; i < count; ++i) {
        rd >> students[i].name;
        rd >> students[i].surname;
        rd >> students[i].id;
        rd >> students[i].size;
        students[i].marks = new float[students[i].size];
        for (int j = 0; j < students[i].size; ++j) {
            rd >> students[i].marks[j];
        }
    }
    rd.close();
}


//Низкий уровень (бинарные файлы)
void writingBFile(struct Student &student, FILE *file){
    fwrite(&student, sizeof(student), 1, file);
}

void readingBFile(Student &student, FILE *file){
    fread(&student, sizeof(student), 1, file);
}

int main(){
    FILE *file;
    int students;
    std::cout << "Введите кол-во студентов ->" << std::endl;
    std::cin >> students;
    Student *studentsArrays1 = new Student[students]; 
    Student *studentsArrays2 = new Student[students];
    Student *studentsArrays3 = new Student[students];
    
    file2 = fopen("bin_dat", "wb");
    for(int i=0; i<students; i++){ //а здесь не надо использовать &?
        InitStruct(studentsArrays1[i]);
        
        InputInfo(&studentsArrays1[i]);          //почему здесь надо использовать &?
        FillArrayOfMarks(studentsArrays1[i]);
        //PrintInfo(&studentsArrays1[i]);          //почему здесь надо использовать &?
        //PrintArrayOfMarks(studentsArrays1[i]);                    
        FreeMemory(&studentsArrays1[i]);         //почему здесь надо использовать &?
        
        writingTFile(studentsArrays1[i], students);
        writingBFile(studentsArrays1[i], file2);
    }
    
    fclose(file2);
    std::cout << "Чтение текстового";
    for(int i=0; i<students; i++){
        readingTFile(&studentsArrays2[i], students);
    }
    
    file2=fopen("bin_dat","rb");
    std::cout<<"Вывод из бинарного файла"<<std::endl;
    for(int i=0; i<students; i++){
	  readingBFile(studentsArrays3[i], file2);   
    }
    fclose(file2);
    
    delete[] studentsArrays1;
    delete[] studentsArrays2;
    delete[] studentsArrays3;
}