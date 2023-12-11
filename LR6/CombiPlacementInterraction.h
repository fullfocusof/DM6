#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <Windows.h>
#include <conio.h>

using namespace std;

class CombiPlacementInterraction
{

public:

	CombiPlacementInterraction();

	void printQuit();

	void genComb(vector<vector<int>>& result, int n, int k);
	void genPlaces(vector<vector<int>>& result, int n, int k);
	void nextPerm(vector<int>& variety);


};