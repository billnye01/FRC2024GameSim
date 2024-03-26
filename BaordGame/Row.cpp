#include "Row.h"

Row::Row(int amountOfInputs, int amountOfOutputs):
	cells(vector<Cell>(amountOfOutputs)), amountOfInputs(amountOfInputs)
{
	for (int i = 0; i < amountOfOutputs; i++)
	{
		cells[i] = Cell(amountOfInputs);
	}
}

vector<Cell> Row::getCells()
{
	return cells;
}

vector<cellValues*> Row::getCellValues()
{
	vector<cellValues*> out(cells.size());

	for (int i = 0; i < cells.size(); i++) {
		out[i] = cells[i].getCellValues_ptr();
	}

	return out;
}

void Row::setCells(vector<Cell> cells)
{
	this->cells = cells;

}

void Row::ModfiCells(float minWeights, float maxWeights, float minBais, float maxBais)
{
	for (int i = 0; i < cells.size(); i++) {
		cells[i].setBaisRandomlyOnARefrancePoint(minBais, maxBais);
		cells[i].setBaisRandomlyOnARefrancePoint(minWeights, maxWeights);
	}
}

void Row::RandomizeCells(float minWeights, float maxWeights, float minBais, float maxBais)
{
	for (int i = 0; i < cells.size(); i++) {
		cells[i].RandomlySetWeightsBais(minBais, maxBais);
		cells[i].RandomlySetWeights(minWeights, maxWeights, cells.size());
	}
}

vector<float> Row::out(vector<float> in)
{
	cout << "starting row\n";
	vector<float> out(cells.size());

	for (int i = 0; i < cells.size(); i++) {
		cout << "starting cell with id : " << i << "\n";
		out[i] = cells[i].getValue(in);
	}

	return out;
}
