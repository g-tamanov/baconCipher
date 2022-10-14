// ---------------------------------------------------------------------------

#pragma hdrstop

#include "BaconsCipherProcessor.h"
#include <System.hpp>
#include <stdio.h>
#include <string.h>
#include <ustring.h>
#include <map>
#include <Vcl.Forms.hpp>
#include <System.Character.hpp>
#include <map>
#include <iostream>

#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair

#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
// ---------------------------------------------------------------------------

// https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/

// // Make three vectors, each of length 100 filled with 1s, 2s, and 3s
// std::vector<int> vec1(100, 1);
// std::vector<int> vec2(100, 2);
// std::vector<int> vec3(100, 3);
//
// // Wrap into a vector
// std::vector<std::pair<std::string, std::vector<int>>> vals = {{"One", vec1}, {"Two", vec2}, {"Three", vec3}};
//
// // Write the vector to CSV
// write_csv("three_cols.csv", vals);

void write_csv(std::string filename, std::vector < std::pair < std::string,
	std::vector < string >>> dataset) {
	// Make a CSV file with one or more columns of integer values
	// Each column of data is represented by the pair <column name, column data>
	// as std::pair<std::string, std::vector<int>>
	// The dataset is represented as a vector of these columns
	// Note that all columns should be the same size

	// Create an output filestream object
	std::ofstream myFile(filename);

	// Send column names to the stream
	for (int j = 0; j < dataset.size(); ++j) {
		myFile << dataset.at(j).first;
		if (j != dataset.size() - 1)
			myFile << ","; // No comma at end of line
	}
	myFile << "\n";

	// Send data to the stream
	for (int i = 0; i < dataset.at(0).second.size(); ++i) {
		for (int j = 0; j < dataset.size(); ++j) {
			myFile << dataset.at(j).second.at(i);
			if (j != dataset.size() - 1)
				myFile << ","; // No comma at end of line
		}
		myFile << "\n";
	}

	// Close the file
	myFile.close();
}

//сохранить набор(таблица рис 1.6 из книги) в csv
void save(std::map<std::string, std::vector<std::string> > lang) {
//	vector<string>letter;
//	vector<string>letters;
//	vector<string>k1;
//	vector<string>k2;
//	vector<string>k3;
//
//	for (auto item: lang) {
//		letter.push_back(item.first);
//		letters.push_back(item.second[0]);
//		k1.push_back(item.second[1]);
//		k2.push_back(item.second[2]);
//		k3.push_back(item.second[3]);
//	}
//	std::vector < std::pair < std::string, std::vector < string >>> vals = {
//		{"letter", letter}, {"letters", letters}, {"k1", k1}, {"k2", k2},
//		{"k3", k3}};
//	write_csv("lang.csv", vals);
}

// // Read three_cols.csv and ones.csv
// std::vector<std::pair<std::string, std::vector<int>>> three_cols = read_csv("three_cols.csv");
// std::vector<std::pair<std::string, std::vector<int>>> ones = read_csv("ones.csv");
//
// // Write to another file to check that this was successful
// write_csv("three_cols_copy.csv", three_cols);
// write_csv("ones_copy.csv", ones);

std::vector < std::pair < std::string, std::vector <
	int >>> read_csv(std::string filename) {
	// Reads a CSV file into a vector of <string, vector<int>> pairs where
	// each pair represents <column name, column values>

	// Create a vector of <string, int vector> pairs to store the result
	std::vector < std::pair < std::string, std::vector < int >>> result;

	// Create an input filestream
	std::ifstream myFile(filename);

	// Make sure the file is open
	if (!myFile.is_open())
		throw std::runtime_error("Could not open file");

	// Helper vars
	std::string line, colname;
	int val;

	// Read the column names
	if (myFile.good()) {
		// Extract the first line in the file
		std::getline(myFile, line);

		// Create a stringstream from line
		std::stringstream ss(line);

		// Extract each column name
		while (std::getline(ss, colname, ',')) {

			// Initialize and add <colname, int vector> pairs to result
			result.push_back({colname, std::vector<int> {}});
		}
	}

	// Read data, line by line
	while (std::getline(myFile, line)) {
		// Create a stringstream of the current line
		std::stringstream ss(line);

		// Keep track of the current column index
		int colIdx = 0;

		// Extract each integer
		while (ss >> val) {

			// Add the current integer to the 'colIdx' column's values vector
			result.at(colIdx).second.push_back(val);

			// If the next token is a comma, ignore it and move on
			if (ss.peek() == ',')
				ss.ignore();

			// Increment the column index
			colIdx++;
		}
	}

	// Close file
	myFile.close();

	return result;
}

String BaconsCipher::Decrypted(String str, int num, int ln) {
	if (ln == 0)
		mp = &mpRU_D;
	else
		mp = &mpEN_D;

	switch (num) {
	case 0:
		str = DecryptedMethod1(str);
		break;
	case 1:
		str = DecryptedMethod2(str);
		break;
	case 2:
		str = DecryptedMethod3(str);
		break;
	case 3:
		str = DecryptedMethod4(str);
		break;
	}
	return str;
};

String BaconsCipher::DecryptedMethod1(String str) {
	String tmp = "";
	String final = "";
	int i = 0;
	try {
		for (auto&c : str) {
			if (c == ' ')
				continue;
			tmp += c;
			i++;
			if (i > 4) {
				final += mp->at(tmp);
				tmp = "";
				i = 0;
			}
		}
	}
	catch (const std::exception& e) {
		// cerr << e.what();
		Application->MessageBox
			(L"Допустимы только буквы кириллицы или латиницы.",
		L"Ошибка", MB_OK);
		// std::cout << tmp;
		final = "";
	}

	return final;
};

String BaconsCipher::DecryptedMethod2(String str) {
	return "DecryptedMethod2";
};

String BaconsCipher::DecryptedMethod3(String str) {
	return "DecryptedMethod3";
};

String BaconsCipher::DecryptedMethod4(String str) {
	return "DecryptedMethod4";
};

String BaconsCipher::Encrypted(String str, int num, int ln) {
	if (ln == 0)
		mp = &mpRU_E;
	else
		mp = &mpEN_E;

	switch (num) {
	case 0:
		str = EncryptedMethod1(str);
		break;
	case 1:
		str = EncryptedMethod2(str);
		break;
	case 2:
		str = EncryptedMethod3(str);
		break;
	case 3:
		str = EncryptedMethod4(str);
		break;
	}
    save(newMpRu);
	return str;
};

String BaconsCipher::EncryptedMethod1(String str) {
	String tmp;
	try {
		for (auto&c : str) {
			if (c == ' ')
				continue;
			tmp += mp->at(c);
			// tmp += mp->at(ToUpper(c));
		}
	}
	catch (const std::exception& e) {
		// cerr << e.what();
		Application->MessageBox
			(L"Допустимы только буквы кириллицы или латиницы.",
		L"Ошибка", MB_OK);
		tmp = "";
	}

	return tmp;
};

String BaconsCipher::EncryptedMethod2(String str) {
	return "EncryptedMethod2";
};

String BaconsCipher::EncryptedMethod3(String str) {
	return "EncryptedMethod3";
};

String BaconsCipher::EncryptedMethod4(String str) {
	return "EncryptedMethod4";
};

#pragma package(smart_init)
