#pragma once
#include "Row.h"
#include "SimProbertys.h"

class Brain
{

public:
	Brain( vector<int> rowSizes, int outputSize, int inputSize);
	Brain( vector<Row> rows);
	Brain( SimProbertys simProbertys );

	void addSimProb(SimProbertys simProb);

	void BrainRandomize(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais);
	void BrainRandomizeRow(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais, int index);
	void RandomiveBasedOnRefrance(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais);


	vector<float> out(vector<float> input);
	void Update();
	void getValue(std::string name, bool& out);
	void getValue(std::string name, float& out);
	void getValue(std::string name, int& out);

	void setBrain(Brain brain);

	Brain getBrain();
	Brain* getBrain_prt();
	vector<Row> getRows();
	vector<Row>* getRows_prt();

	Row* getRowsIndex_prt(int index);
	Row getRowsIndex(int index);

	int getInputSize();

	SimProbertys simProb;




private:
	vector<Row> rows;

	int inputSize = 0;

};

