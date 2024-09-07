#include "stdafx.h"

void InitTable(int* table);
void ShowTable(int* table);
void UserSelect(int* userTable, int* comTable);

int main(){
    srand(time(NULL));
    rand();

    int nUsertable[25];
    int nUserBingo = 0;

    int nComtable[25];
    int nComBingo = 0;

    bool isPlaying = true;

    while(isPlaying){
        InitTable(nUsertable);
        InitTable(nComtable);

        while(nUserBingo < 3 && nComBingo < 3){
            system("cls");

            ShowTable(nUsertable);
            cout << endl;
            ShowTable(nComtable);

            UserSelect(nUsertable, nComtable);
        }

        cout << "0. 게임 종료, 1. 재시작: ";
        cin >> isPlaying; 
    }
}

void InitTable(int* table){
    for(int i = 0; i < 25; i++){
        table[i] = i + 1;
    }

    int nSrc;
    int nDest;
    int nTemp;

    for(int i = 0; i < 250; i++){
        nSrc = rand() % 25;
        nDest = rand() % 25;

        nTemp = table[nSrc];
        table[nSrc] = table[nDest];
        table[nDest] = nTemp;
    }
}

void ShowTable(int* table){
    cout << "=================================================================================" << endl;
    for(int i = 0; i < 25; i++){
        cout << "|\t" << table[i] << "\t|";

        if(i % 5 == 4){
            cout << endl;
            cout << "=================================================================================" << endl;
        }
    }
}

void UserSelect(int* userTable, int* comTable){
    int nSelect;

    cout << "숫자 선택(1 ~ 25): ";
    cin >> nSelect;

    for(int i = 0; i < 25; i++){
        if(nSelect == userTable[i]){
            userTable[i] = 0;

            for(int j = 0; j < 25; j++){
                if(nSelect == comTable[j]){
                    comTable[j] = 0;
                    break;
                }
            }
            break;
        }

        if(i == 24){
            cout << "이미 선택된 숫자입니다." << endl;
            Sleep(1000);
        }
    }
}