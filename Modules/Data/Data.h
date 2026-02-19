#ifndef COPYCAT_DATA_H
#define COPYCAT_DATA_H
#include<string>

#endif //COPYCAT_DATA_H

class DataManipulator {
private:
    std::string PathToSaveItems;
protected:
    std::string current;

    std::string Trim(const std::string& text);

    std::string get_clipboard_xclip();
public:
    DataManipulator(const std::string& PathTXT) {
        PathToSaveItems = Trim(PathTXT);
    }
    void save_to_txt(const std::string& text, const std::string& filename);
    std::string GetCurrentClipboard();
    bool SaveNewClipboard(const std::string& CurrentClipboard, const std::string& LastClipboard);
};
