#include "Soundex.h"
#include <unordered_map>
#include <cctype>

// Mapping of characters to their corresponding Soundex codes
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

// Initialize the Soundex code with the first character of the name
std::string initializeSoundex(const std::string& name) {
    if (name.empty()) return "";
    return std::string(1, toupper(name[0]));
}

// Pad the Soundex code to ensure it is exactly 4 characters long
std::string padSoundex(const std::string& soundex) {
    std::string result = soundex;
    while (result.length() < 4) {
        result += '0';
    }
    return result;
}

// Process the name to generate the Soundex code
std::string processName(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}

// Main function to generate the Soundex code for a given name
std::string generateSoundex(const std::string& name) {
    std::string soundex = processName(name);
    return padSoundex(soundex);
}
