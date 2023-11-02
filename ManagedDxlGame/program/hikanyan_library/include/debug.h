#pragma once
#include <iostream>
#include <mutex>
#include <string>

class debug
{
public:
    // メッセージログ
    static void log(const std::string& message)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << message << std::endl;
    }

    // エラーログ
    static void log_error(const std::string& message)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cerr << "Error: " << message << std::endl;
    }

private:
    static std::mutex mutex_;
};
