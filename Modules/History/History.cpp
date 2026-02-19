#include "History.h"
#include <fstream>


[[nodiscard]] size_t CopyCATHistory::GetNumberOfHistory () { return history.size();}

void CopyCATHistory::GetHistory(const std::string& filename) {
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

std::string CopyCATHistory::GetLastItemClipboard() {
    if (!history.empty()) {
        return history.back();
    }
};

void CopyCATHistory::SetHistory(const std:: string& ItemForClipboard) {
    if (!ItemForClipboard.empty()) {
        history.push_back(ItemForClipboard);
    }
}

void CopyCATHistory::ClearHistory() {
    history.clear();
}

void CopyCATHistory::ClearFileHistory(const std::string &filename) {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
}

void FillHistory() {
    // tibet - preencher interface grafica utiliZe o history
    // integracao com a interface grafica, passar os parametros para uma classe herdada que integrara com os componentes a serem preenchidos
}