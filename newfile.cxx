#include <iostream>
#include <string>

using namespace std;

int main() {
    string barcodeInput;
    cout << "Masukkan 11 digit barcode: ";
    cin >> barcodeInput;

    if (barcodeInput.length() != 11) {
        cout << "Harus 11 digit!" << endl;
        return 1;
    }

    int sumOdd = 0;
    int sumEven = 0;

    
    for (int i = 0; i < 11; i++) {
        int digit = barcodeInput[i] - '0';
        if (i % 2 == 0) {
            sumOdd += digit; // Posisi ganjil (indeks 0, 2, ...)
        }
        else {
            sumEven += digit; // Posisi genap (indeks 1, 3, ...)
        }
    }

    
    int step1 = (sumOdd % 10) * 3;
    int step2 = step1 + (sumEven % 10);

    
    int checkSum = (10 - (step2 % 10)) % 10;

    cout << "Check Digit: " << checkSum << endl;
    cout << "Barcode Lengkap: " << barcodeInput << checkSum << endl;

    return 0;
}