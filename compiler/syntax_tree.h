#pragma once
#include <string>

namespace ast 
{
    /* Top Level */
    class Definition;
    class Expression;
    /* Definition Syntax */
    class Definition
    {
    public:
	enum Kind
	{
	    DefinitionKindValue
	};
    private:
	const Kind _kind;
    public:
    Definition(const Kind kind)
	: _kind(kind) {}
	Kind kind() const;
    };
    class Value: public Definition
    {
    private:
	const std::string _name;
	const Expression *_value;
    public:
    Value(const std::string name,
	  const Expression *value)
	: Definition(DefinitionKindValue), _name(name), _value(value) {}
	static bool classof (const Definition *definition) {
	    return definition->kind() == DefinitionKindValue;
	}
	const std::string name() const;
	const Expression *value() const;
    };
    
    /* Expression Syntax */
    class Expression
    {
    public:
	enum Kind 
	{
	    ExpressionKindInteger,
	    ExpressionKindVariable,
	    ExpressionKindLet,
	    ExpressionKindApplication,
	    ExpressionKindAbstraction
	};
    private:
	const Kind _kind;
    public:
    Expression(const Kind kind)
	: _kind(kind) {}
	Kind kind() const;
    };
    
    class Integer: public Expression
    {
    private:
	const int _value;
    public:
    Integer(const int value)
	: Expression(ExpressionKindInteger), _value(value) {}
	static bool classof (const Expression *expression)
	{
	    return expression->kind() == ExpressionKindInteger;
	}
	int value() const;
    };
    
    class Variable: public Expression
    {
    private:
	const std::string _value;
    public:
    Variable(const std::string value)
	: Expression(ExpressionKindVariable), _value(value) {}
	static bool classof (const Expression *expression)
	{
	    return expression->kind() == ExpressionKindVariable;
	}
	const std::string value() const;
    };
    
    class Let: public Expression
    {
    private:
	const Expression *_name;
	const Expression *_value;
	const Expression *_continuation;
    public:
    Let(const Expression *name,
	const Expression *value,
	const Expression *continuation)
	: Expression(ExpressionKindLet), _name(name), _value(value), _continuation(continuation) {}
	static bool classof(const Expression *expression) 
	{
	    return expression->kind() == ExpressionKindLet;
	}
	const Expression *name() const;
	const Expression *value() const;
	const Expression *continuation() const;
    };
    
    class Application: public Expression
    {
    private:
	const Expression *_expression;
	const Expression *_argument;
    public:
    Application(const Expression *expression,
		const Expression *argument)
	: Expression(ExpressionKindApplication), _expression(expression), _argument(argument) {}
	static bool classof(const Expression *expression) 
	{
	    return expression->kind() == ExpressionKindApplication;
	}
	const Expression *expression() const;
	const Expression *argument() const;
    };
    
    class Abstraction: public Expression
    {
    private:
	const Expression *_argument;
	const Expression *_body;
    public:
    Abstraction(const Expression *argument,
		const Expression *body)
	: Expression(ExpressionKindAbstraction), _argument(argument), _body(body) {}
	static bool classof(const Expression *expression) 
	{
	    return expression->kind() == ExpressionKindAbstraction;
	}
	const Expression *argument() const;
	const Expression *body() const;
    };
}
