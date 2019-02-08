// main.cpp for playing. the library functions will be in other files.
#include <iostream>
#include <fstream>
#include <unicode/locid.h>
#include <unicode/regex.h>


int main(void) {

    std::ifstream infile("/Users/taha/cs/C++/projects/quran/QuranCorpus/quran-uthmani-with-aya-numbers.txt");    

    if(!infile) {
        std::cout << "Cannot open input file.\n";
        return 1;
    }

    std::string line;
    std::getline(infile, line);
    std::cout << line << std::endl;

    // * regax
    UErrorCode status = U_ZERO_ERROR; 
    RegexMatcher regax_matcher(UnicodeString("\\d+\\|\\d\\|"), 0, status);
    UnicodeString text("114|6|ﻢِﻧَ ٱﻞْﺠِﻧَّﺓِ ﻭَٱﻞﻧَّﺎﺳِ");
    regax_matcher.reset(text);

    UnicodeString string_;
    UnicodeString replacement("");


    // find the pattern and replace
    while (regax_matcher.find(status) && U_SUCCESS(status)) {
       regax_matcher.appendReplacement(string_, replacement, status);
    }
    regax_matcher.appendTail(string_);

    char string__buf[100];
    int nul_index = string_.extract(0, string_.length(), string__buf, sizeof(string__buf));
    string__buf[nul_index] = 0;
    printf("The string_ of find & replace is \"%s\"\n", string__buf);

    return 0;
} // end main

