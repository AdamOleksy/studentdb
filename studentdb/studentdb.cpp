#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string imie, nazwisko;
	int indeks;
}s[10];

int main()
{
	cout << "[1] Dodaj studenta (imie, nazwisko, nr_indeksu)\n";
	cout << "[2] Sortuj po nr indeksu \n";
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
			cin >> s[i].imie >> s[i].nazwisko >> s[i].indeks;
			i++;
			break;

		case 2:
			for (int k = 0; k < i; k++)
			{
				for (int j = 0; j < i - 1; j++)
				{
					if (s[j].indeks > s[j + 1].indeks)
					{
						swap(s[j].indeks, s[j + 1].indeks);
						swap(s[j].imie, s[j + 1].imie);
						swap(s[j].nazwisko, s[j + 1].nazwisko);
					}

				}
			}
			break;

		case 3:
			cout << "Podaj numer indeksu do usuniecia: ";
			int nrIndeks;
			cin >> nrIndeks;
			for(int k = 0; k < i; k++)
			{
				if(nrIndeks == s[k].indeks)
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
		cout << s[j].imie << "\t" << s[j].nazwisko << "\t" << s[j].indeks << endl;
	}

	cin.get();
	return 0;
}
