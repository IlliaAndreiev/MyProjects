#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

void delElem(char arr[], int tot, int elem)
{
    int i, j;
    for (i = 0; i < tot; i++)
    {
        if (arr[i] == elem)
        {
            for (j = i; j < (tot - 1); j++)
                arr[j] = arr[j + 1];
            i--;
            tot--;
        }
    }
}

int main() {
   // char fileName[100] = "vstup.txt";
    //cin >> fileName;
    FILE* fr = fopen("vstup.txt", "r");
    if (!fr) printf("subor vstup.txt nemozno otvorit\n");

    char** text = nullptr;
    int MAXR = 0, MAXC = 0;
    char t1[100], t2[100];
    fscanf(fr, "%s %d %s %d", t1, &MAXR, t2, &MAXC);
    //cout << t1 << " " << MAXR << " " << t2 << " " << MAXC << endl;

    text = new char* [MAXR + 1];
    for (int i = 0; i <= MAXR; i++) {
        text[i] = new char[MAXC + 1];
    }

    fscanf(fr, "%s", t1); //START
    fscanf(fr, "\n");
    //t1 != START - ERROR

    for (int i = 0; i < MAXR; i++) {
        fgets(text[i], MAXC + 1, fr);
        size_t l = strlen(text[i]);
        cout << "size: " << l << endl;
        if (!strcmp(text[i], "END") || !strcmp(text[i], "END\n")) {
            // text[i][0] = '\0';
            break;
        }
        text[i][l] = '\0';
        //fscanf(fr, "%*s", text[i]);
    }
    for (int i = 0; i < MAXR; i++) { //problem
        size_t l = strlen(text[i]);
        if (l == 1) delElem(text[i], MAXR, i);/*for (int j = i; j < MAXR - 1; j++) {
            text[j] = text[j + 1];
        }
        i--;
        l--;*/
        //cout << "size: " << l << endl;
     }

    //fscanf(fr, "%s", t1); //END

     //text[i] != END - ERROR

    int j0 = 0, i0 = 0; //j - number of colomn, i - number of row

    while (!feof(fr)) {
        fscanf(fr, "%s", t1);
        if (!strcmp(t1, "LEFT")) {
            if (j0 > 0) j0--;
            else if (i0 > 0) {
                i0--;
                j0 = strlen(text[i0]);
            }
            cout << "LEFT" << " " << i0 << " " << j0 << endl;
            if (i0 < 0 || j0 < 0)
                cout << "ERROR";
        }
        else if (!strcmp(t1, "RIGHT")) {
            if (j0 < MAXC - 1) j0++;
            else if (i0 < MAXR) {
                i0++;
                j0 = 0;
            }
            cout << "RIGHT" << " " << i0 << " " << j0 << endl;
            if (i0 < 0 || j0 < 0)
                cout << "ERROR";
        }
        else if (!strcmp(t1, "INSERT")) {
            fscanf(fr, "%s", t2);
            if (strlen(text[i0]) < MAXC) {
                for (int j = strlen(text[i0]); j >= j0; j--) {
                    text[i0][j + 1] = text[i0][j];
                }
                text[i0][j0] = t2[1];
            }
            cout << "INSERT" << " " << i0 << " " << j0 << endl;
        }
        else if (!strcmp(t1, "DELETE")) {
            if (strlen(text[i0]) > 0)
                for (int j = strlen(text[i0]); j > j0; j--) {
                    text[i0][j - 1] = text[i0][j];
                }
            cout << "DELETE" << " " << i0 << " " << j0 << endl;
            //text[i0][j0] = t2[1];
        }
        else if (!strcmp(t1, "PRINT")) {
            fscanf(fr, "%s", t2);
            if (!strcmp(t2, "-")) {
                    cout << "START" << endl;
                    for (int i = 0; i < MAXR; i++) {
                        if (!strcmp(text[i], "END") || !strcmp(text[i], "END\n")) break;
                        cout << text[i] << endl;
                    }
                    cout << "END" << endl;
            }
            else {
                FILE* fw = fopen(t2, "w");
                cout << "START" << endl;
                for (int i = 0; i < MAXR; i++) {
                    if (!strcmp(text[i], "END") || !strcmp(text[i], "END\n")) break;
                    fputs(text[i], fw);
                    fputs("\n", fw);
                    cout << text[i] << endl;
                }
                cout << "END" << endl;
                fclose(fw);
            }
        }
        //text[i0][j0] = t2[1];
    }
    //if(t1 != EXIT)

    fclose(fr);


    for (int i = 0; i < MAXR + 1; i++) {
        delete[]text[i];
    }
    delete[]text;
}