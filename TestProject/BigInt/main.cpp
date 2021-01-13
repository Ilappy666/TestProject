#include "../headers/stdc++.h"

using namespace std;

class BigInt {
private:
	vector<uint64_t> number;
	bool positive = 1;
	const uint64_t baseNumber = 1000000000; // 1,000,000,000
	const int digitNumber = 9;
public:
	BigInt();
	BigInt(int);
	string str();
	BigInt operator*(BigInt&) const;
	BigInt operator=(BigInt&);
};

/**
 * \brief 
 */
BigInt::BigInt() {}

BigInt::BigInt(int _nb) {
	int nb = _nb;
	if (nb / baseNumber < 1) {
		if (number.empty()) {
			number.push_back(_nb);
		}
	}
	else {
		int testNb = nb;
		while (testNb >= 1) {
			number.push_back(testNb % baseNumber);
			testNb /= baseNumber;
		}
	}
}

BigInt BigInt::operator*(BigInt& bi) const {

	BigInt res;

	for (size_t i = 0; i < bi.number.size(); ++i) {
		for (size_t j = 0; j < number.size(); ++j) {
			uint64_t multResult = bi.number[i] * number[j];

			size_t innerSkip = i + j;

			do {
				if (res.number.size() < innerSkip + 1) {
					res.number.resize(innerSkip + 1, 0);
				}

				res.number[innerSkip] += multResult % baseNumber;

				if (res.number[innerSkip] >= baseNumber) {
					res.number[innerSkip] -= baseNumber;
					multResult += baseNumber;
				}

				innerSkip++;
				multResult /= baseNumber;
			}
			while (multResult >= 1);
		}
	}

	return res;
}

BigInt BigInt::operator=(BigInt& bi) {
	number.clear();
	positive = bi.positive;
	for (auto& it : bi.number) {
		number.push_back(it);
	}

	return *this;
}

string BigInt::str() {
	ostringstream nbrStream;

	reverse(number.begin(), number.end());
	for (auto it = number.begin(); it != number.end(); ++it) {
		if(it != number.begin()) {
			nbrStream << setfill('0') << setw(digitNumber);
		}
		nbrStream << *it;
	}

	return nbrStream.str();
}

BigInt recFact(int _n) {
	BigInt res(_n);
	if (_n <= 1) {
		return res;
	}
	return recFact(_n - 1) * res;
}

void extraLongFactorials(const int n, const string expected) {

	BigInt res = recFact(n);
	const string result = res.str();
	
	cout << "res : " << result << endl;
	cout << "exp : " << expected << endl;
	cout << "equals : " << expected.compare(result) << endl << endl;
	
}

int main()
{

/*
	extraLongFactorials(5, "120");
	extraLongFactorials(10, "3628800");
	extraLongFactorials(11, "39916800");
	extraLongFactorials(12, "479001600");
	extraLongFactorials(15, "1307674368000");
	extraLongFactorials(20, "2432902008176640000");*/
	extraLongFactorials(25, "15511210043330985984000000");
	//extraLongFactorials(100, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");

	return 0;
}
