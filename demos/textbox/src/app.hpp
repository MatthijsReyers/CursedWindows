
#include <cursedwindows/application.hpp>
#include <cursedwindows/layouts/border.hpp>

#include <memory>
#include <ncurses.h>

class TextBoxApp : public cw::application
{
public:
    TextBoxApp();

protected:
    virtual void run() override;
};

TextBoxApp::TextBoxApp()
    :cw::application()
{
    // Create bordered layout as main layout.
    this->setMainWidget(std::make_shared<cw::BorderLayout>());
}

void TextBoxApp::run()
{
    
}