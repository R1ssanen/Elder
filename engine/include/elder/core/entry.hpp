#pragma once

#include "elder/core/application.hpp"
#include "elder/core/log.hpp"
#include "elder/eepch.hpp"

int main(int argc, char** argv) {
    using namespace Elder;

    InitLog(LogLevel::DEBUG);
    Unique<Application> App = CreateApp(argc, argv);

#ifdef NDEBUG
    try {
        App->MainLoop();
    } catch (const std::exception Exception) {
        EE_CORE_FATAL(Exception.what());
        return EXIT_FAILURE;
    }
#else
    App->MainLoop();
#endif

    return EXIT_SUCCESS;
}
