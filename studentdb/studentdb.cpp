#include <iostream>
#include <string>
#include "student.hpp"
using namespace std;

int main()
{
	Student s[10];
	cout << "[1] Dodaj studenta (imie_, nazwisko_, nr_indeks_u)\n";
	cout << "[2] Sortuj po nr indeks_u \n";
	cout << "[3] Usun po nr indkesu \n";
	cout << "[4] Wyjscie \n";

	
	int menu, ktory, i = 0;

	do
	{
		cout << "Wybierz co chcesz zrobić: ";
		cin >> menu;

		switch (menu)
		{
		case 1:	
			cin >> s[i].imie_ >> s[i].nazwisko_ >> s[i].indeks_;
			i++;
			break;

		case 2:
			for (int k = 0; k < i; k++)
			{
				for (int j = 0; j < i - 1; j++)
				{
					if (s[j].indeks_ > s[j + 1].indeks_)
					{
						swap(s[j].indeks_, s[j + 1].indeks_);
						swap(s[j].imie_, s[j + 1].imie_);
						swap(s[j].nazwisko_, s[j + 1].nazwisko_);
					}

				}
			}
			break;

		case 3:
			cout << "Podaj numer indeks_u do usuniecia: ";
			int nrIndeks;
			cin >> nrIndeks;
			for(int k = 0; k < i; k++)
			{
				if(nrIndeks == s[k].indeks_)
				{
					if(k == i)
					{
						i--;
					}
					else
					{
						for(int j = k; j < i - 1; j++)
							swap(s[j], s[j+1]);
						i--;
					}
				break;		
				}
			}
 
			break;

		}
	} while (menu != 4);

	for (int j = 0; j < i; j++)
	{
		cout << s[j].imie_ << "\t" << s[j].nazwisko_ << "\t" << s[j].indeks_ << endl;
	}

	cin.get();
	return 0;
}
