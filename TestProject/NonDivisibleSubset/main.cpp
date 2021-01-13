#include "../headers/stdc++.h"

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

void constructCombinaison(int offset, int cmbSize, vector<int> currentComb, vector<vector<int>>& combs,
                          const int masterListSize) {
	if (cmbSize == 0) {
		combs.push_back(currentComb);
	}
	else {
		for (int idx = offset; idx <= masterListSize - cmbSize; ++idx) {
			currentComb.push_back(idx);
			constructCombinaison(offset + 1, cmbSize - 1, currentComb, combs, masterListSize);
			currentComb.pop_back();
		}
	}

}

int nonDivisibleSubset(int k, vector<int> s) {
	// Facon de subdiviser le vect pour eliminer des combinaisons?

	for (int i = s.size() - 1; i > 0; --i) {
		vector<vector<int>> combinaisons;
		vector<int> combinaison;

		// On pourrais coupler les methodes pour eval directement les comb et eviter de construire des subsets
		constructCombinaison(0, i, combinaison, combinaisons, s.size());


		for (auto comb : combinaisons) {
			int64_t total = 0;

			for (auto idx : comb) {
				total += s[idx];
			}

			bool nonDivisible = total % k > 0;
			if (nonDivisible) {
				for (auto idx : comb) {
					cout << "idx, number : " << idx << ", " << s[idx] << endl;
				}
				return i;
			}
		}

	}


	return 0;
}


int main() {
	int n = 4;
	int k = 7;

	vector<int> s;
	//             
	s.push_back(278);
	s.push_back(576);
	s.push_back(496);
	s.push_back(727);
	s.push_back(410);
	s.push_back(124);
	s.push_back(338);
	s.push_back(149);
	s.push_back(209);
	s.push_back(702);
	s.push_back(282);
	s.push_back(718);
	s.push_back(771);
	s.push_back(575);
	s.push_back(436);

	int result = nonDivisibleSubset(k, s);
	int expected = 11;

	cout << "result : " << result << "\n";
	cout << "expected : " << expected << "\n";
	cout << "equals : " << (result == expected) << "\n";

	return 0;
}

string ltrim(const string& str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string& str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
