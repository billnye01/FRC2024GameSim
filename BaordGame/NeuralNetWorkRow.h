#pragma once

#include <iostream>
#include <vector>
#include <cstdlib> 


using namespace std;

class NeuralNetWorkRow
{

public:
	NeuralNetWorkRow(int size);

	vector<double> getValues(vector<double> inputsUse);

	vector<vector<double>> getWights();
	double getBais();
	int getSize();
	
	void setWights(vector<vector<int>> wights);
	void randomizeWightsBasedOnValue(double MaxChange);
	void randomizeWights();

	void randomizeBiasBasedOnValue(double MaxChange);
	void randomizeBias();
	void setBias(double Bias);

private:
	vector<double>* Inputs;

	//neron
	vector<
		//wights
		vector<double>> Wights;

	int size;

	double Bias;
};

