#include "Soundex.h"
#include <unordered_map>
#include <cctype>


char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    c = toupper(c);
    auto it = soundexMap.find(c);
    return it != soundexMap.end() ? it->second : '0';
}


std::string initializeSoundex(const std::string& name) {
    return std::string(1, toupper(name[0]));
}


std::string padSoundex(const std::string& soundex) {
    std::string result = soundex;
    while (result.length() < 4) {
        result += '0';
    }
    return result;
}


std::string processName(const std::string& name) {
    std::string soundex = initializeSoundex(name);
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }
    return soundex;
}


std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    std::string soundex = processName(name);
    return padSoundex(soundex);
}
