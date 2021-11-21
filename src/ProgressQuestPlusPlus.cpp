// ProgressQuestPlusPlus.cpp : Defines the entry point for the application.
//

#include "ProgressQuestPlusPlus.h"
#include "config.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include "PlayerData.h"
//#include <nana/gui/widgets/listbox.hpp>



using namespace std;

struct PairStr
{
public:
    std::string P1;
    std::string P2;
};

nana::listbox::oresolver& operator << (nana::listbox::oresolver& orr, const PairStr& ps)
{
    orr << ps.P1;
    orr << ps.P2;
    return orr;
}

std::ostream& operator << (std::ostream& orr, const PairStr& ps)
{
    orr << ps.P1;
    orr << ps.P2;
    return orr;
}

nana::listbox::iresolver& operator >> (nana::listbox::iresolver& orr, PairStr& ps)
{
    orr >> ps.P1;
    orr >> ps.P2;
    return orr;
}

int main()
{
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;

    using namespace nana;

    //Define a form.
    form fm;

    //Define a label and display a text.
    label lab{ fm, "Hello, <bold blue size=16>Nana C++ Library</>" };
    lab.format(true);

    listbox lbox{ fm, true };
    lbox.clear_headers();
    lbox.auto_draw(true);
    lbox.append_header("Stat");
    lbox.append_header("Value");

    listbox lbox2{ fm, true };
    lbox2.clear_headers();
    lbox2.auto_draw(true);
    lbox2.append_header("Trait");
    lbox2.append_header("Value");

    //string h = "6";
   // lbox.at(nana::listbox::index_pair(1, 0)).value("STR");
   // PairStr pd{"tz", "bu"};
   // auto st = lbox.at(0).append<PairStr>({ "STR", h });
   // auto con = lbox.at(0).append<PairStr>({ "CON", h });
   // auto dex = lbox.at(0).append<PairStr>({ "DEX", h });
    
    ////Read From
    //lbox.at(0).at(0).resolve_to(pd);
    //dex.resolve_to(pd);
    //
    // Write to
  //  lbox.at(0).at(0).resolve_from(pd);
  //  dex.resolve_from(pd);


    //auto c = lbox.column_size();
        // std::initializer_list<std::string> { "ad", "awdwa", "hhh" });
        //pr.display_number(false);
        //pr.expanded(true);
        //pr.append("3");
    
        //lbox.insert_item(nana::listbox::index_pair(0, 0), "STR");
        //lbox.insert_item(nana::listbox::index_pair(1, 0), "3");
        //
        //lbox.insert_item(nana::listbox::index_pair(0, 1), "CON");
        //lbox.insert_item(nana::listbox::index_pair(1, 1), "5");
        //
        //lbox.insert_item(nana::listbox::index_pair(0, 2), "DEX");
        //lbox.insert_item(nana::listbox::index_pair(1, 2), "6");
        //
        //lbox.insert_item(nana::listbox::index_pair(0, 3), "INT");
        //lbox.insert_item(nana::listbox::index_pair(1, 3), "8");
        //
        //lbox.insert_item(nana::listbox::index_pair(0, 4), "WIS");
        //lbox.insert_item(nana::listbox::index_pair(1, 4), "12");
        //
        //lbox.insert_item(nana::listbox::index_pair(0, 5), "CHA");
        //lbox.insert_item(nana::listbox::index_pair(1, 5), "13");

        //Define a button and answer the click event.
        button btn{ fm, "Quit" };
        btn.events().click([&fm] {
            fm.close();
            });

        Stats stats;
        stats.STR.Value = to_nstring("5");
        stats.CON.Value = to_nstring("8");
        stats.DEX.Value = to_nstring("7");
        stats.INT.Value = to_nstring("3");
        stats.WIS.Value = to_nstring("0");
        stats.CHA.Value = to_nstring("15");
        stats.AppendToListbox(lbox);

        Traits traits;
        traits.Name.Value = to_nstring("Derp");
        traits.Class.Value = to_nstring("Treehugger");
        traits.Race.Value = to_nstring("Frisbee");
        traits.Level.Value = to_nstring(69);
        traits.AppendToListbox(lbox2);

        //Layout management
        fm.div("<vert <lisb><lisbb>>");
        fm["lisb"] << lbox;
        fm["lisbb"] << lbox2;
        //fm["text"] << lab;
        //fm["button"] << btn;
        fm.collocate();

       // pd.P2 = "63";
        
        //Show the form
        fm.show();

        //stats.WIS.Value = to_nstring("18");
        stats.UpdateUI();
      //  lbox.at(0).at(0).resolve_from(pd);
        //Start to event loop process, it blocks until the form is closed.
        exec();

	return 0;
}
