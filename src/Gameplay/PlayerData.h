#ifndef PLAYER_DATA_H 
#define PLAYER_DATA_H
#include <nana/deploy.hpp>
#include <map>

class PlayerData
{
public:
	PlayerData();

	int m_STR;
	int m_CON;
	int m_DEX;
	int m_INT;
	int m_WIS;
	int m_CHA;
	int m_HPMax;
	int m_MPMax;

	nana::detail::native_string_type m_Name;
	nana::detail::native_string_type m_Race;
	nana::detail::native_string_type m_Class;
	int m_Level;

	nana::detail::native_string_type m_Weapon;
	nana::detail::native_string_type m_Shield;
	nana::detail::native_string_type m_Helm;
	nana::detail::native_string_type m_Hauberk;
	nana::detail::native_string_type m_Brassairts;
	nana::detail::native_string_type m_Vambraces;
	nana::detail::native_string_type m_Gauntlets;
	nana::detail::native_string_type m_Gamberson;
	nana::detail::native_string_type m_Cuisses;
	nana::detail::native_string_type m_Greaves;
	nana::detail::native_string_type m_Sollerets;

	std::map<nana::detail::native_string_type, unsigned int> m_Inventory;

	std::map<nana::detail::native_string_type, bool> m_Plots;

	std::map<nana::detail::native_string_type, bool> m_Quests;

	std::map<nana::detail::native_string_type, int> m_Spells;
};
#endif // !PLAYER_DATA_H
