#ifndef GAME_MOTOR_FILES_H
#define GAME_MOTOR_FILES_H

#include <dirent.h>
#include <regex>
#include <functional>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace sp_str {
    using function_id_path = std::function<void(const std::string&, const std::string&)> ;
    using functional_vector = std::vector<std::pair<std::string, function_id_path > > ;
}
void file_rec(const std::string& path, const sp_str::functional_vector& codes) noexcept(false);
json get_json(const std::string& path) noexcept(false);
void copy_file_from_to(const char *src, const char *dest) noexcept(false);
#endif //GAME_MOTOR_FILES_H
