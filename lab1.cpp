#include <iostream>

int main() {
setlocale(LC_ALL, "Russian");
    // 1. Определить в функции main() переменные и массивы по таблице 1 в соответствии с вариантом (см. таблицу 1).
    float No1[5]; // Sozdaem odnomerniy massiv s 5 elementami

    // 2.1. Проверить содержимое массива No1 (с помощью цикла for и операции вывода cout<<).
    std::cout << "Содержимое массива No1 до ввода:"  << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << No1[i] << " ";
    }
    std::cout << std::endl;

    // 2.2. Ввести данные в массив No1 (с помощью цикла for и операции ввода cin>>).
    std::cout << "Введите 5 числел массива No1:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> No1[i];
    }

    // 2.3. Еще раз проверить содержимое этого массива, сделать выводы.
    std::cout << "Содержимое массива No1 после ввода:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << No1[i] << " ";
    }
    std::cout << std::endl;

    // 2.4. Присвоить указателю No2 адрес массива No1, вывести на экран адреса массива и указателя и содержимое указателя.
    float* No2 = No1;
    std::cout << "Содержимое указателя No2: " << *No2 << std::endl;
    std::cout << "Адрес массива No1: " << No1 << std::endl;
    std::cout << "Адрес указателя No2: " << &No2 << std::endl;

    // 2.5. Повторить пункт 3 для указателя, содержащего адрес массива.
    std::cout << "Адрес массива: " << No2 << std::endl;
    // 2.6. Повторить пункты 1-3 для статического массива No3.
        // 2.6 -> 2.1
    char No3[5]; //Sozdaem static massiv simvolov s 10 elementami
    std::cout << "2.6 -> 2.1 Содержимое до ввода значений:" << std::endl;
    for (int i =0; i<5; i++) {
        std::cout << No3[i] << " ";
    } 
    std::cout << std::endl;
        // 2.6 -> 2.2
    std::cout << "2.6 -> 2.2 Введите 5 символов для No3_static:" << std::endl; 
    for (int i = 0; i < 5; i++) {
    std::cin >> No3[i];
    }   
        // 2.6 -> 2.3
    std::cout << "2.6 -> 2.3 Элементы массива после ввода:" << std::endl;
    for (int i=0; i<5; i++) {
        std::cout << No3[i] << " ";
        } 
        std::cout << std::endl;
    

    // 2.7. Используя имеющийся указатель No2, создать динамический массив и повторить для него пункты 1 - 3.
    int size = 3;
    No2 = new float[size];
    std::cout << "Введите " << size << " чисел для динамического массива:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> No2[i];
    }
    std::cout << "Содержимое динамического массива:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << No2[i] << " ";
    }
    std::cout << std::endl;

    //2.8. Удалить динамический массив. Используя указатель No4, создать двумерный динамический массив и повторить для него пункты 2, 3. Сделать выводы. Удалить двумерный динамический массив.
    delete[] No2; // Udalyaem dynamic massiv
    
    int str = 2;
    int stb = 2;
    
    char** No4 = new char*[str]; //Ob'yavlyaem ukazatel na char
    for (int i = 0; i < str; i++) {
        No4[i] = new char[stb];
        }
        //2.8 -> 2.2
    std::cout << "2.8 -> 2.2 Введите 4 символа для массива:" << std::endl;
    for(int i = 0; i < str; i++) {
        for(int j = 0; j < stb; j++) {
               std::cin >> No4[i][j];
        }
    }
        //2.8 -> 2.3
    std::cout << "2.8 -> 2.3 Элементы массива:" << std::endl;
    for(int i = 0; i < str; i++) {
        for(int j = 0; j < stb; j++) {
               std::cout << No4[i][j] << " ";
        }
    }   
    std::cout << std::endl;
    
    delete[] No4; // Udalil 2-merniy char massiv
    
    
    // 2.9. Вывести на экран любой из элементов трехмерного массива No5, используя операцию индексации.
    unsigned int No5[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };
    std::cout << "Element trehmernogo massiva No5: " << No5[1][2][3] << std::endl;
    
    // 2.10. Повторить пункт 9, используя имя массива как указатель и операцию доступа по указателю.
    unsigned int (*No7)[3][4] = (unsigned int (*)[3][4])No5;
    std::cout << "Элементы трехмерного массива No5 через указатель No6: " << No7[1][2][3] << std::endl;
    
    
    // 2.11. Присвоить указателю No6 на двумерный массив адрес трехмерного массива No5. Повторить для этого указателя пункт 10.
    char (*No6)[3][4]; // No6 теперь указатель на двумерный массив символов
    No6 = (char (*)[3][4])No5; // приведение типа массива No5 к типу указателя No6
    std::cout << " Вывод элемента:" << std::endl;
    std::cout << No6[1][2][3] << std::endl; // доступ к элементу через No6

    return 0;
}
