#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

main() {
	for (int i = 0; i != 200; ++i) {
		std::system("sudo iw dev wlp0s29f7u1 scan | grep -B 6 WIUNICAL | grep -A 6 2472 | grep signal > data.txt");
		std::ifstream file("data.txt");
		std::string data;
		file >> data >> data;
		// std::stringstream espeak;
		// espeak << "espeak " << std::abs(std::stoi(data)) << " &";
		// std::system(espeak.str().c_str());
		int freq = 200 + ((85 + std::stoi(data)) * 140);
		std::cout << std::stoi(data) << std::endl << std::flush;
		std::stringstream beep;
		beep << "beep -d 30 -r 3 -f" << freq << " &";
		std::system(beep.str().c_str());
		file.close();
	}
}
