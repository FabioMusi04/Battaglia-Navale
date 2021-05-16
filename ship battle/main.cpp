#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;

int maxships = 10;

int matrix[rows][elements];

void Clear()
{
	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < elements; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Show()
{
	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < elements; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int NumberOfShips()
{
	int c = 0;

	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < elements; j++)
		{
			if(matrix[i][j] == 1)
				c++;
		}
	}

	return c;
}

void SetShips()
{
	int s = 0;
	while(s < maxships)
	{
		int x = rand() % rows;
		int y = rand() % elements;
		if(matrix[x][y] != 1)
		{
			s++;
			matrix[x][y] = 1;
		}
	}
}

bool Attack(int x,int y)
{
	if(matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

int main()
{
    while(1){
        srand(time(NULL));
        Clear();
        SetShips();
        int pos1,pos2;
        string ris;
        cout << "Inserisci coordinate attacco (Numero Numero) ";
        cin >> pos1 >> pos2;
        if (cin.fail() || pos1 < 0 || pos1 > rows || pos2 < 0 || pos2 > elements){
            cout << "Input non valido" << endl;
            return 0;
        }
        else{
            if(Attack(pos1,pos2))
                cout << "Mi hai beccato :)" << endl;
            else
                cout << "Nessuna barca in quella posizione" << endl;
            cout << "Numero di barche rimaste: " << NumberOfShips() << endl;
            cout << "Ti vuoi arrendere (per uscire digitare ESC)? "; cin >> ris;
            if(cin.fail()){
                cout << "Input non valido" << endl;
                return 0;
            }
            if(ris == 'ESC')
                return 0;
        }
    }
cout << "Game over!" << endl;
    Show();
    system("pause");
    return 0;
}
