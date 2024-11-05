#include "pch.h"
#include "CppUnitTest.h"
#include "../laboratory7.1rec/laboratory7.1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71rec
{
	TEST_CLASS(UnitTest71rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 5;
			int colCount = 5;
			int low = -10;
			int high = 10;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			Create(a, rowCount, colCount, low, high, 0, 0);

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::IsTrue(a[i][j] >= low && a[i][j] <= high);
				}
			}
			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
		TEST_METHOD(TestMethod2)
		{
			int rowCount = 3;
			int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			a[0][0] = 10; a[0][1] = 5; a[0][2] = 20;
			a[1][0] = 1;  a[1][1] = 30; a[1][2] = 2;
			a[2][0] = 7;  a[2][1] = 4;  a[2][2] = 15;

			Sort(a, rowCount, colCount, 0, 0);

			Assert::IsTrue(a[0][0] <= a[1][0] && a[1][0] <= a[2][0], L"Рядки не відсортовані за першою колонкою.");

			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
