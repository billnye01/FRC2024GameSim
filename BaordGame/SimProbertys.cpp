#include "SimProbertys.h"

setup SimProbertys::GenSetUp(vector<int> RowSizes)
{
	setup SetUp;

	SetUp.inSize = InputInfo.outType.size();
	SetUp.outSize = OutputInfo.outType.size();
	SetUp.rowSizes = RowSizes;

	return SetUp;
}

void SimProbertys::setSetUp(setup setUp)
{
	this->setUpInfo = setUp;
}

Float SimProbertys::genFloat(float min, float max, string name)
{
	Float newFloat;
	newFloat.max = max;
	newFloat.min = min;

	newFloat.outType.name = name;

	return newFloat;
}
Float SimProbertys::genFloat(float* InputPrt, string name)
{
	Float newFloat;
	newFloat.Inputprt = InputPrt;

	newFloat.outType.name = name;

	return newFloat;
}
Int SimProbertys::genInt(int min, int max, string name)
{
	Int newInt;
	newInt.max = max;
	newInt.min = min;

	newInt.outType.name = name;

	return newInt;
}

Int SimProbertys::genInt(int* intgerprt, string name)
{
	Int newInt;
	newInt.Inputprt = intgerprt;

	newInt.outType.name = name;

	return newInt;
}

Boolean SimProbertys::genBool(float therashould, string name)
{
	Boolean newBool;
	newBool.Threashould = therashould;

	newBool.outType.name = name;

	return newBool;
}

Boolean SimProbertys::genBool(float therashould, bool* boolprt, string name)
{
	Boolean newFloat;
	newFloat.Inputprt = boolprt;
	newFloat.Threashould = therashould;

	newFloat.outType.name = name;

	return newFloat;
}

void SimProbertys::setInput(Float in)
{
	OutputType* NewOutType = &in.outType;
	NewOutType->type = 'F';
	NewOutType->arrayNum = InputInfo.floatInputs.size();
	NewOutType->outIdex = InputInfo.outType.size();

	OutputInfo.floatOutput.push_back(in);
	OutputInfo.outType.push_back(NewOutType);
}

void SimProbertys::setInput(Int in)
{
	OutputType* NewOutType = &in.outType;
	NewOutType->type = 'I';
	NewOutType->arrayNum = InputInfo.intsInputs.size();
	NewOutType->outIdex = InputInfo.outType.size();

	InputInfo.intsInputs.push_back(in);
	InputInfo.outType.push_back(NewOutType);
}

void SimProbertys::setInput(Boolean in)
{
	OutputType* NewOutType = &in.outType;
	NewOutType->type = 'B';
	NewOutType->arrayNum = InputInfo.boolInputs.size();
	NewOutType->outIdex = InputInfo.outType.size();

	InputInfo.boolInputs.push_back(in);
	InputInfo.outType.push_back(NewOutType);
}

void SimProbertys::setOutput(Float in)
{
	OutputType* NewOutType = &in.outType;
	NewOutType->type = 'F';
	NewOutType->arrayNum = OutputInfo.floatOutput.size();
	NewOutType->outIdex = OutputInfo.outType.size();

	OutputInfo.floatOutput.push_back(in);
	OutputInfo.outType.push_back(NewOutType);
}

void SimProbertys::setOutput(Boolean in)
{
	OutputType* NewOutType = &in.outType;
	NewOutType->type = 'B';
	NewOutType->arrayNum = OutputInfo.floatOutput.size();
	NewOutType->outIdex = OutputInfo.outType.size();

	OutputInfo.boolOutput.push_back(in);
	OutputInfo.outType.push_back(NewOutType);
}

void SimProbertys::setOutput(Int in)
{
	OutputType* NewOutType = &in.outType;
	NewOutType->type = 'I';
	NewOutType->arrayNum = OutputInfo.floatOutput.size();
	NewOutType->outIdex = OutputInfo.outType.size();

	OutputInfo.intOutput.push_back(in);
	OutputInfo.outType.push_back(NewOutType);
}



void SimProbertys::updateOutputs(vector<float> inputs)
{
	if (inputs.size() != OutputInfo.outType.size()) {
		return;
	}

	for (int i = 0; i < OutputInfo.outType.size(); i++) {

		// if float
		if (OutputInfo.outType[i]->type == 'F') {
			OutputInfo.floatOutput[OutputInfo.outType[i]->arrayNum].LastRecoredOutput
				= FloatFun(inputs[OutputInfo.outType[i]->outIdex],
					&OutputInfo.floatOutput[OutputInfo.outType[i]->arrayNum]);
		}
		else if (OutputInfo.outType[i]->type == 'I')
		{
			OutputInfo.intOutput[OutputInfo.outType[i]->arrayNum].LastRecoredOutput
				= intFun(inputs[OutputInfo.outType[i]->outIdex],
					&OutputInfo.intOutput[OutputInfo.outType[i]->arrayNum]);
		}
		else if(OutputInfo.outType[i]->type == 'B')
		{
			OutputInfo.boolOutput[OutputInfo.outType[i]->arrayNum].LastRecoredOutput
				= boolFun(inputs[OutputInfo.outType[i]->outIdex],
					&OutputInfo.boolOutput[OutputInfo.outType[i]->arrayNum]);
		}
	}
}

vector<float> SimProbertys::getInputs()
{
	vector<float> out;

	for (int i = 0; i < InputInfo.outType.size(); i++) {
		OutputType* outType = InputInfo.outType[i];
		if (outType->type == 'B') {
			out.push_back(
				&InputInfo.boolInputs[outType->arrayNum].Inputprt
				? 
				1:
				0
			);
		}
		else if(outType->type == 'I')
		{
			out.push_back(
				*InputInfo.intsInputs[outType->arrayNum].Inputprt
			);
		}
		else if(outType->type =='F')
		{

			out.push_back(
				*InputInfo.floatInputs[outType->arrayNum].Inputprt
			);
		}
	}

	return out;
}

float SimProbertys::FloatFun(float input, Float* floatin)
{
	return
		min(
			(float)max(
				(float)input,
				(float)floatin->min
			),

			(float)floatin->max
		);
}

int SimProbertys::intFun(float input, Int* intIn)
{
	return
		min(
			(int)max(
				(int)round(input),
				(int)intIn->min
			),

			(int)intIn->max
	);
}

bool SimProbertys::boolFun(float input, Boolean* boolIn)
{
	return
		input < boolIn->Threashould;
}
