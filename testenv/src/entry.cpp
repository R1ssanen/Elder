#include "elder/elder.hpp"

using namespace Elder;

class TestLayer : public Layer {
  public:

    TestLayer(bool tIsOverlay) : Layer(tIsOverlay) { }

    void OnUpdate() override { EE_CLIENT_INFO("From Layer Update."); }
};

class TestApp : public Application {
  public:

    TestApp() : Application() { PushLayer(new TestLayer(false)); }
};

Unique<Application> CreateApp(int argc, char** argv) { return std::make_unique<TestApp>(); }
