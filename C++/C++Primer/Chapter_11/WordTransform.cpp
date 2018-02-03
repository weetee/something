#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int GenerateRules(ifstream &rule_file, map<string, string> &rule_map);
int TransformFile(ifstream &trans_file, map<string, string> &rule_map);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Need two files,first is rule file; second is need transform file" << endl;
        return -1;
    }

    // 将规则文件中的内容存入map
    ifstream rule_file(argv[1]);
    map<string, string> rule_map;
    int ret = GenerateRules(rule_file, rule_map);
    if (ret == -1)
    {
    	cout << "GenerateRules failed!" << endl;
    	return -1;
    }

    // 开始转换
    ifstream trans_file(argv[2]);
    ret = TransformFile(trans_file, rule_map);
    if (ret == -1)
    {
    	cout << "TransformFile failed!" << endl;
    	return -1;
    }

    return 0;
}

int GenerateRules(ifstream &rule_file, map<string, string> &rule_map)
{
	string line;
	while (getline(rule_file, line))
	{
		istringstream istr(line);
		string key_str;
		string val_str;
		string word;
		istr >> key_str;
		while (istr >> word)
			val_str += word;
		rule_map[key_str] = val_str;
	}
	return 0;
}

int TransformFile(ifstream &trans_file, map<string, string> &rule_map)
{
	string result_str;
	string word;
	while (trans_file >> word)
	{
		if (rule_map.find(word) != rule_map.end())
			result_str += rule_map[word];
		else
			result_str += word;
		result_str += " ";
	}

	cout << "the result is: " << result_str << endl;
	return 0;
}
