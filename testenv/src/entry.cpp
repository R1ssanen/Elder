#include "elder/elder.hpp"

class TestApp : public Elder::Application {
  public:

    void OnUpdate() override;
};

void TestApp::OnUpdate() {
    EE_CLIENT_INFO("OnUpdate");
    mIsRunning = false;
}

Elder::Unique<Elder::Application> CreateApp(int argc, char** argv) {
    return std::make_unique<TestApp>();
}
