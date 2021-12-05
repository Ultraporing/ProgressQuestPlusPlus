// ProgressQuestPlusPlus.cpp : Defines the entry point for the application.
//

#include "ProgressQuestPlusPlus.h"
#include "config.h"
#include <nana/gui.hpp>
#include <string>
#include "Gameplay/Player.h"

using namespace std;

int main()
{
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;

    using namespace nana;

    //Define a form.
    form fm(API::make_center(800,600));
    Player* plr = new Player(fm);
    // only way to get rid of it: delete plr;
 
    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();

    delete plr;

	return 0;
}
