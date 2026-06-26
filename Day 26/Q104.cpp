#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Question {
    std::string prompt;
    std::vector<std::string> options;
    int correctIndex;
};

int main() {
    std::vector<Question> quiz = {
        {
            "What is the capital of France?",
            {"1) Berlin", "2) Madrid", "3) Paris", "4) Rome"},
            3
        },
        {
            "Which planet is known as the Red Planet?",
            {"1) Venus", "2) Mars", "3) Jupiter", "4) Saturn"},
            2
        },
        {
            "What is the result of 5 + 7?",
            {"1) 10", "2) 11", "3) 12", "4) 13"},
            3
        },
        {
            "Which language is primarily used for system programming?",
            {"1) Python", "2) JavaScript", "3) C++", "4) Ruby"},
            3
        },
        {
            "What is the chemical symbol for water?",
            {"1) CO2", "2) H2O", "3) O2", "4) NaCl"},
            2
        }
    };

    std::cout << "Welcome to the Quiz Application!\n";
    std::cout << "Answer the following questions by entering the number of the correct option.\n\n";

    int score = 0;

    for (size_t i = 0; i < quiz.size(); ++i) {
        const Question &q = quiz[i];
        std::cout << "Question " << (i + 1) << ": " << q.prompt << "\n";
        for (const std::string &option : q.options) {
            std::cout << option << "\n";
        }
        std::cout << "Your answer: ";

        int answer = 0;
        std::cin >> answer;
        if (!std::cin || answer < 1 || answer > static_cast<int>(q.options.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Moving to the next question.\n\n";
            continue;
        }

        if (answer == q.correctIndex) {
            std::cout << "Correct!\n\n";
            score++;
        } else {
            std::cout << "Incorrect. The correct answer is option " << q.correctIndex << ".\n\n";
        }
    }

    std::cout << "Quiz complete! You scored " << score << " out of " << quiz.size() << ".\n";

    return 0;
}
