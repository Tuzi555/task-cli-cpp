#include "Task.h"
#include "Commands.h"

#include <iostream>

#include <fmt/core.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please provide a command to execute.\n";
        std::abort();
    }
    const std::string command{argv[1]};

    if (command == Commands::Add) {
        if (argc != 3) {
            fmt::println(
                "Please provide a an item to add to the list (either one word or multiple words inside the double quotes)");
            std::abort();
        }
        const std::string item{argv[2]};
        fmt::println("Item \"{}\" was added to the list.", item);
        const nlohmann::json j = Task{1, item, kTodo, time(nullptr), time(nullptr)};
        std::cout << j;
    }
    if (command == Commands::Delete) {
        if (argc != 3) {
            fmt::println("Please provide and id of a task to delete.");
            std::abort();
        }
        const std::string id{argv[2]};
        fmt::println("Item with id \"{}\" was deleted.", id);
    }

    return 0;
}
