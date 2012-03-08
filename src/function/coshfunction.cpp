#include "coshfunction.h"
#include "numbervalue.h"
#include "math.h"

CoshFunction::CoshFunction() : Function("cosh")
{
}

Value* CoshFunction::evaluate(Context* ctx)
{
	NumberValue* numVal=dynamic_cast<NumberValue*>(ctx->getArgument(0,"value"));
	if(numVal) {
		double num=numVal->getNumber();

		return new NumberValue(cosh(num));
	}
	return new Value();
}
