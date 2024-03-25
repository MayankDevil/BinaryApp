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

		    std::cout
		    
		    << "\n [0] quit program" << std::endl
		    
		    << "\n [1] scan file data" << std::endl
		    
		    << "\n [2] convert data into binary data" << std::endl
		    
		    << "\n [3] convert binary data to orignal data" << std::endl
		    
		    << "\n [4] read file data" << std::endl
		    
		    << "\n [5] write file data" << std::endl;

			    
            while (true) {
            
			    std::cout << std::endl << " /// COMMAND NUMBER /// :";
			    
			    std::cin >> choice;
			    
			    if (choice == 1) {
			    
			        scanFileData();
			    
			    } else if (choice == 2) {

			        convertBinaryData();
			    
			    } else if (choice == 3) {
			    
			        convertOrignalData();
                
                } else if (choice == 4) {
			    
			        readFileData();
			    
			    } else if (choice == 5) {
			    
			        writeFileData();
			    
			    } else {

                    std::cout << "\n(terminated)..." << std::endl;
                    
                    exit(0);
			    }   
		    }
		}

	private:
	
	    // write file data
	    
	    
	    void writeFileData() {
	    
	        setFileLocation();

			file.open(getFileLocation(), std::ios::app);

			if (file.is_open()) {
			
			    std::cout << std::endl << "[ write data ] quit on press enter:";

			    std::cin >> file_data;

				file << file_data;
			}
	    }

        // read file data

		void readFileData() {

			setFileLocation();

			file.open(getFileLocation(), std::ios::in | std::ios::binary);

			if (file.is_open()) {

				while (getline(file, line)) {

					std::cout << line << std::endl;
				}
			}

			file.close();

			std::cout << "\n[success]: read (" << getFileLocation() << ") file data" << std::endl;
		}

		// convert orignal data

		void convertOrignalData() {

			setFileLocation();

			file.open(getFileLocation(), std::ios::trunc | std::ios::out);

			if (file.is_open()) {

				file << data(file_data);
			}

			file.close();

			std::cout << "\n[success]: orignal data file (" << getFileLocation() << ") is created" << std::endl;
		}

		// convert binary data

		void convertBinaryData() {

			setFileLocation();

			file.open(getFileLocation(), std::ios::out | std::ios::binary);

			if (file.is_open()) {

				file << bit(file_data);
			}

			file.close();

			std::cout << "\n[success]: binary file (" << getFileLocation() << ") is created" << std::endl;
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

			std::cout << "\n[success]: scanned (" << getFileLocation() << ") file data" << std::endl;
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
