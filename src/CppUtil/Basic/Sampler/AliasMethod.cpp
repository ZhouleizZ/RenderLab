#include <CppUtil/Basic/AliasMethod.h>

#include <CppUtil/Basic/Math.h>

using namespace CppUtil::Basic;
using namespace std;

void AliasMethod::Init(const vector<double> & distribution) {
	table.clear();
	const auto num = static_cast<int>(distribution.size());
	table.resize(num);

	vector<int> overfulls;
	vector<int> underfulls;
	overfulls.reserve(num);
	underfulls.reserve(num);

	for (int i = 0; i < num; i++) {
		table[i].p = distribution[i];
		table[i].u = num * distribution[i];
		if (table[i].u < 1)
			underfulls.push_back(i);
		else if (table[i].u > 1)
			overfulls.push_back(i);
		else
			table[i].k = static_cast<int>(i);
	}

	while (!overfulls.empty() && !underfulls.empty()) {
		int i = overfulls.back();
		overfulls.pop_back();
		
		int j = underfulls.back();
		underfulls.pop_back();

		table[i].u -= 1 - table[j].u;
		table[j].k = i;

		if (table[i].u > 1)
			underfulls.push_back(i);
	}
	
	for (auto i : overfulls) {
		table[i].u = 1.f;
		table[i].k = i;
	}

	for (auto j : underfulls) {
		table[j].u = 1.f;
		table[j].k = j;
	}
}

int AliasMethod::Sample() const {
	double x = Math::Rand_F();
	auto n = static_cast<int>(table.size());
	auto nx = n * x;

	// 0, 1, ..., n - 1
	auto i = static_cast<int>(nx);

	// [0, 1)
	auto y = nx - i;

	if (y < table[i].u)
		return i;
	else
		return table[i].k;
}

int AliasMethod::Sample(double & p) const {
	int i = Sample();
	p = P(i);
	return i;
}

double AliasMethod::P(int i) const {
	assert(i >= 0 && i < static_cast<int>(table.size()));
	return table[i].p;
}