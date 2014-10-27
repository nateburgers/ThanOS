#include "syntax_tree.h"

namespace ast
{
    /* Definition */
    Definition::Kind Definition::kind() const {
	return _kind;
    }
    /* Definition - Value */
    const std::string Value::name() const {
	return _name;
    }
    const Expression *Value::value() const {
	return _value;
    }
    /* Expression */
    Expression::Kind Expression::kind() const {
	return _kind;
    }
    /* Expression - Integer */
    int Integer::value() const {
	return _value;
    }
    /* Expression - Variable */
    const std::string Variable::value() const {
	return _value;
    }
    /* Expression - Let */
    const Expression *Let::name() const {
	return _name;
    }
    const Expression *Let::value() const {
	return _value;
    }
    const Expression *Let::continuation() const {
	return _continuation;
    }
    /* Expression - Application */
    const Expression *Application::expression() const {
	return _expression;
    }
    const Expression *Application::argument() const {
	return _argument;
    }
    /* Expression - Abstraction */
    const Expression *Abstraction::argument() const {
	return _argument;
    }
    const Expression *Abstraction::body() const {
	return _body;
    }
}










