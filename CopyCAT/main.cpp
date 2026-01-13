#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <thread>
#include <chrono>
#include <csignal>

namespace FileSystem = std::filesystem;

volatile bool running = true;
std::string last_clipboard;

const char* HomeDir = std::getenv("HOME");

std::string NameFileTexts = "TXT.dat";
std::string NameFileConfig = "CONFIG.ini";
std::string DirTexts = "History/Text";

bool PathExists(const std::string& Path) {
    return FileSystem::exists(Path);
}

class CopyCAT {
protected:
    int NumberItens;
    FileSystem::path PathApplication = FileSystem::path(HomeDir) / ".local/share/CopyCAT";
    std::string PathTexts;

public:
    CopyCAT() {
        NumberItens = 0;
        PathTexts = PathApplication / DirTexts / NameFileTexts;
    };

    void SetNumber(int Number) {NumberItens = Number;}
    [[nodiscard]] std::string GetPathApplication() const {return PathApplication.string();}
};

class CopyCATHistory{
private:
    std::string line, item;
    std::vector<std::string> history;
public:
    [[nodiscard]] size_t GetNumberOfHistory() const{ return history.size();}

    void GetHistory(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            while (std::getline(file, item)) {
                if (!item.empty()) {
                    history.push_back(item);
                }
            }
        }
        file.close();
    }

    void SetHistory(const std:: string& ItemForClipboard) {
        if (!ItemForClipboard.empty()) {
            history.push_back(ItemForClipboard);
        }
    }

    void ClearHistory() {
        history.clear();
    }

    static void ClearFileHistory(const std::string& filename) {
       std::ofstream file(filename, std::ios::out | std::ios::trunc);
    }

    void FillHistory() {
        // tibet
        // - preencher interface grafica utiliZe o history
        // integracao com a interface grafica, passar os parametros para uma classe herdada que integrara com os componentes a serem preenchidos
    }
};



void signal_handler(int sig) {
    running = false;
}

std::string get_clipboard_xclip() {
    FILE* pipe = popen("xclip -selection clipboard -o 2>/dev/null", "r");
    if (!pipe) return "";

    char buffer[1024];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}

void save_to_txt(const std::string& text, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);  // append!
    if (file.is_open()) {
        file << text << "\n";
        file.close();
    }
}

int main() {
    signal(SIGINT, signal_handler);

    std::cout << "--- CopyCAT Monitor ---" << std::endl;

    CopyCAT CP;
    std::string FullPath = CP.GetPathApplication();

    if (!PathExists(FullPath)) {
        FileSystem::create_directories(FullPath);
        std::cout << "Created directory: " << FullPath << std::endl;
    }

    std::string path_txt = CP.GetPathApplication() + "/History/Text/TXT.dat";

    std::string home = std::getenv("HOME");

    FileSystem::create_directories(FileSystem::path(path_txt).parent_path());

    // Load data in TXT to Vector
    CopyCATHistory History;
    History.GetHistory(path_txt);

    while (running) {
        std::string current = get_clipboard_xclip();

        if (current != last_clipboard && !current.empty() && current.length() > 1) {
            std::cout << ">>> NEW: LENGTH (" << current.length() << " chars): "
                      << current.substr(0, 100) << (current.length() > 100 ? "..." : "") << std::endl;

            last_clipboard = current;

            History.SetHistory(current);

            // Salving to TXT.DAT
            save_to_txt(current, path_txt);
            std::cout << "SAVE!: " << History.GetNumberOfHistory() << " items" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "\nClosing... Score: " << History.GetNumberOfHistory() << " saved items!" << std::endl;
    return 0;
}
