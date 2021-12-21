// ProgressQuestPlusPlus.cpp : Defines the entry point for the application.
//

#include "ProgressQuestPlusPlus.h"
#include "config.h"
#include <nana/gui.hpp>
#include <string>
#include "Gameplay/PlayerScreen.h"
#include <zstr.hpp>

using namespace std;

int main()
{
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;

    using namespace nana;
    zstr::istreambuf zsbuf(std::cin.rdbuf(), 1 << 16, true);
    //Define a form.
    form fm(API::make_center(800,600));
    PlayerScreen* plr = new PlayerScreen(fm);
    PlayerData data = PlayerData();
    plr->SetPlayer(data);
    plr->GetPlayer().m_Class = nana::to_nstring("derp");
    plr->UpdateUI();
    // only way to get rid of it: delete plr;
    
    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();

    delete plr;

	return 0;
}
