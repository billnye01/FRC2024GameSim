#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;


class OutputType
{
public:
	std::string name;
	int outIdex;
	int arrayNum;
	char type;
};

struct Boolean
{
public:
	bool LastRecoredOutput;
	bool* Inputprt;

	float Threashould;
	OutputType outType;
};

struct Float
{
public:
	float LastRecoredOutput;
	float* Inputprt;

	float min;
	float max;
	OutputType outType;
};


struct Int
{
public:
	int LastRecoredOutput;
	int* Inputprt;

	int min;
	int max;
	OutputType outType;
};

struct setup {
public:
	float speed;

	int outSize;
	int inSize;
	std::vector<int> rowSizes;
};

template <typename T>
class DistanceLimit
{
public:
	int x;
	int y;

	int Dist;

	T type;
	
	OutputType outType;
};

struct inputInfo
{
public:
	std::vector<OutputType*> outType;
	std::vector<Float> floatInputs;
	std::vector<Boolean> boolInputs;
	std::vector<Int> intsInputs;
};

struct outputInfo
{
public:
	std::vector<OutputType*> outType;
	std::vector<Float> floatOutput;
	std::vector<Int> intOutput;
	std::vector<Boolean> boolOutput;
};

class SimProbertys
{



public:

	setup GenSetUp(vector<int> RowSizes);
	void setSetUp(setup setUp);

	static Float genFloat(float min, float max, string name);
	static Float genFloat(float* InputPrt, string name);

	static Int genInt(int min, int max, string name);
	static Int genInt(int* intgerprt, string name);

	static Boolean genBool(float therashould, string name);
	static Boolean genBool(float therashould, bool* boolprt, string name);

	void setInput(Float in);
	void setInput(Int in);
	void setInput(Boolean in);

	void setOutput(Float in);
	void setOutput(Boolean in);
	void setOutput(Int in);

	void updateOutputs(vector<float> inputs);
	vector<float> getInputs();

	template <class T> T getValue(string name);

	outputInfo OutputInfo;
	inputInfo InputInfo;
	setup setUpInfo;

private:
	float FloatFun(float input, Float* floatin);
	int intFun(float input, Int* intIn);
	bool boolFun(float input, Boolean* boolIn);

};

template<class T>
inline T SimProbertys::getValue(string name)
{
	char type = (is_same<T, bool>::value) ? 'B' :
		(is_same<T, int>::value) ? 'I' :
		(is_same<T, float>::value) ? 'F' : '_';

	if (type == '_') {
		// Handle unsupported type
		throw std::invalid_argument("Unsupported type provided.");
	}

	for (size_t i = 0; i < OutputInfo.outType.size(); i++) {
		if (type == OutputInfo.outType[i]->type && name == OutputInfo.outType[i]->name) {
			switch (type) {
			case 'B':
				return static_cast<T>(OutputInfo.boolOutput[OutputInfo.outType[i]->arrayNum].LastRecoredOutput);
			case 'I':
				return static_cast<T>(OutputInfo.intOutput[OutputInfo.outType[i]->arrayNum].LastRecoredOutput);
			case 'F':
				return static_cast<T>(OutputInfo.floatOutput[OutputInfo.outType[i]->arrayNum].LastRecoredOutput);
			}
		}
	}

	// Handle case where the name or type doesn't match
	throw std::invalid_argument("Value not found for the provided name and type.");
}
