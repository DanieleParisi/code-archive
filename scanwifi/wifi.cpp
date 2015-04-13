#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <fstream>

struct Ap {
  std::string ssid;
  int frequency;
  int signal;
  int lastSeen;
  // Ap(std::string ssi, int f, double sig) : ssid(ssi), frequency(f), signal(sig) {};

  int get_ap(std::ifstream &f) {
    std::string data;
    if(!std::getline(f, data))
      return 0;
    if (data.substr(0,2) == "--") {
      std::getline(f, data);
    }
    if (data.substr(1,4) == "freq") {
      frequency = std::stoi(data.substr(7));
      std::getline(f, data); std::getline(f, data); std::getline(f, data);
      signal = std::abs(std::stoi(data.substr(9)));
      std::getline(f, data);
      lastSeen = std::stoi(data.substr(11));
      std::getline(f, data); std::getline(f, data);
      ssid = data.substr(7);
    } else
      return 0;
    return 1;
  }
  friend bool operator< (Ap, Ap);
};

bool operator< (Ap a, Ap b) {
  return a.signal < b.signal;
}

main(int argc, char** argv) {
  std::string device(argv[1]);
  std::string ssidMatch(argv[2]);
  
  for (int i = 0; i != 200; ++i) {
    //std::system("sudo iw dev wlp0s29f7u1 scan | grep -B 6 WIUNICAL | grep -A 6 2472 | grep signal > data.txt");
    std::system(("sudo iw dev " + device + " scan | grep -B 6 SSID > data.txt").c_str());
    std::ifstream file("data.txt");

    std::vector<Ap> vAp;
    while(true) {
      Ap newAp;
      if(!newAp.get_ap(file))
	break;
      vAp.push_back(newAp);
    }
    
    std::sort(vAp.begin(), vAp.end());
    std::system("clear");

    for(auto &ap : vAp) {
      if (ap.lastSeen < 2000)
	std::cout << ap.ssid << " " << ap.signal << " " << ap.frequency << " " << ap.lastSeen << std::endl << std::flush;
    }
    
    for(auto &ap : vAp) {
      std::string subSsid = ap.ssid.substr(0,3);
      if (subSsid == ssidMatch) {
	if (ap.lastSeen < 1500) {
	  std::stringstream espeak;
	  espeak << "espeak " << ap.signal << " &";
	  std::system(espeak.str().c_str());
	  break;
	}
      }
    }
    file.close();
  }
}
