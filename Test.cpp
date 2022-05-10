#define CHECK DOCTEST_CHECK
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
using namespace coup;
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
#include "doctest.h"
TEST_CASE("Tests"){

	Game game_1{};

	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	duke.income();
	assassin.income();
	ambassador.income();
	captain.income();
	contessa.income();
	CHECK(duke.coins()==1);

	duke.foreign_aid ();
	assassin.foreign_aid ();
	ambassador.income();
	captain.income();
	contessa.income();

	CHECK(duke.coins()==3);
	CHECK(assassin.coins()==3);
	CHECK(ambassador.coins()==2);
	CHECK(captain.coins()==2);
	CHECK(contessa.coins()==2);

	duke.block(assassin);
	CHECK(assassin.coins()==1);
	assassin.foreign_aid ();
	ambassador.transfer(captain, ambassador);
	
	CHECK(captain.coins()==1);
    CHECK(ambassador.coins()==3);
	captain.income();
	contessa.income();
    CHECK(captain.coins()==2);
    CHECK(contessa.coins()==3);

	duke.tax();
	CHECK(duke.coins()==6);
	assassin.coup(ambassador);
    CHECK_THROWS(contessa.coins());
	captain.steal(duke);
	CHECK(duke.coins()==4);
	CHECK(captain.coins()==4);
	contessa.foreign_aid();

	CHECK(duke.coins()==4);
	CHECK(assassin.coins()==3);
	CHECK(captain.coins()==5);
	CHECK(contessa.coins()==5); 

	duke.block(contessa);
	CHECK(contessa.coins()==4);

	


	}