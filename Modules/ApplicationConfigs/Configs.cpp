//
// Created by guss on 1/14/26.
//

#include "Configs.h"
#include <iostream>

bool Application::PathExists (const std::string& Path) { return FileSystem::exists(Path);}

[[nodiscard]] std::string Application::GetPathApplication() const {return PathApplication.string();}

[[nodiscard]] std::string Application::GetPathTXTApplication() const { return PathApplication / DirTexts / NameFileTexts;}

void Application::CreateDirectory(const std::string& PathForCreate) {
    if (!PathExists(PathForCreate)) {
        FileSystem::create_directories(PathForCreate);
        std::cout << "Created directory: " << PathForCreate << std::endl;
    }else {
        std::cout << "Directory already exists: " << PathForCreate << std::endl;
    }
};

void Application::StartUpRoutines() {
    std::string FullPath = GetPathApplication();
    std::string PathTxt = GetPathApplication() + "/History/Text/TXT.dat";

    // Try to create Path Application and Text files
    CreateDirectory(FullPath);
    CreateDirectory(PathTxt);
}

void Application::signal_handler(int sig) {Running =  false;}

bool Application::Running = true;
