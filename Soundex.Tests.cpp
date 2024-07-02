#include <gtest/gtest.h>
#include "Soundex.h"

// Test that handles an empty string
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Test that handles a single character
TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
}

// Test that handles names with vowels and certain consonants that should be ignored
TEST(SoundexTest, HandlesIgnoredCharacters) {
    EXPECT_EQ(generateSoundex("AEIOU"), "A000");
    EXPECT_EQ(generateSoundex("HW"), "H000");
}

// Test that handles names with consonants that should be mapped to the same code
TEST(SoundexTest, HandlesSimilarSoundingConsonants) {
    EXPECT_EQ(generateSoundex("BFPV"), "B100");
    EXPECT_EQ(generateSoundex("CGJKQSXZ"), "C200");
    EXPECT_EQ(generateSoundex("DT"), "D300");
    EXPECT_EQ(generateSoundex("L"), "L000");
    EXPECT_EQ(generateSoundex("MN"), "M500");
    EXPECT_EQ(generateSoundex("R"), "R000");
}

// Test that handles names with adjacent consonants that should be ignored
TEST(SoundexTest, HandlesAdjacentConsonants) {
    EXPECT_EQ(generateSoundex("BB"), "B100");
    EXPECT_EQ(generateSoundex("CC"), "C200");
    EXPECT_EQ(generateSoundex("DD"), "D300");
}

// Test that handles longer names that require truncation
TEST(SoundexTest, HandlesLongNames) {
    EXPECT_EQ(generateSoundex("Abhishek"), "A120");
    EXPECT_EQ(generateSoundex("Nikhil"), "N240");
}

// Test that handles mixed cases
TEST(SoundexTest, HandlesMixedCase) {
    EXPECT_EQ(generateSoundex("KrishnaVamshi"), "K625");
    EXPECT_EQ(generateSoundex("SathishKumar"), "S325");
}

// Test that handles names with hyphens or spaces
TEST(SoundexTest, HandlesHyphensAndSpaces) {
    EXPECT_EQ(generateSoundex("Ramesh-Suresh"), "R520");
    EXPECT_EQ(generateSoundex("Ramesh Suresh"), "R520");
}

// Test that handles names with non-alphabetic characters
TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("T'Sharma"), "T650");
    EXPECT_EQ(generateSoundex("T123Sharma"), "T650");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
