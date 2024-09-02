#include "stdafx.h"
#include <vector>

void InitTable(int* table);
void ShowTable(int* table);
void UserSelect(int* userTable, int* comTable, vector<int>& v);
void ComSelect(int * userTable, int* comTable, vector<int>& v);
void CheckUserBingo(int* userTable, int& nUserBingo);
void CheckComBingo(int* comTable,int& nComBingo);
void ShowNum(vector<int>& v);

int main(){
    srand(time(NULL));
    rand();

    vector<int> v;

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
            ShowNum(v);
            cout << endl;

            UserSelect(nUsertable, nComtable, v);
            ComSelect(nUsertable, nComtable, v);

            CheckUserBingo(nUsertable, nUserBingo);
            CheckComBingo(nComtable, nComBingo);
        }
        ShowTable(nComtable);

        cout << "User Bingo: " << nUserBingo << endl;
        cout << "Computer Bingo: " << nComBingo << endl;

        cout << endl << "0. Exit game, 1. Restart game: ";
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

void UserSelect(int* userTable, int* comTable, vector<int>& v){
    int nSelect;

    cout << "Select number(1 ~ 25): ";
    cin >> nSelect;
    v.push_back(nSelect);

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
            cout << nSelect << " is not exsist!" << endl;
            Sleep(1000);
        }
    }
}

void ComSelect(int* userTable, int* comTable, vector<int>& v){
    int nSelect;

    cout << "Computer is selecting number.." << endl;
    nSelect = rand() % 25 + 1;
    v.push_back(nSelect);

    cout << "Computer's number: " << nSelect << endl;

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
            cout << nSelect << " is not exsist!" << endl;
            Sleep(1000);
        }
    }
}

void CheckUserBingo(int* userTable, int& nUserBingo){
    int userCount = 0;
    int temp = 0;

    nUserBingo = 0;

    for(int i = 0; i < 25; i++){
        if(userTable[i] == 0){
            userCount++;
        }

        if(userCount == 5){
            nUserBingo++;
            userCount = 0;
        }

        if(i % 5 == 4){
            userCount = 0;
        }
    }

    userCount = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(userTable[i + temp] == 0){
                userCount++;
            }

            temp += 5;
        }
        if(userCount == 5){
            nUserBingo++;
        }
        else{
            userCount = 0;
        }
        temp = 0;
    }

    userCount = 0;

    for(int i = 0; i < 5; i++){
        if(userTable[i * 6] == 0){
            userCount++;
        }
    }

    if(userCount == 5){
        nUserBingo++;
        userCount = 0;
    }
    else{
        userCount = 0;
    }

    for(int i = 1; i < 6; i++){
        if(userTable[i * 4] == 0){
            userCount++;
        }
    }

    if(userCount == 5){
        nUserBingo++;
        userCount = 0;
    }
    else{
        userCount = 0;
    }
}

void CheckComBingo(int* comTable, int& nComBingo){
    int comCount = 1;
    int temp = 5;

    nComBingo = 0;

    for(int i = 0; i < 25; i++){
        if(comTable[i] == 0){
            comCount++;
        }

        if(i % 5 == 4){
            comCount = 1;
        }

        if(comCount == 5){
            nComBingo++;
            comCount = 1;
        }
    }

    comCount = 1;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(comTable[i + temp] == 0){
                comCount++;
            }

            temp += 5;
        }
        if(comCount == 5){
            nComBingo++;
            comCount = 1;
        }
        else{
            comCount = 1;
        }
        temp = 5;
    }

    comCount = 1;

    for(int i = 0; i < 5; i++){
        if(comTable[i * 6] == 0){
            comCount++;
        }
    }

    if(comCount == 5){
        nComBingo++;
        comCount = 1;
    }
    else{
        comCount = 1;
    }

    for(int i = 1; i < 6; i++){
        if(comTable[i * 4] == 0){
            comCount++;
        }
    }

    if(comCount == 5){
        nComBingo++;
        comCount = 1;
    }
    else{
        comCount = 1;
    }
}

void ShowNum(vector<int>& v){
    cout << "Be selected number lists: ";

    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
}