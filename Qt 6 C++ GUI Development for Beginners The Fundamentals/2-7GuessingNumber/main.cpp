#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    int random_number = std::rand();
//    std::cout << "number: " << random_number << std::endl;

    // Make sure the secret number is between 1 and 10
    int secret_number = random_number % 10 + 1;
//    std::cout << secret_number << std::endl;

    // Get user's guess number and check
    int guess_number = -1;
    while(true) {
        std::cout << "Please input your guess number (1 - 10): ";
        std::cin >> guess_number;

        if(guess_number == secret_number) {
            break;
        } else if (guess_number < secret_number) {
            std::cout << "Your guess number is less than secret number" << std::endl;
        } else {
            std::cout << "Your guess number is larger than secret number" << std::endl;
        }
    }

    std::cout << "Congratulation, the number is " << secret_number << std::endl;

    return 0;
}
