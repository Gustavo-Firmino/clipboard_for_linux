#ifndef COPYCAT_CONFIGS_H
#define COPYCAT_CONFIGS_H
#include <filesystem>

#endif //COPYCAT_CONFIGS_H

namespace FileSystem = std::filesystem;

class  Application {
protected:
    const char* HomeDir = std::getenv("HOME");
    std::string NameFileTexts = "TXT.dat";
    std::string NameFileConfig = "CONFIG.ini";
    std::string DirTexts = "History/Text";
private:
public:
    static bool Running;

    FileSystem::path PathApplication = FileSystem::path(HomeDir) / ".local/share/CopyCAT";

    static bool PathExists(const std::string& Path);
    [[nodiscard]]std::string GetPathApplication() const;
    [[nodiscard]] std::string GetPathTXTApplication() const;
    void CreateDirectory(const std::string& PathForCreate);
    void StartUpRoutines();
    static void signal_handler(int sig);
};