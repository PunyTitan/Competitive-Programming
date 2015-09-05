#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string dayHaab, monthHaab, yearHaab;
	int temp, i;
	map<string, int> haabMonthMap;
	haabMonthMap["pop"] = 0;
	haabMonthMap["no"] = 1;
	haabMonthMap["zip"] = 2;
	haabMonthMap["zotz"] = 3;
	haabMonthMap["tzec"] = 4;
	haabMonthMap["xul"] = 5;
	haabMonthMap["yoxkin"] = 6;
	haabMonthMap["mol"] = 7;
	haabMonthMap["chen"] = 8;
	haabMonthMap["yax"] = 9;
	haabMonthMap["zac"] = 10;
	haabMonthMap["ceh"] = 11;
	haabMonthMap["mac"] = 12;
	haabMonthMap["kankin"] = 13;
	haabMonthMap["muan"] = 14;
	haabMonthMap["pax"] = 15;
	haabMonthMap["koyab"] = 16;
	haabMonthMap["cumhu"] = 17;
	haabMonthMap["uayet"] = 18;


	map<int, string> tzoMonthMap;
	tzoMonthMap[0] = "imix";
	tzoMonthMap[1] = "ik";
	tzoMonthMap[2] = "akbal";
	tzoMonthMap[3] = "kan";
	tzoMonthMap[4] = "chicchan";
	tzoMonthMap[5] = "cimi";
	tzoMonthMap[6] = "manik";
	tzoMonthMap[7] = "lamat";
	tzoMonthMap[8] = "muluk";
	tzoMonthMap[9] = "ok";
	tzoMonthMap[10] = "chuen";
	tzoMonthMap[11] = "eb";
	tzoMonthMap[12] = "ben";
	tzoMonthMap[13] = "ix";
	tzoMonthMap[14] = "mem";
	tzoMonthMap[15] = "cib";
	tzoMonthMap[16] = "caban";
	tzoMonthMap[17] = "eznab";
	tzoMonthMap[18] = "canac";
	tzoMonthMap[19] = "ahau";

	int totalDay;
	int dayTzo, monthTzo, yearTzo;

	cin >> n;
	cout << n<<endl;

	while (n-- != 0)
	{
		totalDay = 0;
		cin >> dayHaab >> monthHaab >> yearHaab;
		monthTzo = yearTzo = 0;
		dayTzo = 1;

		totalDay += atoi(yearHaab.c_str()) * 365 + haabMonthMap[monthHaab] * 20 + atoi(dayHaab.substr(0, dayHaab.length() - 1).c_str());

		for (i = 0; totalDay >= 0; ++i)
		{
			temp = totalDay;
			totalDay -= 260;
		}
		yearTzo = i - 1;
		totalDay = temp;

		if (totalDay != 0)
		{
			dayTzo = totalDay % 13 + 1;
			monthTzo = totalDay % 20;
		}

		cout << dayTzo << " " << tzoMonthMap[monthTzo] << " " << yearTzo << endl;

	}
	return 0;
}