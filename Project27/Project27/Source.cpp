#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int arr[3][26] = { 0 }; //'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'

    string fileName1;
    cin >> fileName1;

    FILE* fr1 = fopen(fileName1.c_str(), "r");
    char fileText1[30001];
    for(int i=0; true; i++){
        fileText1[i] = fgetc(fr1);
        //printf("%c", fileText[i]);
        if (fileText1[i] == EOF) break;
    }

    for (int i = 0; i < strlen(fileText1); i++) {
        if(fileText1[i] - 97 < 26 && fileText1[i] - 97 >= 0)
        arr[0][fileText1[i] - 97]++;
    }
    fclose(fr1);


    string fileName2;
    cin >> fileName2;

    FILE* fr2 = fopen(fileName2.c_str(), "r");
    char fileText2[30001];
    for (int i = 0; true; i++) {
        fileText2[i] = fgetc(fr2);
        //printf("%c", fileText[i]);
        if (fileText2[i] == EOF) break;
    }
    for (int i = 0; i < strlen(fileText2); i++) {
        if (fileText2[i] - 97 < 26 && fileText2[i] - 97 >= 0)
        arr[1][fileText2[i] - 97]++;
    }
    fclose(fr2);


    string fileName3;
    cin >> fileName3;

    FILE* fr3 = fopen(fileName3.c_str(), "r");
    char fileText3[30001];
    for (int i = 0; true; i++) {
        fileText3[i] = fgetc(fr3);
        //printf("%c", fileText3[i]);
        if (fileText3[i] == EOF) break;
    }
    for (int i = 0; i < strlen(fileText3); i++) {
        if (fileText3[i] - 97 < 26 && fileText3[i] - 97 >= 0)
        arr[2][fileText3[i] - 97]++;
    }
    fclose(fr3);

    int all = 0;

    cout<< fileName1 << endl;
    for (int i = 0; i < 26; i++) {
        //cout << arr[0][i] << " ";
        all += arr[0][i];
        
    }
    //cout << endl;
    //cout << all <<endl;
    for (int i = 0; i < 26; i++) {
        if(i!=0)cout << " ";
        arr[0][i] = arr[0][i] * 100 / all;
        cout << arr[0][i];
    }
    cout << endl;


    all = 0;

    cout << fileName2 << endl;
    for (int i = 0; i < 26; i++) {
        //cout << arr[1][i] << " ";
        all += arr[1][i];

    }
    //cout << endl;
    //cout << all << endl;
    for (int i = 0; i < 26; i++) {
        if (i != 0)cout << " ";
        arr[1][i] = arr[1][i] * 100 / all;
        cout << arr[1][i];
    }
    cout << endl;

    int a = 0;
    for (int i = 0; i < 26; i++) {
        a += abs(arr[0][i] - arr[1][i]);
    }
    cout << a << endl;

    all = 0;

    cout << fileName3 << endl;
    for (int i = 0; i < 26; i++) {
        //cout << arr[2][i] << " ";
        all += arr[2][i];

    }
    //cout << endl;
    //cout << all << endl;
    for (int i = 0; i < 26; i++) {
        if (i != 0)cout << " ";
        arr[2][i] = arr[2][i] * 100 / all; //problem
        cout << arr[2][i];
    }
    cout << endl;

    int b = 0;
    for (int i = 0; i < 26; i++) {
        b += abs(arr[0][i] - arr[2][i]);
    }
    cout << b << endl;

    if (a < b) cout << fileName2 << endl;
    else cout << fileName3 << endl;

}