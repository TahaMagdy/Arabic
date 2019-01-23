// main.cpp for playing. the library functions will be in other files.
#include <iostream>


#include <unicode/utext.h>
#include <unicode/ubrk.h>
//#include <unicode/ustring.h>
#include <assert.h>

int countWords(const char *utf8String) {
    UText          *ut        = NULL;
    UBreakIterator *bi        = NULL;
    int             wordCount = 0;
    UErrorCode      status    = U_ZERO_ERROR;

    ut = utext_openUTF8(ut, utf8String, -1, &status);
    bi = ubrk_open(UBRK_WORD, "en_us", NULL, 0, &status);

    ubrk_setUText(bi, ut, &status);
    while (ubrk_next(bi) != UBRK_DONE) {
        if (ubrk_getRuleStatus(bi) != UBRK_WORD_NONE) {
            /* Count only words and numbers, not spaces or punctuation */
            wordCount++;
        }
    }
    utext_close(ut);
    ubrk_close(bi);
    assert(U_SUCCESS(status));
    return wordCount;
}


int main(void) {
    const char* m = "الحمد لله رب العلمين";
    std::cout << countWords(m) << " Words" << std::endl;
    return 0;
} // end main

