
#ifndef COPYCAT_HISTORY_H
#define COPYCAT_HISTORY_H
#include <string>
#include <vector>

#endif //COPYCAT_HISTORY_H

class CopyCATHistory {
private:
    std::string line, item;
    std::string last_clipboard;
protected:
    std::vector<std::string> history;
public:
    void GetHistory(const std::string& filename);

    std::string GetLastItemClipboard();

    [[nodiscard]] size_t GetNumberOfHistory();

    void SetHistory(const std:: string& ItemForClipboard) ;

    void ClearHistory();

    void ClearFileHistory(const std::string& filename);

    void FillHistory();
};