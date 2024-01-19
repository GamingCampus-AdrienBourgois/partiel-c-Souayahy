#include "Solution3.h"
#include <algorithm>

// Don't forget to enable the exercise in the StudentConfiguration.h file!
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_3

void Solution3::SetWords(const std::vector<std::string>& _words)
{
    words = _words;
}

void Solution3::SortWords()
{
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        std::string lowerA = a;
        std::string lowerB = b;
        std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);

        return lowerA < lowerB;
        });
}

std::vector<std::string> Solution3::GetSortedWords() const
{
    return words;
}

#endif
