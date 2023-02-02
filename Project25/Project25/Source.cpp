#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

int main() {
    FILE* fr = fopen("vstup.txt", "r");

    FILE* fw = fopen("vystup.txt", "w");

        if (!fr) {
            printf("subor ");
            printf("vstup.txt");
            printf(" nemozno otvorit\n");
       }

        

        char fileText[10001];
        fgets(fileText, 10001, fr);
        fclose(fr);

        string arr[1001] = { "" };
        int j = 0;

        char* pch;
        //printf("Splitting string \"%s\" into tokens:\n", fileText);
        pch = strtok(fileText, " ,+");
        while (pch != NULL)
        {
            arr[j] = pch;
            j++;
            pch = strtok(NULL, " ,+\r");
        }

        char s[10000];

        double nums[10000];
        for (int i = 0; i < j; i++) {
            nums[i] = stod(arr[i]);
        }


        for (int i = 0; i < j; i++) {
            //string num = to_string(nums[i]);
            //fputs(num.c_str(), fw);
            //fputs("\n", fw);
            if (i != 0) sprintf(s, " +%11.2f", nums[i]);
            else sprintf(s, "  %11.2f", nums[i]);
            fputs(s, fw);
            fputs("\n", fw);
        }

        fputs("--------------\n", fw);

        double result = 0;
        for (int i = 0; i < j; i++)
            result += nums[i];

        sprintf(s, " % 12.2f", result);
        fputs(s, fw);
        fputs("\n", fw);
        //fputs(to_string(result).c_str(), fw);  

    fclose(fw);
}