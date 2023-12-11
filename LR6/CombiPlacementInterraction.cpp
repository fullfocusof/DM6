#include "CombiPlacementInterraction.h"

CombiPlacementInterraction::CombiPlacementInterraction()
{
	
}

void CombiPlacementInterraction::printQuit()
{
	cout << endl << endl << "Backspace - возврат в меню";

	int answ = _getch();
	bool press = false;

	while (!press)
	{
		if (answ == 8)
		{
			press = true;
			break;
		}
		else
		{
			answ = _getch();
		}
	}

	system("cls");
}

void CombiPlacementInterraction::genComb(vector<vector<int>>& result, int n, int k)
{
    if (k == n)
    {
        vector<int> temp(n);
        for (int j = 0; j < temp.size(); j++)
        {
            temp[j] = j;
        }
        reverse(temp.begin(), temp.end());
        result.push_back(temp);

        return;
    }

    if (k == 0)
    {
        result.push_back(vector<int>());

        return;
    }

    vector<int> comb(n + 2);

    for (int j = 1; j <= k; j++) 
    {
        comb[j] = j - 1;
    }
    comb[k + 1] = n;
    comb[k + 2] = 0;

    while (true) 
    {
        vector<int> temp;
        copy(comb.begin() + 1, comb.begin() + k + 1, back_inserter(temp));
        reverse(temp.begin(), temp.end());
        result.push_back(temp);

        int j = 1;
        while (comb[j + 1] == comb[j] + 1)
        {
            comb[j] = j - 1;
            j++;
        }

        if (j > k) 
        {
            break;
        }

        comb[j] += 1;
    }
}

void CombiPlacementInterraction::nextPerm(vector<int>& variety)
{
    int i = variety.size() - 2;
    while (i >= 0 && variety[i] >= variety[i + 1])
    {
        i--;
    }

    if (i < 0)
    {
        reverse(variety.begin(), variety.end());
        return;
    }

    int lastId = variety.size() - 1;
    while (lastId > i && variety[lastId] <= variety[i])
    {
        lastId--;
    }

    swap(variety[i], variety[lastId]);
    reverse(variety.begin() + i + 1, variety.end());
}

void CombiPlacementInterraction::genPlaces(vector<vector<int>>& result, int n, int k)
{
    vector<vector<int>> temp;
    genComb(temp, n, k);

    for (auto comb : temp)
    {
        reverse(comb.begin(), comb.end());       
        do
        {
            result.push_back(comb);
            nextPerm(comb);
        } while (!is_sorted(comb.begin(), comb.end()));
    }
}