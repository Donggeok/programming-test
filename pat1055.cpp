
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	char *name;
	int age;
	int net_worth;

	bool operator<(const Info other) {
		if (net_worth == other.net_worth && age == other.age) {
			for (int i = 0; i < 9; ++i) {
				if (name[i] < other.name[i]) {
					return true;
				}
				else if (name[i] > other.name[i]) {
					return false;
				}
			}
			return false;
		}
		else if (net_worth == other.net_worth) {
			return age < other.age;
		}
		else {
			return net_worth > other.net_worth;
		}
	}

};

int main() {
	
	int N, M;
	scanf("%d%d", &N, &M);
	vector<Info> infos;
	for (int i = 0; i < N; ++i) {
		Info tmp;
		char *name = new char[10];
		scanf("%s%d%d", name, &tmp.age, &tmp.net_worth);
		tmp.name = name;
		infos.push_back(tmp);
	}
	sort(infos.begin(), infos.end());

	vector<int> queries;

	for (int i = 0; i < M; ++i) {
		int num, age_l, age_r;
		scanf("%d%d%d", &num, &age_l, &age_r);
		queries.push_back(num);
		queries.push_back(age_l);
		queries.push_back(age_r);

	}
	for (int i = 0; i < M; ++i) {
		int num, age_l, age_r;
		num = queries[i * 3];
		age_l = queries[i * 3 + 1];
		age_r = queries[i * 3 + 2];
		printf("Case #%d:\n", i + 1);
		int raw_num = num;
		for (int j = 0; j < infos.size(); ++j) {
			if (infos[j].age >= age_l && infos[j].age <= age_r) {
				--num;
				printf("%s %d %d\n", infos[j].name, infos[j].age, infos[j].net_worth);
				if (!num) {
					break;
				}
			}
		}
		if (raw_num == num) {
			printf("None\n");
		}
	}

	return 0;
}

