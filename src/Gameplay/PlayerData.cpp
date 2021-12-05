#include "PlayerData.h"

PlayerData::PlayerData() :
	m_STR(0), m_CON(0),	m_DEX(0), m_INT(0),	m_WIS(0), m_CHA(0),	m_HPMax(0),	m_MPMax(0),
	m_Name(nana::to_nstring("")), m_Race(nana::to_nstring("")),	m_Class(nana::to_nstring("")), m_Level(0),
	m_Weapon(nana::to_nstring("")), m_Shield(nana::to_nstring("")), m_Helm(nana::to_nstring("")), m_Hauberk(nana::to_nstring("")),
	m_Brassairts(nana::to_nstring("")), m_Vambraces(nana::to_nstring("")), m_Gauntlets(nana::to_nstring("")), 
	m_Gamberson(nana::to_nstring("")), m_Cuisses(nana::to_nstring("")),	m_Greaves(nana::to_nstring("")), m_Sollerets(nana::to_nstring("")),
	m_Inventory(std::map<nana::detail::native_string_type, unsigned int>()), m_Plots(std::map<nana::detail::native_string_type, bool>()),
	m_Quests(std::map<nana::detail::native_string_type, bool>()), m_Spells(std::map<nana::detail::native_string_type, int>())
{
}
