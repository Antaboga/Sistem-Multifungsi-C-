#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Fungsi Kalkulator
void kalkulator() {
    double num1, num2, hasil;
    char op;
    cout << "\n=== Kalkulator Sederhana ===\n";
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;
    cout << "Masukkan angka kedua: ";
    cin >> num2;

    switch(op) {
        case '+': hasil = num1 + num2; break;
        case '-': hasil = num1 - num2; break;
        case '*': hasil = num1 * num2; break;
        case '/': 
            if(num2 != 0) hasil = num1 / num2; 
            else {
                cout << "Error: Tidak bisa membagi dengan 0!\n";
                return;
            }
            break;
        default:
            cout << "Operator tidak valid!\n";
            return;
    }
    cout << "Hasil: " << hasil << "\n";
}

// Fungsi Generator Angka Acak
void generatorAngkaAcak() {
    int min, max;
    cout << "\n=== Generator Angka Acak ===\n";
    cout << "Masukkan nilai minimum: ";
    cin >> min;
    cout << "Masukkan nilai maksimum: ";
    cin >> max;

    if(min > max) {
        cout << "Nilai minimum tidak boleh lebih besar dari maksimum!\n";
        return;
    }

    srand(time(0));
    int hasil = min + rand() % (max - min + 1);
    cout << "Angka acak: " << hasil << "\n";
}

// Fungsi Enkripsi Sederhana
void enkripsiSederhana() {
    string teks, hasil;
    int kunci;
    cout << "\n=== Enkripsi Sederhana ===\n";
    cout << "Masukkan teks: ";
    cin.ignore();
    getline(cin, teks);
    cout << "Masukkan kunci (angka): ";
    cin >> kunci;

    for(char c : teks) {
        if(isalpha(c)) {
            char batas = islower(c) ? 'a' : 'A';
            c = batas + (c - batas + kunci) % 26;
        }
        hasil += c;
    }

    cout << "Teks terenkripsi: " << hasil << "\n";
}

// Menu Utama
int main() {
    int pilihan;

    do {
        cout << "\n=== Sistem Multifungsi C++ ===\n";
        cout << "1. Kalkulator\n";
        cout << "2. Generator Angka Acak\n";
        cout << "3. Enkripsi Sederhana\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: kalkulator(); break;
            case 2: generatorAngkaAcak(); break;
            case 3: enkripsiSederhana(); break;
            case 4: cout << "Terima kasih telah menggunakan program ini!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while(pilihan != 4);

    return 0;
}
