#include "TextDao.h"
#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../Factory.h"
#include "TextDao.h"
#include "IDao.h"

TextDao::TextDao() {

}

vector<Song> TextDao::getAll() {
    vector<Song> songs;
    string input = "input/data.txt";
    ifstream reader;    

    cout << "Dang doc thong tin tu: " << input << "\n";

    reader.open(input, ios::in);

    if(reader.good()) {
        // do nothing
    } else {
        cout << "CAN NOT OPEN FILE\n";
        return songs;
    }

    std::string line;
    while (std::getline(reader, line)) {
        std::stringstream ss(line);
        std::string name, type, singer, album, timeStr;

        if (std::getline(ss, name, ',') &&
            std::getline(ss, type, ',') &&
            std::getline(ss, singer, ',') &&
            std::getline(ss, album, ',') &&
            std::getline(ss, timeStr, ',')) {
            
            int time = std::stoi(timeStr); // Convert thời lượng từ string sang int
            songs.emplace_back(name, type, singer, album, time);
        }
    }


    reader.close();
    
    return songs;
}
