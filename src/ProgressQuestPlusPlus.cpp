// ProgressQuestPlusPlus.cpp : Defines the entry point for the application.
//

#include "ProgressQuestPlusPlus.h"
#include "config.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/progress.hpp>
#include <nana/gui/timer.hpp>
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

// Function to calculate roman equivalent
nana::detail::native_string_type IntToRoman(int num)
{
    // storing roman values of digits from 0-9
    // when placed at different places
    nana::detail::native_string_type m[] = { nana::to_nstring(""), nana::to_nstring("M"), nana::to_nstring("MM"), nana::to_nstring("MMM") };
    nana::detail::native_string_type c[] = { nana::to_nstring(""),  nana::to_nstring("C"),  nana::to_nstring("CC"),  nana::to_nstring("CCC"),
        nana::to_nstring("CD"), nana::to_nstring("D"), nana::to_nstring("DC"), nana::to_nstring("DCC"), nana::to_nstring("DCCC"), nana::to_nstring("CM") };
    nana::detail::native_string_type x[] = { nana::to_nstring(""),  nana::to_nstring("X"),  nana::to_nstring("XX"),  nana::to_nstring("XXX"),
        nana::to_nstring("XL"), nana::to_nstring("L"), nana::to_nstring("LX"), nana::to_nstring("LXX"), nana::to_nstring("LXXX"), nana::to_nstring("XC") };
    nana::detail::native_string_type i[] = { nana::to_nstring(""),  nana::to_nstring("I"),  nana::to_nstring("II"),  nana::to_nstring("III"),
        nana::to_nstring("IV"), nana::to_nstring("V"), nana::to_nstring("VI"), nana::to_nstring("VII"), nana::to_nstring("VIII"), nana::to_nstring("IX") };

    // Converting to roman
    nana::detail::native_string_type thousands = m[num / 1000];
    nana::detail::native_string_type hundereds = c[(num % 1000) / 100];
    nana::detail::native_string_type tens = x[(num % 100) / 10];
    nana::detail::native_string_type ones = i[num % 10];

    nana::detail::native_string_type ans = thousands + hundereds + tens + ones;

    return ans;
}

// This function returns value
// of a Roman symbol
int RomanToDecimal(std::string& str)
{
    std::map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        /*If present value is less than next value,
          subtract present from next value and add the
          resultant to the sum variable.*/
        if (m[str[i]] < m[str[i + 1]])
        {
            sum += m[str[i + 1]] - m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}

int main()
{
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;

    using namespace nana;

    //Define a form.
    form fm(API::make_center(640,480));

    //Define a label and display a text.
    label charSheetLbl{ fm, "<bold=true>Character Sheet</>" };
    charSheetLbl.text_align(nana::align::left);
    charSheetLbl.typeface(nana::paint::font("", 10, true));
    charSheetLbl.size(nana::size(charSheetLbl.size().width, 25));
    charSheetLbl.format(true);

    label spellBookLbl{ fm, "<bold=true>Spell Book</>" };
    spellBookLbl.text_align(nana::align::left);
    spellBookLbl.typeface(nana::paint::font("", 10, true));
    spellBookLbl.size(nana::size(spellBookLbl.size().width, 25));
    spellBookLbl.format(true);

    progress expPro{ fm, true };
    label labExp{ fm, "Experience" };
    labExp.text_align(nana::align::left);
    labExp.typeface(nana::paint::font("", 10, true));
    labExp.format(true);
    expPro.unknown(false);

    timer timer_;
    timer_.elapse([&expPro](const nana::arg_elapse& a)
    {
            //Resets the known mode progress if its value reaches the amount value.
            if (expPro.value() == expPro.amount())
                expPro.value(0);
            expPro.inc();
    });
    timer_.interval(std::chrono::milliseconds{ 80 });
    timer_.start();


    Stats stats;
    stats.STR.Value = to_nstring("5");
    stats.CON.Value = to_nstring("8");
    stats.DEX.Value = to_nstring("7");
    stats.INT.Value = to_nstring("3");
    stats.WIS.Value = to_nstring("0");
    stats.CHA.Value = to_nstring("15");
    stats.HPMax.Value = to_nstring("10");
    stats.MPMax.Value = to_nstring("17");

    listbox statsLb{ fm, true };
    statsLb.clear_headers();
    statsLb.auto_draw(false);
    statsLb.sortable(false);
    statsLb.append_header("Stat");
    statsLb.append_header("Value");
    stats.AppendToListbox(statsLb);
    statsLb.auto_draw(true);
    statsLb.column_at(0).fit_content();
    statsLb.column_at(0).width((unsigned int)(statsLb.column_at(0).width() * 1.10));
    statsLb.column_at(1).width(200 - statsLb.column_at(0).width());
    statsLb.column_movable(false);
    statsLb.column_resizable(false);
    statsLb.enable_single(true, false);


    Traits traits;
    traits.Name.Value = to_nstring("Derp");
    traits.Class.Value = to_nstring("Treehugger");
    traits.Race.Value = to_nstring("Frisbee");
    traits.Level.Value = to_nstring(69);

    listbox traitsLb{ fm, true };
    traitsLb.clear_headers();
    traitsLb.auto_draw(false);
    traitsLb.sortable(false);
    traitsLb.append_header("Trait");
    traitsLb.append_header("Value");
    traits.AppendToListbox(traitsLb);
    traitsLb.auto_draw(true);
    traitsLb.column_movable(false);
    traitsLb.column_resizable(false);
    traitsLb.column_at(0).width(statsLb.column_at(0).width());
    traitsLb.column_at(1).width(200 - traitsLb.column_at(0).width());
    traitsLb.enable_single(true, false);

    listbox spellsLb{ fm, true };
    spellsLb.clear_headers();
    spellsLb.auto_draw(false);
    spellsLb.sortable(false);
    spellsLb.append_header("Spell");
    spellsLb.append_header("Level");
    spellsLb.auto_draw(true);
    spellsLb.column_movable(false);
    spellsLb.column_resizable(false);
    spellsLb.column_at(0).width(statsLb.column_at(0).width());
    spellsLb.column_at(1).width(200 - traitsLb.column_at(0).width());
    spellsLb.enable_single(true, false);

    Spells spells;
    spells.SetSpell(NativeStringPair{ nana::to_nstring("derp pew"), IntToRoman(512) }, spellsLb);
    spells.SetSpell(NativeStringPair{ nana::to_nstring("depew"), IntToRoman(52) }, spellsLb);
    spells.SetSpell(NativeStringPair{ nana::to_nstring("deew"), IntToRoman(1) }, spellsLb);
    spells.SetSpell(NativeStringPair{ nana::to_nstring("kmkw"), IntToRoman(12) }, spellsLb);

    
    

    label l1{ fm, "l1"};
    label l2{ fm, "l2" };
    label l3{ fm, "l3" };
    label l4{ fm, "l4" };
    label l5{ fm, "l5" };
    label l6{ fm, "l6" };
    label l7{ fm, "l7" };
    label l8{ fm, "l8" };
    

    
    //Layout management
    place plc(fm);
    plc.div("<vertical leftFld arrange=[20,110,195,20,20,20,variable]><centerFld><rightFld>");
    //plc.modify("leftFld", "<vertical <charSheetLbl weight = 20><traitsLb weight = 110><statsLb weight = 195><labExp weight = 20><expPro weight = 20>");
    plc.modify("centerFld", "<vertical <l1 weight = 20><l2 weight = 108><l3 weight = 150><l4 weight = 20><l5 weight = 20>");
    plc.modify("rightFld", "<vertical <l6 weight = 20><l7 weight = 108><l8 weight = 150>");
    plc["leftFld"] << charSheetLbl << traitsLb << statsLb << labExp << expPro << spellBookLbl << spellsLb;
    //plc["charSheetLbl"] << charSheetLbl;
    //plc["traitsLb"] << traitsLb;
    //plc["statsLb"] << statsLb;
    //plc["labExp"] << labExp;
    //plc["expPro"] << expPro;
    plc["l1"] << l1;
    plc["l2"] << l2;
    plc["l3"] << l3;
    plc["l4"] << l4;
    plc["l5"] << l5;
    plc["l6"] << l6;
    plc["l7"] << l7;
    plc["l8"] << l8;

    plc.collocate();
 
    // pd.P2 = "63";
        
    //Show the form
    fm.show();



    //Start to event loop process, it blocks until the form is closed.
    exec();

	return 0;
}
