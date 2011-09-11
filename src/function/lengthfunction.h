#ifndef LENGTHFUNCTION_H
#define LENGTHFUNCTION_H

#include "function.h"
#include "context.h"

class LengthFunction : public Function
{
public:
	LengthFunction();
	Value* evaluate(Context*);
};

#endif // LENGTHFUNCTION_H
