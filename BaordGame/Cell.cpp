#include "Cell.h"

#include <vector>

Cell::Cell(int amountOfInputs) : cellvalues() {
	cellvalues.Weights = vector<float>(amountOfInputs);
}

void Cell::RandomlySetWeights(float Min, float Max, int amountOfInputs)
{
	vector<float> weights(amountOfInputs);

	for (int i = 0; i < weights.size(); i++)
	{
		weights[i] = getRandomNumberInRange(Min, Max);
		cout << "Weight index " << i << " value: " << weights[i] << " And Random number: " << rand() << "\n";
	}

	cellvalues.Weights = weights;
}

void Cell::RandomlySetWeightsBais(float Min, float Max)
{
	cellvalues.Bais = getRandomNumberInRange(Min, Max);
	cout << "Bais value: " << cellvalues.Bais << " And Random number: " << rand() << "\n";
}

void Cell::setCellValues(cellValues m_cellValues)
{
	cellvalues = m_cellValues;
}

void Cell::setBais(float m_Bais)
{
	cellvalues.Bais = m_Bais;
}

void Cell::setWeights(vector<float> m_Weights)
{
	cellvalues.Weights = m_Weights;
}

void Cell::setWeightsRandomlyOnARefrancePoint(float MaxUp, float MinDown)
{
	for (int i = 0; i < cellvalues.Weights.size(); i++) {
		cellvalues.Weights[i] += getRandomNumberInRange(MinDown, MaxUp);
	}
}

void Cell::setBaisRandomlyOnARefrancePoint(float MaxUp, float MinDown)
{
	cellvalues.Bais += getRandomNumberInRange(MinDown, MaxUp);
}

float Cell::getValue(vector<float> Inputs)
{
	if (Inputs.size() < cellvalues.Weights.size()) {
		cout << "Inputs inputs to small compaired to weights, weights size: " << cellvalues.Weights.size() << " Inputs size: " << Inputs.size() << "\n";
		return 0;
	}

	float out = 0;

	for (int i = 0; i <  cellvalues.Weights.size(); i++)
	{
		out += Inputs[i] * cellvalues.Weights[i];
	}

	out += cellvalues.Bais;

	//sigmoid
	out = out / (1 + abs(out));

	return out;
}

cellValues Cell::getCellValues()
{
	return cellvalues;
}

cellValues* Cell::getCellValues_ptr()
{
	return &cellvalues;
}

float Cell::getRandomNumberInRange(float min, float max)
{
	//cout << "randomNumber: " << abs(rand()) * (max - min) + max << endl;
	return abs(rand()) * (max - min) + max;
}
