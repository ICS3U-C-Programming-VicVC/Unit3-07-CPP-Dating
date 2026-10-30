// Copyright (c) 2026 Victor Victor-Calixte All rights reserved.
// .
// Created by: Victor Victor-Calixte
// Date: 10/27/26
// This program will determine whether or not the user is valid to
// date a grandchild based on the asked questions.

#include<iostream>
#include<string>

char const ERR_MSG[] =
"Invalid inputs. \n (FIRST QUESTION MUST BE yes/no)"
"\n (SECOND QUESTION MUST BE AN INTEGER FROM 0-10)\n";
int const ABV_AVG_LOOKS = 6;

char const VALID[] = "yes";
char const INVALID[] = "no";

char const WORTHY_MSG[] = "You've proven worthy to date the grandchild.\n";
char const UNWORTHY_MSG[] =
"Unfortunately, You're unworthy to date the grandchild.\n";

int const SMALLEST_LOOKS_RANGE = 0;
int const LARGEST_LOOKS_RANGE = 10;

int main() {
    // Setting needed variables
    bool validIpt = false;

    std::string isRich;
    std::string hasLooks;

    // Asking the user questions that will validate their worthiness
    std::cout << "Is your income well above average? ("
    << VALID
    << "/"
    << INVALID
    << "): ";
    std::cin >> isRich;

    std::cout << "Rate your looks from "
    << SMALLEST_LOOKS_RANGE
    << "-"
    << LARGEST_LOOKS_RANGE
    << ": ";
    std::cin >> hasLooks;

    // the try statement will make sure the code safely with invalid user inputs
    try {
        // checking is the IsRich input isn't valid
        if (isRich != VALID && isRich != INVALID) {
            std::cout << ERR_MSG;

        } else {
            validIpt = true;
        }

        // This section determines whether or not the user is valid to
        // date the grandchild
        if (validIpt) {
            int hasLooksInt = std::stoi(hasLooks);

            if (hasLooksInt < SMALLEST_LOOKS_RANGE
                || hasLooksInt > LARGEST_LOOKS_RANGE) {
                std::cout << ERR_MSG;

            } else {
                if (hasLooksInt > ABV_AVG_LOOKS) {
                    if (isRich == VALID) {
                        std::cout << WORTHY_MSG;

                    } else {
                        std::cout << UNWORTHY_MSG;
                    }

                } else {
                    std::cout << UNWORTHY_MSG;
                }
            }
        }
        // If the try statement fails,
        // it was likely due to the input from the user being invalid
    } catch (std::invalid_argument) {
        std::cout << ERR_MSG;
    }
}
