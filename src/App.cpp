/*
-	binary.cpp
-   Developed by (https://github.com/MayankDevil/)
-	programmer : Mayank
*/

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

class BinaryApp {

	protected:

		int choice;

		std::fstream file;

		std::string file_location, file_data, line;

	public:

		BinaryApp(std::string active_command) {

			if (active_command != "gupt") {

				std::cout << "\n{ Access : DENIED }-----\n" << std::endl;

				return;
			}

			std::cout << "\n{ Access: GRANTED }-----\n" << std::endl;

			execute();
		}

		// execute get or set file data

		void execute() {

			scanFileData();

			convertBinaryData();

			convertOrignalData();
		}

	private:


		// convert orignal data

		void convertOrignalData() {

			setFileLocation();

			file.open(getFileLocation(), std::ios::trunc | std::ios::out);

			if (file.is_open()) {

				file << data(file_data);
			}

			file.close();

			std::cout << "[success]: orignal data file (" << getFileLocation() << ") is created" << std::endl;
		}

		// convert binary data

		void convertBinaryData() {

			setFileLocation();

			file.open(getFileLocation(), std::ios::out | std::ios::binary);

			if (file.is_open()) {

				file << bit(file_data);
			}

			file.close();

			std::cout << "[success]: binary file (" << getFileLocation() << ") is created" << std::endl;
		}

		// scan file data

		void scanFileData() {

			setFileLocation();

			file.open(getFileLocation(), std::ios::in | std::ios::binary);

			if (file.is_open()) {

				while (getline(file, line)) {

					file_data += line;
				}
			}

			file.close();

			std::cout << "[success]: scanned (" << getFileLocation() << ") file data" << std::endl;
		}

		// set file location

		void setFileLocation() {

			std::cout << std::endl << "[ insert file location ]:";

			std::cin >> file_location;
		}

		// get file location

		std::string getFileLocation() {

			return file_location;
		}

		// parma string data AND return convert binary

		std::string bit(const std::string& data) {

			std::string binaryData;

			for (char character : data) {

				binaryData += std::bitset<8>(character).to_string();
			}
			return binaryData;
		}

		// parma string binary AND return convert data

		std::string data(const std::string& binaryData) {

			std::string Data;

			for (size_t i = 0; i < binaryData.length(); i += 8) {

				std::string byte = binaryData.substr(i,8);

				char character = static_cast<char>(std::bitset<8>(byte).to_ulong());

				Data += character;
			}
			return Data;
		}

};

int main() {

	BinaryApp app("gupt");

	return 0;
}
