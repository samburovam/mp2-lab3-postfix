#include "postfix.h"
#include <gtest.h>
#include "postfix.cpp"

TEST(TPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix p("0"));
}

TEST(TPostfix, can_not_start_infix_the_operation)
{
	TPostfix p("+a+1");
	EXPECT_EQ(false, p.IsCorrect());
}
TEST(TPostfix, can_not_finish_infix_the_operation)
{
	TPostfix p("a+1+");
	EXPECT_EQ(false, p.IsCorrect());
}
TEST(TPostfix, infix_has_not_two_operation_in_a_row)
{
	TPostfix p("a+*1");
	EXPECT_EQ(false, p.IsCorrect());
}
TEST(TPostfix, parentheses_is_not_correct)
{
	TPostfix p("(a+1))");
	EXPECT_EQ(false, p.IsCorrect());
}
TEST(TPostfix, parentheses_is_correct)
{
	TPostfix p("(a+1)*(b+1)");
	EXPECT_EQ(true, p.IsCorrect());
}

TEST(TPostfix, transformation_infix_in_postfix_is_true_only_numbers)
{
	TPostfix p("(5+1)*(7+1)");
	p.ToPostfix();
	EXPECT_EQ("5 1 + 7 1 + *", p.GetPostfix());
}
TEST(TPostfix, transformation_infix_in_postfix_is_true_only_variables)
{
	TPostfix p("(a+b*c)-(k*d-p)");
	p.ToPostfix();
	EXPECT_EQ("a b c * + k d * p - -", p.GetPostfix());
}
TEST(TPostfix, transformation_infix_in_postfix_is_true_variables_and_numbers_mixed)
{
	TPostfix p("(5+4*v)/5.0");
	p.ToPostfix();
	EXPECT_EQ("5 4 v * + 5.0 /", p.GetPostfix());
}
TEST(TPostfix, can_use_only_long_variables)
{
	TPostfix p("(alpha+1)*(betta+1)");
	p.ToPostfix();
	EXPECT_EQ("alpha 1 + betta 1 + *", p.GetPostfix());
}
TEST(TPostfix, can_use_variables_short_and_long)
{
	TPostfix p("(num*c+5.0)/denominator");
	p.ToPostfix();
	EXPECT_EQ("num c * 5.0 + denominator /", p.GetPostfix());
}
TEST(TPostfix, can_calculate_expression)
{
	TPostfix p("(5+1)*(10+1)");
	p.ToPostfix();
	EXPECT_EQ(66, p.Calculate());
}