// ProgressQuestPlusPlus.cpp : Defines the entry point for the application.
//

#include "ProgressQuestPlusPlus.h"
#include "config.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>



using namespace std;

int main()
{
	std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;

        using namespace nana;

        //Define a form.
        form fm;

        //Define a label and display a text.
        label lab{ fm, "Hello, <bold blue size=16>Nana C++ Library</>" };
        lab.format(true);

        //Define a button and answer the click event.
        button btn{ fm, "Quit" };
        btn.events().click([&fm] {
            fm.close();
            });

        //Layout management
        fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
        fm["text"] << lab;
        fm["button"] << btn;
        fm.collocate();

        //Show the form
        fm.show();

        //Start to event loop process, it blocks until the form is closed.
        exec();

	return 0;
}
