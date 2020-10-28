
#include <application.hpp>
#include <layouts/border.hpp>
#include <memory>

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
    // TODO: subscribe to key event and close window upon pressing button.
}