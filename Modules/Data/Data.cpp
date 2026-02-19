#include "Data.h"
#include <fstream>

// Remove blank spaces in between string
std::string DataManipulator::Trim(const std::string& text) {
    std::string s = text;
    s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
    s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
    return s;
};

std::string DataManipulator::get_clipboard_xclip() {
    FILE* pipe = popen("xclip -selection clipboard -o 2>/dev/null", "r");
    if (!pipe) return "";

    char buffer[1024];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);
    return Trim(result);
}

void DataManipulator::save_to_txt(const std::string& text, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << Trim(text) << "\n";
        file.close();
    }
}

std::string DataManipulator:: GetCurrentClipboard() {
    current = get_clipboard_xclip();
    if (not std::empty(current)) {return Trim(current);}
}

bool DataManipulator:: SaveNewClipboard(const std::string& CurrentClipboard, const std::string& LastClipboard) {
    Trim(CurrentClipboard);
    Trim(LastClipboard);

    if (CurrentClipboard != LastClipboard && !CurrentClipboard.empty() && !LastClipboard.empty()) {
        return true;
    }
}