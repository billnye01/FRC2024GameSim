#include "BrainContruller.h"

BrainContruller::BrainContruller(int Rows, int RowSize)
{
    rows = vector<NeuralNetWorkRow>(Rows);
    
    for (int i = 0; i < rows.size(); i++) {
        rows[i] = NeuralNetWorkRow();
    }
}

vector<int> BrainContruller::GetValue(vector<int> inputs)
{
    return vector<int>();
}

vector<NeuralNetWorkRow> BrainContruller::getRows()
{
    return vector<NeuralNetWorkRow>();
}

void BrainContruller::setRows(vector<NeuralNetWorkRow> rows)
{
}
