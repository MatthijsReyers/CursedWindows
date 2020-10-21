
#include "application.hpp"

class BoxApp : protected cw::application
{
private:
    virtual void run() override;

public:
    BoxApp(/* args */);
};

BoxApp::BoxApp(/* args */)
{
    
}

void BoxApp::run()
{

}

int main(int argc, char const *argv[])
{
    auto app = BoxApp();

    return app.start();
}
