#pragma once

#include "elder/core/application.hpp"
#include "elder/core/log.hpp"
#include "elder/eepch.hpp"

int main(int argc, char** argv) {
    Elder::InitLog(Elder::LogLevel::TRACE);
    Elder::Unique<Elder::Application> App = CreateApp(argc, argv);

    while (App->IsRunning()) {
#ifdef NDEBUG
        try {
            App->OnUpdate();
        }

        catch (const std::exception& Exception) {
            EE_CORE_FATAL(Exception.what());
            return EXIT_FAILURE;
        }

#else
        App->OnUpdate();
#endif
    }

    return EXIT_SUCCESS;
}
