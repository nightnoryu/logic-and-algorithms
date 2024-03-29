/*
 * ����� �������:
 * 14.13. ������ 2 (6)
 * ������������������ ()(()) �������� ���������� ��������� �������������������,
 * ������ ��� ��� �����, ��������, ����������� � ��������� (2+2):(3-(5-2)+4),
 * � ������������������ (() � ())( �� �������� ��������. ����� ���������� ����������
 * ��������� �������� ���������� ���� ������ � �������� ���������� ���������
 * ������������������ ���, ����� ����� ���������� ���������� ��������� ������������������.
 * ������� ��������� ������������������ ����������� �� �������� ����������� ������ �
 * ���������� ������������������. ��������, ���� ��� ���������� ������ � ����������
 * ������������������ () ����� �������� ������ ���������� ��������� ������������������
 * ����� ���������: ()(), (()), (()), (()), (()), ()(), ()(). ����� �������, ���� �
 * ���������� ������������������ ����������� ����������� ������ ����� � ������� i,
 * � ����������� ����������� - � ������� j, �� ��� �������, ��������������� �����
 * (i1, j1) � (i2, j2), ��������� ����������, ���� i1 != i2 ��� j1 != j2. ��������� ��������
 * ���������, ������� �� �������� ���������� ��������� ������������������ ���������� ����������
 * ��������� ��������� ���� �������� ���������� ���� ������.
 *
 * ����. ������� ���� ������� �� ����� �������� ������, ���������� ����� 2N ��������: N
 * ����������� � N ����������� ������� ������ (1 <= N <= 10^5). �������������, ��� ���
 * ������ �������� ���������� ��������� �������������������.
 *
 * �����. � ������������ ������ �������� ���������� ��������� �������� ���������� � ��������
 * ������������������ ���� ������ ����� �������, ����� ���������� ������ ���������� ��������� ������������������.
 *
 * �������
 *
 * ���� 1    ���� 2    ���� 3
 * ()        ()()      (())
 *
 * ����� 1   ����� 2   ����� 3
 * 7         17        21
 *
 *
 * ��������:
 * ������� �����, ��-21
 *
 * ����� ����������:
 * Visual Studio 2022
 */

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;

ll FindSolutions(const std::string& str)
{
	ll result = (str.length() + 1) * (str.length() + 2) / 2; // ������ ��� ������� ()

	ll currentDepth = 0;
	ll positionsBetweenZeroDepths = 0;
	for (auto const& ch : str)
	{
		if (ch == '(')
		{
			++currentDepth;
		}
		else if (ch == ')')
		{
			--currentDepth;
		}

		if (currentDepth == 0)
		{
			result += positionsBetweenZeroDepths * (positionsBetweenZeroDepths + 1) / 2; // ������ ��� ������� )(
			positionsBetweenZeroDepths = 0;
		}
		else
		{
			++positionsBetweenZeroDepths;
		}
	}

	return result;
}

void Solve(std::istream& input, std::ostream& output)
{
	std::string brackets;
	std::getline(input, brackets);

	output << FindSolutions(brackets) << '\n';
}

int main()
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

	input.tie(nullptr);
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	Solve(input, output);
}
