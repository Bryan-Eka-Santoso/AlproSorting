#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int menu, temp, backMenu;
int n = 1000000;
int arr[1000000];

void simpanFile(){
    ofstream myFile;
    myFile.open("data_angka.txt", ios::out);
    if (myFile.is_open()) {
        for(int i = 0; i < n; i++){
            myFile << i+1 << endl;
        }
        myFile.close();
    }
}

void bacaFile() {
    ifstream myFile;
    myFile.open("data_angka.txt");
    if (myFile.is_open()) {
        int j, i = 0;
        while (myFile >> j) {
            arr[i] = j;
            i++;
        }
        myFile.close();

        for (int i = 0; i < n; i++) {
            int angka = rand() % n;
            int temp = arr[i];
            arr[i] = arr[angka];
            arr[angka] = temp;
        }
    }
}

void bacaFileRandom() {
    ifstream myFile;
    myFile.open("data_angkaRandom.txt");
    if (myFile.is_open()) {
        int j, i = 0;
        while (myFile >> j) {
            arr[i] = j;
            i++;
        }
        myFile.close();
    }
}

void simpanFileRandom(){
    ofstream myFile;
    myFile.open("data_angkaRandom.txt", ios::out);
    if (myFile.is_open()) {
        for(int i = 0; i < n; i++){
            myFile << arr[i] << endl;
        }
        myFile.close();
    }
}

void simpanDurasi(double duration, string nameSort, int n){
    ofstream myFile;
    myFile.open("duration.txt", ios::app);
    if (myFile.is_open()) {
        myFile << nameSort << " ( " << n << " Data Numbers" << " ) " << ": " << duration << " Seconds" << endl;
        myFile.close();
    }
}

void addLine(){
    ofstream myFile;
    myFile.open("duration.txt", ios::app);
    if (myFile.is_open()) {
        myFile << endl << "---------- New Random Number ----------" << endl;
        myFile.close();
    }
}

int main()
{
    srand(time(0));
    bacaFileRandom();

    do {
        cout << "== Menu ==" << endl;
        cout << "1. Generate Number" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Straight Selection Sort" << endl;
        cout << "4. Bubble Sort" << endl;
        cout << "5. Two Way Bubble Sort" << endl;
        cout << "0. Exit" << endl;
        do {
            cout << ">> ";
            cin >> menu;
        } while (menu < 0 || menu > 5);
        system("cls");

        switch(menu){
            case 1:{
                do {
                    clock_t start_time = clock();
                    simpanFile();
                    bacaFile();
                     clock_t end_time = clock();
                    // For seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                    simpanFileRandom();
                    addLine();

                    cout << "Generate Number: " << endl;

                    for(int k = 0; k < n; k++){
                        cout << arr[k] << " ";
                    }

                    cout << endl << endl;
                    cout << "Generate Number: " << duration << " Seconds" << endl;
                    cout << "0. Back" << endl;
                    cout << ">> ";
                    cin >> backMenu;
                } while (backMenu != 0);
                system("cls");
            break;
            }
            case 2:{
                do {
                    clock_t start_time = clock();

                    int minn = 0;
                    for (int i = 0 ; i < n-1; i++){
                        minn = i + 1;
                        for (int j = i + 1; j < n; j++){
                            if (arr[j] < arr[minn]){
                            minn = j;
                            }
                        }
                        if (arr[i] > arr[minn]){
                            temp = arr[i];
                            arr[i] = arr[minn];
                            arr[minn] = temp;
                        }

                    }
                    clock_t end_time = clock();
                    // For Seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

                    cout << "Selection Sort: " << endl;

                    for(int k = 0; k < n; k++){
                        cout << arr[k] << " ";
                    }

                    cout << endl << endl;
                    cout << "Selection Sort took " << duration << " Seconds" << endl;
                    simpanDurasi(duration, "Selection Sort", n);
                    cout << "0. Back" << endl;
                    cout << ">> ";
                    cin >> backMenu;
                } while (backMenu != 0);
                system("cls");
            break;
            }
            case 3:{
                do {
                    clock_t start_time = clock();

                    for(int i = 0; i < n-1; i++){
                        for(int j = i+1; j < n; j++){
                            if(arr[i] > arr[j]){
                                temp = arr[j];
                                arr[j] = arr[i];
                                arr[i] = temp;
                            }
                        }
                    }
                    clock_t end_time = clock();
                    // For Seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

                    cout << "Straight Selection Sort: " << endl;

                    for(int k = 0; k < n; k++){
                        cout << arr[k] << " ";
                    }

                    cout << endl << endl;
                    cout << "Bubble Sort took " << duration << " Seconds" << endl;
                    simpanDurasi(duration, "Straight Selection Sort", n);
                    cout << "0. Back" << endl;
                    cout << ">> ";
                    cin >> backMenu;
                } while (backMenu != 0);
                system("cls");
            break;
            }
            case 4:{
                do {
                    clock_t start_time = clock();

                    for (int i = 0; i < n-1; i++){
                        for (int j = 0; j < n-i-1; j++){
                            if (arr[j] > arr[j+1]){
                            temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                            }
                        }
                    }
                    clock_t end_time = clock();
                    // For Seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;


                    cout << "Bubble Sort: " << endl;

                    for(int k = 0; k < n; k++){
                        cout << arr[k] << " ";
                    }

                    cout << endl << endl;
                    cout << "Bubble Sort took " << duration << " Seconds" << endl;
                    simpanDurasi(duration, "Bubble Sort", n);
                    cout << "0. Back" << endl;
                    cout << ">> ";
                    cin >> backMenu;
                } while (backMenu != 0);
                system("cls");
            break;
            }
            case 5:{
                do {
                    clock_t start_time = clock();

                    for (int i = 0; i < n/2; i++){
                        for (int j = i; j < n-1-i; j++){
                            if (arr[j] > arr[j+1]){
                                temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                            }
                        }
                        for (int j = n-2-i; j > i ;j--){
                            if (arr[j-1] > arr[j]){
                                temp = arr[j];
                                arr[j] = arr[j-1];
                                arr[j-1] = temp;
                            }
                        }
                    }
                    clock_t end_time = clock();
                    // For Seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;


                    cout << "Two Way Bubble Sort: " << endl;

                    for(int k = 0; k < n; k++){
                        cout << arr[k] << " ";
                    }

                    cout << endl << endl;
                    cout << "Two Way Bubble Sort took " << duration << " Seconds" << endl;
                    simpanDurasi(duration, "Two Way Bubble Sort", n);
                    cout << "0. Back" << endl;
                    cout << ">> ";
                    cin >> backMenu;
                } while (backMenu != 0);
                system("cls");
            break;
            }
        }
    } while(menu != 0);
    return 0;
}
