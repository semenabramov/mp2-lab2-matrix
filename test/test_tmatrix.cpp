#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> t(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> t(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> t(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> t(5);

	ASSERT_NO_THROW(TMatrix<int> t1(t));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> t(5);

	for (int i = 0; i < t.GetSize(); i++)
	{
		for (int j = i; j < t.GetSize(); j++)
		{
			t[i][j] = i * j;
		}
	}

	TMatrix<int> tp(t);

	EXPECT_EQ(t, tp);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> t(5);
	TMatrix<int> tp(t);
	EXPECT_NE(&(t[0][0]), &(tp[0][0]));
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> t(5);
	EXPECT_EQ(5, t.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> t(5);
	t[0][0] = 9;
	EXPECT_EQ(9, t[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> t(5);

	ASSERT_ANY_THROW(t[-1][-1] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> t(5);

	ASSERT_ANY_THROW(t[5][5] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> t(5);
	ASSERT_NO_THROW(t = t);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> t(5), tp(5);

	for (int i = 0; i < t.GetSize(); i++)
	{
		for (int j = i; j < t.GetSize(); j++)
		{
			t[i][j] = i + j;
		}
	}

	tp = t;
	EXPECT_EQ(t, tp);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> t(7), tp(5);
	t = tp;
	EXPECT_EQ(5, t.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> t(7), tp(5);

	for (int i = 0; i < t.GetSize(); i++)
	{
		for (int j = i; j < t.GetSize(); j++)
		{
			t[i][j] = i + j;
		}
	}

	tp = t;
	EXPECT_EQ(t, tp);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> t(5), tp(5);
	for (int i = 0; i < t.GetSize(); i++)
	{
		for (int j = i; j < t.GetSize(); j++)
		{
			t[i][j] = i + j;
			tp[i][j] = i + j;
		}
	}

	EXPECT_EQ(true, t == tp);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> t(5);
	for (int i = 0; i < t.GetSize(); i++)
	{
		for (int j = i; j < t.GetSize(); j++)
		{
			t[i][j] = i + j;
		}
	}

	EXPECT_EQ(true, t == t);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> t(5), tp(7);
	EXPECT_NE(false, t != tp);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> t(5), tp(5), tpm(5);
	for (int i = 0; i < t.GetSize(); i++)
	{
		for (int j = i; j < t.GetSize(); j++)
		{
			t[i][j] = i;
			tp[i][j] = t.GetSize() - i;
			tpm[i][j] = t.GetSize();
		}
	}
	EXPECT_EQ(tpm, t + tp);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> t(5), tp(7);
	ASSERT_ANY_THROW(t + tp);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> t(5), tp(5), tpm(5);
	for (int i = 0; i < t.GetSize(); i++)
	{
		for (int j = i; j < t.GetSize(); j++)
		{
			t[i][j] = i;
			tp[i][j] = i;
		}
	}
	EXPECT_EQ(tpm, t - tp);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> t(5), tp(7);
	ASSERT_ANY_THROW(t - tp);
}