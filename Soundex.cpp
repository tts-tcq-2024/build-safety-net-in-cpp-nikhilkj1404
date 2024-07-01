#include <string>
#include <cctype>
#include <unordered_map>

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexCodes {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'},
        {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    c = toupper(c);
    auto it = soundexCodes.find(c);
    if (it != soundexCodes.end()) {
        return it->second;
    } else {
        return '0'; // For A, E, I, O, U, H, W, Y and other characters
    }
}

char getFirstCharacterCode(const std::string& name) {
    if (name.empty()) return '\0';
    return toupper(name[0]);
}

std::string processName(const std::string& name, char firstChar) {
    std::string soundex;
    soundex += firstChar;
    char prevCode = getSoundexCode(firstChar);

    // Iterate over the remaining characters of the name
    for (size_t i = 1; i < name.length(); ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            if (soundex.length() >= 4) {
                break; // Stop once we have 4 characters in soundex
            }
            prevCode = code;
        }
    }

    return soundex;
}

std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0');
    return paddedSoundex;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    char firstChar = getFirstCharacterCode(name);
    std::string processedName = processName(name, firstChar);
    std::string paddedSoundex = padSoundex(processedName);

    return paddedSoundex;
}
