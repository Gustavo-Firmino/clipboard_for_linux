#include "CopyCATWindow.h"
#include <iostream>
#include <thread>
#include <csignal>
#include "Modules/ApplicationConfigs/Configs.h"
#include "Modules/History/History.h"
#include "Modules/Data/Data.h"

CopyCATWindow::CopyCATWindow(QWidget *parent) {
    ui.setupUi(this);
    signal(SIGINT, Application::signal_handler);

    Application App;
    CopyCATHistory History;

    std::cout << R"(
                /\_/\
               ( o.o )
                > ^ <
()|--------- CopyCAT Monitor ---------|()
)" << std::endl;


    App.StartUpRoutines();

    std::string PathTXTDir = App.GetPathTXTApplication();

    DataManipulator Data(PathTXTDir);

    // Load data in TXT to Vector
    History.GetHistory(PathTXTDir);

    std::string Last;

    while (Application::Running) {
        std::string Current = Data.GetCurrentClipboard();

        if (Current != Last && !Current.empty() && Current.length() > 1) {
            std::cout << ">>> NEW: " << Current.substr(0, 100) << std::endl;

            History.SetHistory(Current);
            Data.save_to_txt(Current, PathTXTDir);
            Last = Current;

            std::cout << "Saved! " << History.GetNumberOfHistory() << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "\nClosing CopyCAT..." << std::endl;
    // return 0;
}