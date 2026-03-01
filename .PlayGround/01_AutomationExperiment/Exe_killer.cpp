#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

// ANSI color helpers
namespace ui {
    constexpr const char* RED    = "\033[91m";
    constexpr const char* GREEN  = "\033[92m";
    constexpr const char* YELLOW = "\033[93m";
    constexpr const char* BLUE   = "\033[94m";
    constexpr const char* MAGENTA= "\033[95m";
    constexpr const char* CYAN   = "\033[96m";
    constexpr const char* RESET  = "\033[0m";
}

void divider(const std::string& title = "") {
    std::cout << ui::CYAN
              << "################################################################"
              << ui::RESET << "\n";
    if (!title.empty()) {
        std::cout << ui::CYAN << title << ui::RESET << "\n";
        std::cout << ui::CYAN
                  << "################################################################"
                  << ui::RESET << "\n";
    }
}

int main() {
    const std::string targetFolder =
        "C:\\Users\\mohit\\OneDrive\\Documents\\00_Code";

    divider("EXECUTABLE CLEANUP UTILITY");

    std::cout << ui::RED
              << "WARNING: This operation will PERMANENTLY delete\n"
              << "all .exe files inside the following directory:\n\n"
              << ui::RESET;

    std::cout << ui::YELLOW << targetFolder << ui::RESET << "\n\n";

    std::cout << ui::MAGENTA
              << "Press ENTER to proceed or close this window to abort..."
              << ui::RESET << "\n";
    std::cin.get();

    divider("SCANNING FILE SYSTEM");

    std::vector<fs::path> exeFiles;

    try {
        for (const auto& entry :
             fs::recursive_directory_iterator(targetFolder)) {
            if (entry.is_regular_file() &&
                entry.path().extension() == ".exe") {
                exeFiles.push_back(entry.path());
            }
        }
    } catch (const std::exception& e) {
        std::cout << ui::RED << "Scan failed: "
                  << e.what() << ui::RESET << "\n";
        return 1;
    }

    if (exeFiles.empty()) {
        std::cout << ui::GREEN
                  << "No .exe files found. Nothing to delete."
                  << ui::RESET << "\n";
        return 0;
    }

    std::cout << ui::BLUE
              << "Found " << exeFiles.size()
              << " executable file(s).\n"
              << ui::RESET;

    divider("DELETION IN PROGRESS");

    size_t deleted = 0;
    size_t failed  = 0;

    for (const auto& file : exeFiles) {
        std::cout << ui::RED << "[DELETE] "
                  << file.string() << ui::RESET << "\n";
        try {
            fs::remove(file);
            ++deleted;
        } catch (const std::exception& e) {
            ++failed;
            std::cout << ui::YELLOW
                      << "   Failed: " << e.what()
                      << ui::RESET << "\n";
        }
    }

    divider("SUMMARY");

    std::cout << ui::GREEN << "Deleted successfully : "
              << deleted << ui::RESET << "\n";
    std::cout << ui::YELLOW << "Failed to delete     : "
              << failed << ui::RESET << "\n";

    std::cout << "\n" << ui::CYAN
              << "Cleanup complete. Press ENTER to exit."
              << ui::RESET << "\n";
    std::cin.get();

    return 0;
}
