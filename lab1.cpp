#include <iostream>

int main() {
setlocale(LC_ALL, "Russian");
    // 1. Odnomerniy massiv tipa float float
    float No1[5]; // Sozdaem odnomerniy massiv s 5 elementami

    std::cout << "// 2.1. Proveryaem soderzhimoe massiva No1" << std::endl;
    std::cout << "Soderzhimoe massiva No1:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << No1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "// 2.2. Vvodim dannie v massiv No1" << std::endl;
    std::cout << "Vvedite 5 chisel massiva No1:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> No1[i];
    }

    std::cout << "// 2.3. Proveryaem soderzhimoe massiva No1 posle vvoda dannih" << std::endl;
    std::cout << "Soderzhimoe massiva No1 posle vvoda:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << No1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "// 2.4. Prisvoit ukazatelyu No2 adres massiva No1, vivesti adresa massiva&ukazatelya, soderzhimoe ukazatelya " << std::endl;
    float* No2 = No1;
    std::cout << "Adress massiva No1: " << No1 << std::endl;
    std::cout << "Adres ukazatelya No2: " << No2 << std::endl;
    std::cout << "Soderzhimoe ukazatelya No2: " << *No2 << std::endl;

    // 2.5. Povtoryaem dlya ukazatelya, soderzhashego adres massiva
    float (*No3)[5] = &No1; // ob'yavlyaet ukazatel *No3 na massiv tipa float razmerom 5 i inizializiruet ego adresom massiva No1
    std::cout << "Adres ukazatelya No3: " << No3 << std::endl;
    std::cout << "Soderzhimoe ukazatelya No3: " << (*No3)[0] << std::endl;

    std::cout << "// 2.6. Povtoryaem dlya static massiva No3" << std::endl;
        // 2.6 -> 2.1
    char No3_static[5]; //Sozdaem static massiv simvolov s 10 elementami
    std::cout << "2.6 -> 2.1 Soderzhimoe do vvoda znacheniy:" << std::endl;
    for (int i =0; i<5; i++) {
        std::cout << No3_static[i] << " ";
    } 
    std::cout << std::endl;
        // 2.6 -> 2.2
    std::cout << "2.6 -> 2.2 Vvedite 5 simvolov massiva No3_static:" << std::endl; 
    for (int i = 0; i < 5; i++) {
    std::cin >> No3_static[i];
    }   
        // 2.6 -> 2.3
    std::cout << "2.6 -> 2.3 Elementi simvolnogo massiva:" << std::endl;
    for (int i=0; i<5; i++) {
        std::cout << No3_static[i] << " ";
        } 
        std::cout << std::endl;
    


    std::cout << "// 2.7. Sozdaem dinamic massiv s ispolzovaniem ukazatelya No2" << std::endl;
    int size = 3;
    No2 = new float[size];
    std::cout << "Vvedite " << size << " chisel dlya dinamic massiva:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> No2[i];
    }
    std::cout << "Soderzhimoe dinamic massiva:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << No2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "// 2.8. Udalit dynamic massiv, isp ukaz No4(mass char), 2-merniy dynamic mass i povtor 2.2, 2.3" << std::endl;
    delete[] No2; // Udalyaem dynamic massiv
    
    int str = 2;
    int stb = 2;
    
    char** No4 = new char*[str]; //Ob'yavlyaem ukazatel na char
    for (int i = 0; i < str; i++) {
        No4[i] = new char[stb];
        }
        //2.8 -> 2.2
    std::cout << "2.8 -> 2.2 Vvedite elementi char massiva" << std::endl;
    for(int i = 0; i < str; i++) {
        for(int j = 0; j < stb; j++) {
               std::cin >> No4[i][j];
        }
    }
        //2.8 -> 2.3
    std::cout << "2.8 -> 2.3 Elementi char massiva" << std::endl;
    for(int i = 0; i < str; i++) {
        for(int j = 0; j < stb; j++) {
               std::cout << No4[i][j] << " ";
        }
    }   
    std::cout << std::endl;
    
    delete[] No4; // Udalil 2-merniy char massiv
    
    
    std::cout << "// 2.9. Vivesti na ekran lyuboy elementov trehmernogo massiva No5" << std::endl;
    unsigned int No5[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };
    std::cout << "Element trehmernogo massiva No5: " << No5[1][2][3] << std::endl;
    
    std::cout << "// 2.10. Povtorit 2.9, isp imya massiva kak ukazatel" << std::endl;
    unsigned int (*No7)[3][4] = (unsigned int (*)[3][4])No5;
    std::cout << "Element trehmernogo massiva No5 cherez ukazatel No6: " << No7[1][2][3] << std::endl;
    
    
    std::cout << "// 2.11. Присвоить указателю No6 на двумерный массив адрес трехмерного массива No5. Повторить для этого указателя пункт 10." << std::endl;
    char (*No6)[3][4]; // No6 теперь указатель на двумерный массив символов
    No6 = (char (*)[3][4])No5; // приведение типа массива No5 к типу указателя No6
    std::cout << No6[1][2][3] << std::endl; // доступ к элементу через No6

    return 0;
}
