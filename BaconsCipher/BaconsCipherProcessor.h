// ---------------------------------------------------------------------------

#ifndef BaconsCipherProcessorH
#define BaconsCipherProcessorH
#include <System.hpp>
#include <map>
using namespace std;
#include <System.Character.hpp>
#include <list>

#include <string>
#include <vector>
// ---------------------------------------------------------------------------

class BaconsCipher {
private: // ������������ ������� private

	String EncryptedMethod1(String);
	String EncryptedMethod2(String);
	String EncryptedMethod3(String);
	String EncryptedMethod4(String);

	String DecryptedMethod1(String);
	String DecryptedMethod2(String);
	String DecryptedMethod3(String);
	String DecryptedMethod4(String);

	map<String, String> *mp;
	map<String, String>mpEN_D;
	map<String, String>mpRU_D;
	map<String, String>mpEN_E;
	map<String, String>mpRU_E;

	std::map<std::string, vector<string>> newMpRu;

	void mp_toLower(map<String, String> *mp_in) {
		for (const auto&kv : (*mp_in)) {
			(*mp_in)[kv.first.LowerCase()] = kv.second;
		}
	}

	void EtoD(map<String, String> *mp_in, map<String, String> *mp_out) {
		for (const auto&kv : (*mp_in)) {
			(*mp_out)[kv.second] = kv.first;
		}
	};

public: // ������������ ������� public
	BaconsCipher() {
		// mpEN_E
		mpEN_E["A"] = "abbbb";
		mpEN_E["B"] = "babbb";
		mpEN_E["C"] = "bbabb";
		mpEN_E["D"] = "abbab";
		mpEN_E["E"] = "babba";
		mpEN_E["F"] = "ababb";
		mpEN_E["G"] = "aabab";
		mpEN_E["H"] = "baaba";
		mpEN_E["I"] = "bbaab";
		mpEN_E["J"] = "abbaa";
		mpEN_E["K"] = "aabba";
		mpEN_E["L"] = "aaabb";
		mpEN_E["M"] = "aaaab";
		mpEN_E["N"] = "aaaaa";
		mpEN_E["O"] = "baaaa";
		mpEN_E["P"] = "bbaaa";
		mpEN_E["Q"] = "bbbaa";
		mpEN_E["R"] = "abbba";
		mpEN_E["S"] = "aabbb";
		mpEN_E["T"] = "baabb";
		mpEN_E["U"] = "abaab";
		mpEN_E["V"] = "aabaa";
		mpEN_E["W"] = "aaaba";
		mpEN_E["X"] = "baaab";
		mpEN_E["Y"] = "abaaa";
		mpEN_E["Z"] = "babaa";
		// mpRU_E
		mpRU_E["�"] = "AAAAA";
		mpRU_E["�"] = "AAAAB";
		mpRU_E["�"] = "AAABA";
		mpRU_E["�"] = "AAABB";
		mpRU_E["�"] = "AABAA";
		mpRU_E["�"] = "AABAB";
		mpRU_E["�"] = "AABBA";
		mpRU_E["�"] = "AABBB";
		mpRU_E["�"] = "ABAAA";
		mpRU_E["�"] = "ABAAB";
		mpRU_E["�"] = "ABABA";
		mpRU_E["�"] = "ABABB";
		mpRU_E["�"] = "ABBAA";
		mpRU_E["�"] = "ABBAB";
		mpRU_E["�"] = "ABBBA";
		mpRU_E["�"] = "ABBBB";
		mpRU_E["�"] = "BAAAA";
		mpRU_E["�"] = "BAAAB";
		mpRU_E["�"] = "BAABA";
		mpRU_E["�"] = "BAABB";
		mpRU_E["�"] = "BABAA";
		mpRU_E["�"] = "BABAB";
		mpRU_E["�"] = "BABBA";
		mpRU_E["�"] = "BABBB";
		mpRU_E["�"] = "BBAAA";
		mpRU_E["�"] = "BBAAB";
		mpRU_E["�"] = "BBABA";
		mpRU_E["�"] = "BBABB";
		mpRU_E["�"] = "BBBAA";
		mpRU_E["�"] = "BBBAB";
		mpRU_E["�"] = "BBBBA";
		mpRU_E["�"] = "BBBBB";
		EtoD(&mpEN_E, &mpEN_D);
		EtoD(&mpRU_E, &mpRU_D);
		mp_toLower(&mpEN_E);
		mp_toLower(&mpRU_E);
		//������������� ������ ��� ���������
		newMpRu=langRU();
	}; // ����������� ������
	String Encrypted(String, int, int); //
	String Decrypted(String, int, int);

	string randomLetter() {
		std::string textArray[2] = {"a", "b"};
		int RandIndex = rand() % 2; // generates a random number between 0 and 3
		return textArray[RandIndex];
	}
		 //map[1,map[2,3,4,5]] �� ������� �� �����
	std::map<std::string, vector<string>>langRU() {
		map<string, vector<string> >lang;
		lang.insert(pair<string, vector<string> >("A",
		{"abbbb", "a", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("B",
		{"babbb", "a", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("C",
		{"bbabb", "a", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("D",
		{"abbab", "a", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("E",
		{"babba", "a", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("F",
		{"ababb", "a", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("G",
		{"aabab", "a", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("H",
		{"baaba", "a", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("I",
		{"bbaab", "a", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("J",
		{"abbaa", "a", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("K",
		{"aabba", "a", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("L",
		{"aaabb", "a", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("M",
		{"aaaab", "a", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("N",
		{"aaaaa", "b", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("O",
		{"baaaa", "b", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("P",
		{"bbaaa", "b", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("Q",
		{"bbbaa", "b", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("R",
		{"abbba", "b", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("S",
		{"aabbb", "b", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("T",
		{"baabb", "b", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("U",
		{"abaab", "b", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("V",
		{"aabaa", "b", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("W",
		{"aaaba", "b", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("X",
		{"baaab", "b", "a", randomLetter()}));
		lang.insert(pair<string, vector<string> >("Y",
		{"abaaa", "b", "b", randomLetter()}));
		lang.insert(pair<string, vector<string> >("Z",
		{"babaa", "b", "a", randomLetter()}));
		return lang;
	}

};

#endif
