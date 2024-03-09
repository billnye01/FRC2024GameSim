#include "NeuralNetWorkRow.h"

NeuralNetWorkRow::NeuralNetWorkRow(int size)
{
	Wights = vector<vector<double>>(size);
	this->size = size;
}

vector<double> NeuralNetWorkRow::getValues(vector<double> inputsUse)
{
	vector<double> out(size);

	for (int i = 0; i < size; i++)
	{
		vector<double> WightsForNeron = Wights[i];
		double Resalt = Bias;

		for (int j = 0; j < WightsForNeron.size(); j++)
		{
			Resalt =  inputsUse[j] * WightsForNeron[j];
		}

		out[i] = 1 / (1 + exp(-Resalt));
	}

	return out;
}

vector<vector<double>> NeuralNetWorkRow::getWights()
{
	return Wights;
}

double NeuralNetWorkRow::getBais()
{
	return Bias;
}

int NeuralNetWorkRow::getSize()
{
	return size;
}

void NeuralNetWorkRow::setWights(vector<vector<int>> wights)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < wights[i].size(); j++)
		{
			Wights[i][j] = wights[i][j];
		}
	}
}

void NeuralNetWorkRow::randomizeWightsBasedOnValue(double MaxChange)
{
	for (int i = 0; i < Wights.size(); i++) {
		
		for (int j = 0; j < Wights[i].size(); j++)
		{

			Wights[i][j] += sin(rand() * i / j) * MaxChange;
			if (Wights[i][j] > 1) {
				Wights[i][j] = 1;
			}
			else if (Wights[i][j] < 0)
			{
				Wights[i][j] = 0;
			}
		}
	}
}

void NeuralNetWorkRow::randomizeWights()
{
	for (int i = 0; i < Wights.size(); i++) {

		for (int j = 0; j < Wights[i].size(); j++)
		{

			Wights[i][j] = abs(sin(rand() * i));

		}
	}
}

void NeuralNetWorkRow::randomizeBiasBasedOnValue(double MaxChange)
{
	Bias += sin(rand()) * MaxChange;

	if (Bias > 1) {
		Bias = 1;
	}
	else if (Bias < 0)
	{
		Bias = 0;
	}
}

void NeuralNetWorkRow::randomizeBias()
{
	Bias = abs(sin(rand()));
}

void NeuralNetWorkRow::setBias(double Bias)
{
	this->Bias = Bias;
}
