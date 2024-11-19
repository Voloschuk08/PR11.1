#include "pch.h"
#include "CppUnitTest.h"
#include "../PR11.1/PR11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:
		
        TEST_METHOD(TestReplaceNo)
        {
            string testStr1 = "no one knows";
            string result1 = ReplaceNo(testStr1);
            Assert::AreEqual(string("*** one k***ws"), result1); // Очікується заміна "no" на "***"

            string testStr2 = "on the notion";
            string result2 = ReplaceNo(testStr2);
            Assert::AreEqual(string("on the ***tion"), result2); // Замінено лише "no", "on" залишилося

            string testStr3 = "hello world";
            string result3 = ReplaceNo(testStr3);
            Assert::AreEqual(string("hello world"), result3); // Без змін, оскільки немає "no"
		}
	};
}
