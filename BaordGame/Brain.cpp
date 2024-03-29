#include "Brain.h"

Brain::Brain( vector<int> rowSizes, int outputSize, int inputSize)
{


    this->inputSize = inputSize;
        for (int i = 0; i < rowSizes.size() + 1; i++) {

            if (i == 0) {
                this->rows.push_back(Row(inputSize, rowSizes[0]));
            }
            else if (i == rowSizes.size())
            {
                this->rows.push_back(Row(rowSizes[i - 1], outputSize));
            }
            else
            {
                this->rows.push_back(Row(rowSizes[i - 1], rowSizes[i]));
            }
            
        }

}

/*
Brain::Brain(vector<Row> rows, int inputSize)
{
    this->inputSize = inputSize;
    this->rows = rows;
}*/

void Brain::BrainRandomize(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais)
{

    for (int i = 0; i < rows.size(); i++)
    {
        rows[i].RandomizeCells(minValueWeights, maxValueWeights, minValueBais, maxValueBais);
    }
}

void Brain::BrainRandomizeRow(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais, int index)
{
}

void Brain::setBrain(Brain brain)
{
    *this = brain;
}

void Brain::RandomiveBasedOnRefrance(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais)
{
    for (int i = 0; i < rows.size(); i++)
    {
        rows[i].ModfiCells(minValueWeights, maxValueWeights, minValueBais, maxValueBais);
    }
}

vector<float> Brain::out(vector<float> input)
{
    vector<float> PastOutputs = input;

    if (input.size() != inputSize) {
        cout << "Incorrect Input Size";
        return vector<float>(0);
    }

    for (int i = 0; i < rows.size(); i++) {
        PastOutputs = rows[i].out(PastOutputs);
    }

    return PastOutputs;
}

Brain Brain::getBrain()
{
    return *this;
}

Brain* Brain::getBrain_prt()
{
    return this;
}

vector<Row> Brain::getRows()
{
    return rows;
}

vector<Row>* Brain::getRows_prt()
{
    return &rows;
}

Row* Brain::getRowsIndex_prt(int index)
{
    return &rows[index];
}

Row Brain::getRowsIndex(int index)
{
    return rows[index];
}
