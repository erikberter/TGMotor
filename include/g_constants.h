//
// Created by whiwho on 17/04/2020.
//

#ifndef GAME_MOTOR_G_CONSTANTS_H
#define GAME_MOTOR_G_CONSTANTS_H

#include <string>


namespace constants{

    const std::string ASSET_REGEX_PNG = "(^(?!._).*\\.png$)";
    const std::string ASSET_REGEX_LST = "(^(?!._).*\\.lst$)";
    const std::string ASSET_REGEX_STG = "(^(?!._).*\\.stg$)";
    const std::string ASSET_REGEX_PER = "(^(?!._).*\\.per$)";

    inline std::string get_default_file_regex(std::string end_p){
        return "(^(?!._).*\\."+end_p+"$)";
    }



}

#endif //GAME_MOTOR_G_CONSTANTS_H
