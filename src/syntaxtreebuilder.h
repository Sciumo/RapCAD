#ifndef SYNTAXTREEBUILDER_H
#define SYNTAXTREEBUILDER_H

#include <QVector>
#include "module.h"
#include "parameter.h"
#include "expression.h"
#include "binaryexpression.h"

class SyntaxTreeBuilder
{
public:
    SyntaxTreeBuilder();
    void BuildModule(QString name,QVector<Parameter*>*);
    QVector<Parameter*>* BuildParameters();
    QVector<Parameter*>* BuildParameters(Parameter*);
    QVector<Parameter*>* BuildParameters(QVector<Parameter*>*,Parameter*);
    Parameter* BuildParameter(QString);
    Parameter* BuildParameter(QString,Expression*);
    Expression* BuildExpression(bool);
    Expression* BuildExpression(double value);
    Expression* BuildExpression(Expression*,Expression*);
private:
    Module * current_module;
    QVector<Module*>  module_stack;
};

#endif // SYNTAXTREEBUILDER_H
