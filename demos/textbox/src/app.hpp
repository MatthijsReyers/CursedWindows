
#include <cursedwindows/application.hpp>
#include <cursedwindows/layouts/grid.hpp>
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
    // Create grid layout as main layout.
    auto main = std::make_shared<cw::GridLayout>(2,2,0,0);
    this->setMainWidget(main);

    main->setVerticalGap(1);

    // Add bordered layouts to grid.
    main->addWidget(std::make_shared<cw::BorderLayout>(), 0, 0);
    main->addWidget(std::make_shared<cw::BorderLayout>(), 0, 1);
    main->addWidget(std::make_shared<cw::BorderLayout>(), 1, 0);
    main->addWidget(std::make_shared<cw::BorderLayout>(), 1, 1);
}

void TextBoxApp::run()
{

}