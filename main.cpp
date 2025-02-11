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
                int minn=0;
                for (int i = 0 ;i<10-1 ; i++){
                    minn = i+1;
                    for (int j = i+1;j<10;j++){

                    if (arr[j]<arr[minn]){
                    minn = j;
                    }

                    }
                    if (arr[i]>arr[minn]){
                        temp=arr[i];
                        arr[i]=arr[minn];
                        arr[minn] = temp;
                    }

                }
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
                int arr[10]={10,2,5,9,3,6,8,7,1,4};
                int temp;
                for (int i = 0;i<10-1;i++){
                    for (int j = 0;j<10-i-1;j++){
                        if (arr[j]>arr[j+1]){
                        temp = arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                        }   
                    }
                }

            break;
            }
            case 5:{
                for (int i = 0;i<10/2;i++){
                    for (int j = i;j<10-1-i;j++){
                        if (arr[j]>arr[j+1]){
                            temp = arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                    }
                    for (int j = 10-2-i;j>i;j--){
                        if (arr[j-1]>arr[j]){
                            temp = arr[j];
                            arr[j]=arr[j-1];
                            arr[j-1]=temp;
                        }
                    }
                }
            break;
            }
        }
    } while(menu != 0);
    return 0;
}
