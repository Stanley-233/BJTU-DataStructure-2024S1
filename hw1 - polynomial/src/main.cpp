#include <iostream>
#include <fstream>

#include "util/Polynomial.h"


int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    // input
    int length1, length2;
    int inputs1[100], inputs2[100];
    memset(inputs1, 0, sizeof(inputs1));
    memset(inputs2, 0, sizeof(inputs2));
    fin >> length1;
    for (int i = 0; i < length1 * 2; i++) {
        fin >> inputs1[i];
    }
    fin >> length2;
    for (int i = 0; i < length2 * 2; i++) {
        fin >> inputs2[i];
    }
    Polynomial a(length1, inputs1);
    Polynomial b(length2, inputs2);
    // sum
    Polynomial sum = a + b;
    int sumLength = sum.getLength();
    fout << sumLength << " ";
    for (int i = 1; i <= sumLength; i++) {
        fout << sum.get(i)->coefficient << " " << sum.get(i)->exponent << " ";
    }
    fout << "\n";
    // multiply
    Polynomial product = a * b;
    int productLength = product.getLength();
    fout << productLength << " ";
    for (int i = 1; i <= productLength; i++) {
        fout << product.get(i)->coefficient << " " << product.get(i)->exponent << " ";
    }
    fout << "\n";
}
