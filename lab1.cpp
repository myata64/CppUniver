#include <iostream>

int main() {
setlocale(LC_ALL, "Russian");
    // 1. Odnomerniy massiv tipa float float
    float No1[5]; // Sozdaem odnomerniy massiv s 5 elementami

    // 2.1. Proveryaem soderzhimoe massiva No1
    std::cout << "Soderzhimoe massiva No1:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << No1[i] << " ";
    }
    std::cout << std::endl;

    // 2.2. Vvodim dannie v massiv No1
    std::cout << "Vvedite 5 chisel massiva No1:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> No1[i];
    }

    // 2.3. Proveryaem soderzhimoe massiva No1 posle vvoda dannix
    std::cout << "Soderzhimoe massiva No1 posle vvoda:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << No1[i] << " ";
    }
    std::cout << std::endl;

    // 2.4. Prisvaevaem ukazatelyu No2 adres massiva No1
    float* No2 = No1;
    std::cout << "Adress massiva No1: " << No1 << std::endl;
    std::cout << "Adres ukazatelya No2: " << No2 << std::endl;
    std::cout << "Soderzhimoe ukazatelya No2: " << *No2 << std::endl;

    // 2.5. Povtoryaem dlya ukazatelya, soderzhashego adres massiva
float (*No3)[5] = &No1; // ob'yavlyaet ukazatel *No3 na massiv tipa float razmerom 5 i inizializiruet ego adresom massiva No1
    std::cout << "Adres ukazatelya No3: " << No3 << std::endl;
    std::cout << "Soderzhimoe ukazatelya No3: " << (*No3)[0] << std::endl;

    // 2.6. Povtoryaem dlya static massiva No3
    char No3_static[10]; // Sozdaem static massiv simvolov s 10 elementami

    // 2.7. Sozdaem dinamic massiv s ispolzovaniem ukazatelya No2
    int size = 3;
    float* dynamicArray = new float[size];
    std::cout << "Vvedite " << size << " chisel dlya dinamic massiva:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> dynamicArray[i];
    }
    std::cout << "Soderzhimoe dinamic massiva:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    // 2.8. Udalyaem dinamichesiy massiv
    delete[] dynamicArray;

    // 2.9. Vivodim elemento trehmernogo massiva No5
    unsigned int No5[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };
    std::cout << "Element trehmernogo massiva No5: " << No5[1][2][3] << std::endl;

    // 2.10. Povtoryaem dlya imeni massiva kak ukazatel
    unsigned int (*No6)[3][4] = (unsigned int (*)[3][4])No5;
    std::cout << "Element trehmernogo massiva No5 cherez ukazatel No6: " << No6[1][2][3] << std::endl;

    return 0;
}
