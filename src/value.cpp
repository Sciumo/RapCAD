/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010  Giles Bathgate
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "value.h"

Value::Value()
{
}

void Value::setName(QString name)
{
	this->name = name;
}

QString Value::getName()
{
	return this->name;
}

QString Value::getValueString()
{
	return "undef";
}

Value* Value::operator*(Value&)
{
	return this;
}

Value* Value::componentwiseMultiply(Value&)
{
	return this;
}

Value* Value::operator/(Value&)
{
	return this;
}

Value* Value::componentwiseDivide(Value&)
{
	return this;
}

Value* Value::operator%(Value&)
{
	return this;
}

Value* Value::operator+(Value&)
{
	return this;
}

Value* Value::operator-(Value&)
{
	return this;
}

Value* Value::operator&&(Value&)
{
	return this;
}

Value* Value::operator||(Value&)
{
	return this;
}

Value* Value::operation(Value* p_left, Expression::Operator_e e, Value* p_right)
{
	Value& left=*p_left;
	Value& right=*p_right;
	Value* result;
	switch(e) {
	case Expression::Multiply:
		result=left*right;
		break;
	case Expression::ComponentwiseMultiply:
		result=p_left->componentwiseMultiply(right);
		break;
	case Expression::Divide:
		result=left/right;
		break;
	case Expression::ComponentwiseDivide:
		result=p_left->componentwiseDivide(right);
		break;
	case Expression::Modulus:
		result=left%right;
		break;
	case Expression::Add:
		result=left+right;
		break;
	case Expression::Subtract:
		result=left-right;
		break;
	case Expression::LessThan:
		throw; //result=left<right;
		break;
	case Expression::LessOrEqual:
		throw; //result=left<=right;
		break;
	case Expression::Equal:
		throw; //result=left==right;
		break;
	case Expression::NotEqual:
		throw; //result=left!=right;
		break;
	case Expression::GreaterOrEqual:
		throw; //result=left>=right;
		break;
	case Expression::GreaterThan:
		throw; //result=left>right;
		break;
	case Expression::LogicalAnd:
		result=left&&right;
		break;
	case Expression::LogicalOr:
		result=left||right;
		break;
	default:
		result=&left;
	}
	result=result;
}
