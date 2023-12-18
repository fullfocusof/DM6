#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

class CombiPlacementInterraction
{

public:

	CombiPlacementInterraction();

	void printQuit();

	void genComb(vector<vector<int>>& result, int n, int k);
	void genPlaces(vector<vector<int>>& result, int n, int k);
	void nextPerm(vector<int>& variety);

	int factorial(int num);
	int binomCoef(int n, int k);
	vector<int> genCombFromNum(int n, int k, int index);

	int genNumFromComb(vector<int> comb, int n);
};