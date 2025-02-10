#include <iostream>

using namespace std;

int main()
{
    int menu, temp;
    int n = 1000000;
    int arr[] = {};

    do {
        cout << "== Menu ==" << endl;
        cout << "1. Generate Angka" << endl;
        cout << "2. Selection" << endl;
        cout << "3. Straight Selection" << endl;
        cout << "4. Bubble" << endl;
        cout << "5. Two Way Bubble" << endl;
        cout << "0. Exit" << endl;
        do {
            cout << ">> ";
            cin >> menu;
        } while (menu < 0 || menu > 5);

        switch(menu){
            case 1:{

            break;
            }
            case 2:{

            break;
            }
            case 3:{            
                for(int i = 0; i < n-1; i++){
                    for(int j = i+1; j < n; j++){
                        if(arr[i] > arr[j]){
                            temp = arr[j];
                            arr[j] = arr[i];
                            arr[i] = temp;
                        }
                    }
                }
            
                for(int k = 0; k < n; k++){
                    cout << arr[k] << " ";
                }
            break;
            }
            case 4:{

            break;
            }
            case 5:{

            break;
            }
        }
    } while(menu != 0);
    return 0;
}
