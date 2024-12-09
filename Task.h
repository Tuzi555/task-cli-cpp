//
// Created by jakub on 12/9/2024.
//

#ifndef TASK_H
#define TASK_H
#include <nlohmann/json.hpp>
#include <string>

enum Status {
    kTodo,
    kInProgress,
    kDone
};

NLOHMANN_JSON_SERIALIZE_ENUM(Status,
                             {{kDone,
                             "done"},
                             {kTodo,
                             "todo"},
                             {kInProgress,
                             "in-progress"}});

struct Task {
    int id;
    std::string description;
    Status status;
    time_t createdAt;
    time_t updatedAt;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Task, description, status, createdAt, updatedAt);


#endif //TASK_H
