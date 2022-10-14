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
private: // спецификатор доступа private

	String EncryptedMethod1(String);
	String EncryptedMethod2(String);
	String EncryptedMethod3(String);
	String EncryptedMethod4(String);

	String DecryptedMethod1(String);
	String DecryptedMethod2(String);
	String DecryptedMethod3(String);
	String DecryptedMethod4(String);

	void save(std::map<std::string, std::vector<std::string> >);

	map<String, String> *mp;
	map<String, String>mpEN_D;
	map<String, String>mpRU_D;
	map<String, String>mpEN_E;
	map<String, String>mpRU_E;

	map < string, vector < string >> newMpEn;

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

public: // спецификатор доступа public
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
		mpRU_E["А"] = "AAAAA";
		mpRU_E["Б"] = "AAAAB";
		mpRU_E["В"] = "AAABA";
		mpRU_E["Г"] = "AAABB";
		mpRU_E["Д"] = "AABAA";
		mpRU_E["Е"] = "AABAB";
		mpRU_E["Ж"] = "AABBA";
		mpRU_E["З"] = "AABBB";
		mpRU_E["И"] = "ABAAA";
		mpRU_E["Й"] = "ABAAB";
		mpRU_E["К"] = "ABABA";
		mpRU_E["Л"] = "ABABB";
		mpRU_E["М"] = "ABBAA";
		mpRU_E["Н"] = "ABBAB";
		mpRU_E["О"] = "ABBBA";
		mpRU_E["П"] = "ABBBB";
		mpRU_E["Р"] = "BAAAA";
		mpRU_E["С"] = "BAAAB";
		mpRU_E["Т"] = "BAABA";
		mpRU_E["У"] = "BAABB";
		mpRU_E["Ф"] = "BABAA";
		mpRU_E["Х"] = "BABAB";
		mpRU_E["Ц"] = "BABBA";
		mpRU_E["Ч"] = "BABBB";
		mpRU_E["Ш"] = "BBAAA";
		mpRU_E["Щ"] = "BBAAB";
		mpRU_E["Ъ"] = "BBABA";
		mpRU_E["Ы"] = "BBABB";
		mpRU_E["Ь"] = "BBBAA";
		mpRU_E["Э"] = "BBBAB";
		mpRU_E["Ю"] = "BBBBA";
		mpRU_E["Я"] = "BBBBB";
		EtoD(&mpEN_E, &mpEN_D);
		EtoD(&mpRU_E, &mpRU_D);
		mp_toLower(&mpEN_E);
		mp_toLower(&mpRU_E);
		// инициализация набора для кириллицы
		newMpEn = langEN();
		// newMpEn["A"].push_back("abbbb");
		// newMpEn["A"] = {"abbbb", "a", "b", randomLetter()};
		// newMpEn["B"] = {"babbb", "a", "a", randomLetter()};

	}; // конструктор класса
	String Encrypted(String, int, int); //
	String Decrypted(String, int, int);

	string randomLetter() {
		std::string textArray[2] = {"a", "b"};
		int RandIndex = rand() % 2; // generates a random number between 0 and 3
		return textArray[RandIndex];
	}
	// map[1,map[2,3,4,5]] по таблице из книги
	std::map < std::string, vector < string >> langEN() {
		map<string, vector<string> >lang;
		lang["A"] = {"abbbb", "a", "b", randomLetter()};
		lang["B"] = {"babbb", "a", "a", randomLetter()};
		lang["C"] = {"bbabb", "a", "b", randomLetter()};
		lang["D"] = {"abbab", "a", "a", randomLetter()};
		lang["E"] = {"babba", "a", "b", randomLetter()};
		lang["F"] = {"ababb", "a", "a", randomLetter()};
		lang["G"] = {"aabab", "a", "b", randomLetter()};
		lang["H"] = {"baaba", "a", "a", randomLetter()};
		lang["I"] = {"bbaab", "a", "b", randomLetter()};
		lang["J"] = {"abbaa", "a", "a", randomLetter()};
		lang["K"] = {"aabba", "a", "b", randomLetter()};
		lang["L"] = {"aaabb", "a", "a", randomLetter()};
		lang["M"] = {"aaaab", "a", "b", randomLetter()};
		lang["N"] = {"aaaaa", "b", "a", randomLetter()};
		lang["O"] = {"baaaa", "b", "b", randomLetter()};
		lang["P"] = {"bbaaa", "b", "a", randomLetter()};
		lang["Q"] = {"bbbaa", "b", "b", randomLetter()};
		lang["R"] = {"abbba", "b", "a", randomLetter()};
		lang["S"] = {"aabbb", "b", "b", randomLetter()};
		lang["T"] = {"baabb", "b", "a", randomLetter()};
		lang["U"] = {"abaab", "b", "b", randomLetter()};
		lang["V"] = {"aabaa", "b", "a", randomLetter()};
		lang["W"] = {"aaaba", "b", "b", randomLetter()};
		lang["X"] = {"baaab", "b", "a", randomLetter()};
		lang["Y"] = {"abaaa", "b", "b", randomLetter()};
		lang["Z"] = {"babaa", "b", "a", randomLetter()};
		return lang;
	}

};

#endif
