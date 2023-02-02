#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int p_name = 16, p_category = 16, p_paradigm = 16, p_lvl = 16, p_authors = 16;
const int countZinP = 12;

struct progLanguage
{
	char name[p_name];
	int year;
	char category[p_category];
	char paradigm[p_paradigm];
	char lvl[p_lvl];
	char authors[p_authors];
};

fstream f;
char fdir[100];

void openNew()
{
	system("cls");
	printf(" ������ ����� ��'� ����� ( �������: \"D:\\Dev-Cpp\\coursework\\file.dat\" ): ");
	cin >> fdir;

openf:
	f.open(fdir, ios::in | ios::out | ios::binary);
	if (!f.is_open())
	{
		printf("\n ������� ��� ������� �����, ���� ������ ���� ��������. \n ");
		ofstream ofs(fdir); // �������� �����
		ofs.close();
		printf(" ���� ��������. \n ");
		goto openf;
	}
	else
		printf(" ���� ������� ��� ������. \n ");

	system("pause");
}

void addzap()
{
	system("cls");
	int i, pp, j, t;
	progLanguage lang;

	f.clear();
	f.seekg(0, ios::end);
	i = f.tellp() / sizeof(struct progLanguage); // ��������� �������
s1:
	i++; //����� ������

	// �������� ���� ������:
	strcpy(lang.name, "");
	lang.year = 0;
	strcpy(lang.category, "");
	strcpy(lang.paradigm, "");
	strcpy(lang.lvl, "");
	strcpy(lang.authors, "");
	pp = 0;

	cout << "������ ����� � " << i << ": \n";
	cout << "�����: ";
	do
	{
		gets(lang.name);
		t = strlen(lang.name);
	} while (t == 0);
	for (j = t; j < p_name - 1; j++)
		strcat(lang.name, " ");
	//	
	cout << "�������� ����: ";
	do
	{
		gets(lang.category);
		t = strlen(lang.category);
	} while (t == 0);
	for (j = t; j < p_category - 1; j++)
		strcat(lang.category, " ");
	//
	cout << "��������� ����: ";
	do
	{
		gets(lang.paradigm);
		t = strlen(lang.paradigm);
	} while (t == 0);
	for (j = t; j < p_paradigm - 1; j++)
		strcat(lang.paradigm, " ");
	//	
	cout << "г���� ����: ";
	do
	{
		gets(lang.lvl);
		t = strlen(lang.lvl);
	} while (t == 0);
	for (j = t; j < p_lvl - 1; j++)
		strcat(lang.lvl, " ");
	//	
	cout << "������-����������: ";
	do
	{
		gets(lang.authors);
		t = strlen(lang.authors);
	} while (t == 0);
	for (j = t; j < p_authors - 1; j++)
		strcat(lang.authors, " ");
	//	
	cout << "г� ����������: ";
	cin >> lang.year;

	f.write((char*)&lang, sizeof(struct progLanguage));

s2:
	cout << "��� �������� ������ ������ �������� Enter, ��� ������ Esc \n";

	if ((pp = getch()) != 27)
		if (pp == 13)
			goto s1;
		else
			goto s2;
}

void all_out()
{
	progLanguage zap;
	int space, position = 0, im = 0;
	f.clear();
	f.seekp(0, ios::end);
	int size = f.tellp() / sizeof(struct progLanguage);
	if (size < 1)
	{
		cout << "���� �������";
		goto exit;
	}

start1:
	f.clear();
	f.seekp(position * countZinP * sizeof(struct progLanguage), ios::beg);
	system("cls");

	printf("|**                                    ʳ������ ������ � ���� = %5d                                      **|\n", size);
	cout << ".____________________________________________________________________________________________________________.\n";
	cout << "|     |      �����       |  г�  |  �������� ����  |  ��������� ����  |    г���� ����   |      ������      |\n";
	cout << "|=====|==================|=======|==================|==================|==================|==================|\n";
	space = 0;

	while ((!f.eof()) && (space < countZinP))
	{
		f.read((char*)&zap, sizeof(struct progLanguage));
		if (f.eof()) break;
		printf("| %2d  | %16s | %4d  | %16s | %16s | %16s | %16s |\n", ((1 + space) + ((position)*countZinP)), zap.name, zap.year, zap.category, zap.paradigm, zap.lvl, zap.authors);
		space++;
	}
	cout << "|=====|==================|=======|==================|==================|==================|==================|\n";
	printf("|<<<\"Up/Down - ���������� �� ����.\"<<< �%2d >>>\"Esc - ������� ���� \">>>|\n", position + 1);

ctrl:
	im = getch();
	switch (im)
	{
	case 80: // ����
	{
		if (position < (size - 1) / countZinP)
			position++;
		goto start1;
	}
	case 72: // �����
	{
		if (position >= 1)
			position--;
		goto start1;
	}
	case 27:
		goto exit;
	default:
		goto ctrl;
	}
exit:;
}

void editzap()
{
	int t, i, j, im;

start2:
	system("cls");
	progLanguage zap;
	int num = 0;
	cout << "������ ����� ������ ��� �����������:  \n";
	cin >> num;


	f.clear();
	f.seekp((num - 1) * sizeof(struct progLanguage), ios::beg);

	cout << ".______________________________________________________________________________________________________.\n";
	cout << "|      �����       |  г�  |  �������� ����  |  ��������� ����  |    г���� ����   |      ������      |\n";
	cout << "|==================|=======|==================|==================|==================|==================|\n";
	f.read((char*)&zap, sizeof(struct progLanguage));
	printf("| %16s | %4d | %16s | %16s | %16s | %16s |\n", zap.name, zap.year, zap.category, zap.paradigm, zap.lvl, zap.authors);
	cout << "|==================|=======|==================|==================|==================|==================|\n";
	printf("|<<<<<<<\"         ��� ������������ ����������� �������� Enter, � ��� ����� Esc           \">>>>>>>|\n");

control:
	im = getch();
	if (im == 13)
	{
		progLanguage lang;

		strcpy(lang.name, "");
		lang.year = 0;
		strcpy(lang.category, "");
		strcpy(lang.paradigm, "");
		strcpy(lang.lvl, "");
		strcpy(lang.authors, "");

		cout << "������ ��� ��������: \n";
		cout << "�����: ";
		do
		{
			gets(lang.name);
			t = strlen(lang.name);
		} while (t == 0);
		for (j = t; j < p_name - 1; j++)
			strcat(lang.name, " ");
		//		
		cout << "г� ����������: ";
		cin >> lang.year;
		// 	
		cout << "�������� ����: ";
		do
		{
			gets(lang.category);
			t = strlen(lang.category);
		} while (t == 0);
		for (j = t; j < p_category - 1; j++)
			strcat(lang.category, " ");
		// 	
		cout << "��������� ����: ";
		do
		{
			gets(lang.paradigm);
			t = strlen(lang.paradigm);
		} while (t == 0);
		for (j = t; j < p_paradigm - 1; j++)
			strcat(lang.paradigm, " ");
		// 	
		cout << "г���� ����: ";
		do
		{
			gets(lang.lvl);
			t = strlen(lang.lvl);
		} while (t == 0);
		for (j = t; j < p_lvl - 1; j++)
			strcat(lang.lvl, " ");
		// 	
		cout << "������-����������: ";
		do
		{
			gets(lang.authors);
			t = strlen(lang.authors);
		} while (t == 0);
		for (j = t; j < p_authors - 1; j++)
			strcat(lang.authors, " ");

		printf("|<<<<<<<\"��� ������������ ����������� �������� Enter, � ��� ����� Esc\">>>>>>>|\n");

	control2:
		im = getch();
		if (im == 13) // Enter
		{
			f.seekp((num - 1) * sizeof(struct progLanguage), ios::beg);
			f.write((char*)&lang, sizeof(struct progLanguage));
			goto start2;
		}
		else
			if (im == 27) // Esc
				goto start2;
		goto control2;
	}
	else
		if (im != 27)
			goto control;

	system("pause");
}

void delzap()
{
	system("cls");
	progLanguage zap;
	int im = 0, num = 0;

	cout << "������ ����� ������ ��� ���������: ";
	cin >> num;
	f.clear();
	f.seekp((num - 1) * sizeof(struct progLanguage), ios::beg);

	cout << " ��� ����� ���� �������� \n";
	cout << ".____________________________________________________________________________________________________________.\n";
	cout << "|     |      �����       |  г�  |  �������� ����  |  ��������� ����  |    г���� ����   |      ������      |\n";
	cout << "|=====|==================|=======|==================|==================|==================|==================|\n";
	f.read((char*)&zap, sizeof(struct progLanguage));
	printf("| %16s | %4d | %16s | %16s | %16s | %16s |\n", zap.name, zap.year, zap.category, zap.paradigm, zap.lvl, zap.authors);
	cout << "|=====|==================|=======|==================|==================|==================|==================|\n";
	printf("|<<<<<<<\"��� ������������ ����������� �������� Enter, � ��� ����� Esc\">>>>>>>|\n");
control:
	im = getch();
	if (im == 13) // Enter
	{
		f.clear();
		f.seekp(0, ios::end);
		int size = f.tellp() / sizeof(struct progLanguage);

		progLanguage* mas;

		mas = new progLanguage[size + 1]; // ��������� ������
		f.clear();
		f.seekp(0, ios::beg);
		int i = 0;
		while (!f.eof())
		{
			f.read((char*)&mas[i], sizeof(struct progLanguage));
			i++;
		}
		f.close();
		f.clear();
		f.open(fdir, ios::in | ios::out | ios::trunc);
		f.seekp(0, ios::beg);
		for (i = 0; i < size; i++)
			if (i != (num - 1))
				f.write((char*)&mas[i], sizeof(struct progLanguage));

		delete[]mas;
		cout << "����� �������� \n";
	}
	else
		if (im != 27)
			goto control;
}

void exit_prog()
{
	system("cls");
	cout << "\n\n ��������: Enter ��� ���� ��� ����� / Esc ��� ���� ��� ����������� � ������� ����. \n\n";
st:
	int go = getch();
	if (go != 13)
		if (go == 27)
			goto exit;
		else
			goto st;
	if (f.is_open())
		f.close();
	exit(0);
exit:;
}


void searchzap()
{
	progLanguage zap;
	int i, k, t, year, diff, im = 0, p = 0;
	char txt[16];
	COORD crd, end;
	crd.X = 73;
	crd.Y = 5;
	end.X = 0;
	end.Y = 15;

start:
	f.clear();
	system("cls");
	cout << "|============================================================================|\n";
	cout << "|                                �����                                       |\n";
	cout << "|============================================================================|\n";
	cout << "| *                                                                        * |\n";
	cout << "|============================================================================|\n";
	cout << "| 1. ���� �������������, �� ������� �� ������ N ����                       |\n";
	cout << "| 2. ���� ������������� �������� ����                                       |\n";
	cout << "| 3. ��������� ������� ��� ������������� � ������ �������               |\n";
	cout << "| 4. ���� ������������� ������ ���������                                    |\n";
	cout << "| 5. ���� ������������� �������� ����������                                  |\n";
	cout << "| 6. ����, �� ������� � ������� ����� �� ���������� ��������� ���������    |\n";
	cout << "| 7. ���i�                                                                   |\n";
	cout << "|============================================================================|\n";

	SetConsoleCursorPosition(hConsole, crd);
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 2) | 10));
	cout << " <<<";
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 2) | 10));
	SetConsoleCursorPosition(hConsole, end);

	im = getch();
	switch (im)
	{
	case 72: // Up
	{
		if (crd.Y > 5) crd.Y--;
		goto start;
	}
	case 80: // Down
	{
		if (crd.Y < 11) crd.Y++;
		goto start;
	}
	case 13:
	{
		p = crd.Y + 45;
		if ((!f.is_open()) && (p != 55)) p = 50;
		switch (p)
		{
		case 50:
		{
			cout << "����i�� ������ N ���� ��� ������: \n\n";
			cin >> year;
			diff = 2022 - year;

			cout << ".______________________________________________________________________________________________________.\n";
			cout << "|      �����       |  г�  |  �������� ����  |  ��������� ����  |    г���� ����   |      ������      |\n";
			cout << "|==================|=======|==================|==================|==================|==================|\n";

			for (int i = 0; (!f.eof()) && (i < countZinP); i++)
			{
				f.read((char*)&zap, sizeof(struct progLanguage));
				if (f.eof()) break;
				if (diff <= zap.year) printf("| %16s | %4d  | %16s | %16s | %16s | %16s |\n", zap.name, zap.year, zap.category, zap.paradigm, zap.lvl, zap.authors);
			}
			goto end;
		}
		case 51:
		{
			cout << "����i�� ����i���� �i����: ";
			do
			{
				gets(txt);
				t = strlen(txt);
			} while (t == 0);
			for (i = t; i < 15; i++)
				strcat(txt, " ");


			cout << ".______________________________________________________________________________________________________.\n";
			cout << "|      �����       |  г�  |  �������� ����  |  ��������� ����  |    г���� ����   |      ������      |\n";
			cout << "|==================|=======|==================|==================|==================|==================|\n";

			for (i = 0; (!f.eof()) && (i < countZinP); i++)
			{
				f.read((char*)&zap, sizeof(struct progLanguage));
				if (f.eof()) break;
				if (zap.lvl == txt) printf("| %16s | %4d  | %16s | %16s | %16s | %16s |\n", zap.name, zap.year, zap.category, zap.paradigm, zap.lvl, zap.authors);
			}

			goto end;
		}
		case 52:
		{

			goto start;
		}
		case 53:
		{

			goto start;
		}
		case 54:
		{

			goto start;
		}
		case 55:
		{

			goto start;
		}
		default: goto start;
		}
	}
	default: goto start;
	}

end:
	cout << "|==================|=======|==================|==================|==================|==================|\n";
	cout << "|<<<                       Esc - ������� ���� / Enter - ����� �����                                 >>>|\n";
	im = getch();
	if (im != 27)
	{
		if (im == 13) goto start;
		else goto end;
	}
}


void menu()
{
	int im = 0, p = 0;
	COORD crd, end;
	crd.X = 40;
	crd.Y = 5;
	end.X = 0;
	end.Y = 15;
start:
	system("cls");
	cout << "|============================================================================|\n";
	cout << "|                        ������� ��� �������������                          |\n";
	cout << "|============================================================================|\n";
	cout << "| *                             ������� ����                               * |\n";
	cout << "|============================================================================|\n";
	cout << "| 1. ³������/�������� ����                                                  |\n";
	cout << "| 2. ������ ����� � �����                                                    |\n";
	cout << "| 3. ���������� �����                                                        |\n";
	cout << "| 4. �������� ����� � �����                                                  |\n";
	cout << "| 5. ������� ��� ���������� � �����                                          |\n";
	cout << "| 6. �����                                                                   |\n";
	cout << "| 7. ���i�                                                                   |\n";
	cout << "|============================================================================|\n";
	if (!f.is_open())
		cout << "\n ���� �������, ���������� ��� ������� ����. \n";
	else
		cout << "\n ���� ������ �����������.: \"" << fdir << "\"\n";
	SetConsoleCursorPosition(hConsole, crd);
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 2) | 10));
	cout << " <<<<<< ";
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 2) | 10));
	SetConsoleCursorPosition(hConsole, end);
	im = getch();
	switch (im)
	{
	case 72: // Up
	{
		if (crd.Y > 5) crd.Y--;
		goto start;
	}
	case 80: // Down
	{
		if (crd.Y < 11) crd.Y++;
		goto start;
	}
	case 13:
	{
		p = crd.Y + 45;
		if ((!f.is_open()) && (p != 56)) p = 50;
		switch (p)
		{
		case 50:
		{
			openNew();
			goto start;
		}
		case 51:
		{
			addzap();
			goto start;
		}
		case 52:
		{
			editzap();
			goto start;
		}
		case 53:
		{
			delzap();
			goto start;
		}
		case 54:
		{
			all_out();
			goto start;
		}
		case 55:
		{
			searchzap();
			goto start;
		}
		case 56:
		{
			exit_prog();
			goto start;
		}
		default: goto start;
		}
	}
	default: goto start;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 2) | 10));

	menu();
	system("pause");
	return 0;
}
