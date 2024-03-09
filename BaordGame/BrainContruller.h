#pragma once

#include "NeuralNetWorkRow.h"

class BrainContruller
{

public:
	BrainContruller(int Rows, int RowSize);

	vector<int> GetValue(vector<int> inputs);

	vector<NeuralNetWorkRow> getRows();

	void setRows(vector<NeuralNetWorkRow> rows);

private:
	vector<NeuralNetWorkRow> rows;

};

