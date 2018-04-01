#ifndef CSANKE_EXPRESSION_H
namespace game_pattern {
	class Expression
	{
	public:
		Expression();
		~Expression();

		virtual ~Expression() {}
		virtual double evaluate() = 0;

	private:

	};

	class NumberExpression :public Expression {
	public:
		NumberExpression(double value)
		:value_(value){

		}

		virtual double evaluate() {
			return value_;
		}

	private:
		double value_;
	};

	class AdditionExpression :public Expression {
	public:
		AdditionExpression(Expression* left,Expression*right)
			:left_(left),
			right_(right)
		{}

		virtual double evaluate() {
			double left = left_->evaluate();
			double right = right_->evaluate();
			return left + right;
		}

	private:
		Expression* left_;
		Expression* right_;
	};
}



namespace game_pattern {
Expression::Expression()
{
}

Expression::~Expression()
{
}
}
#endif // !CSANKE_EXPRESSION_H
