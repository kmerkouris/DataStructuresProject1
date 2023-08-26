//////////////////////////////////////////////////////////////////
//
// Test για το state.h module
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "state.h"
#include "set_utils.h"
#include <common_types.h>
#include <raylib.h>
#include <state.h>
#include <ADTSet.h>





void test_state_create() {

	State state = state_create();
	TEST_ASSERT(state != NULL);

	StateInfo info = state_info(state);
	TEST_ASSERT(info != NULL);

	List list = state_objects(state,-2,-10);
	
	TEST_ASSERT(list != NULL);
	
	list = state_objects(state,-100,-2000);

	TEST_ASSERT(list != NULL);
	

	list = state_objects(state,-100,0);

	TEST_ASSERT(list != NULL);

	TEST_ASSERT(info->playing);
	TEST_ASSERT(!info->paused);
	TEST_ASSERT(info->score == 0);
	

	
	
	
	// Προσθέστε επιπλέον ελέγχους
}

void test_state_update() {
	State state = state_create();
	TEST_ASSERT(state != NULL && state_info(state) != NULL);

	// Πληροφορίες για τα πλήκτρα (αρχικά κανένα δεν είναι πατημένο)
	struct key_state keys = { false, false, false, false, false, false, false, false };
	
	// Χωρίς κανένα πλήκτρο, το αεροσκάφος μετακινείται 3 pixels πάνω
	
	Rectangle old_rect = state_info(state)->jet->rect;
	state_update(state, &keys);
	Rectangle new_rect = state_info(state)->jet->rect;

	TEST_ASSERT( new_rect.x == old_rect.x && new_rect.y == old_rect.y - 3 );
	

	keys.down = true;
	old_rect = state_info(state)->jet->rect;
	state_update(state, &keys);
	new_rect = state_info(state)->jet->rect;
	TEST_CHECK( new_rect.x == old_rect.x && new_rect.y == old_rect.y - 2 );
	// Με πατημένο το δεξί βέλος, το αεροσκάφος μετακινείται 6 pixels μπροστά

	keys.up = true;
	old_rect = state_info(state)->jet->rect;
	state_update(state, &keys);
	new_rect = state_info(state)->jet->rect;
	TEST_CHECK( new_rect.x == old_rect.x && new_rect.y == old_rect.y - 6 );

	// Προσθέστε επιπλέον ελέγχους

	keys.right = true;
	old_rect = state_info(state)->jet->rect;
	state_update(state, &keys);
	new_rect = state_info(state)->jet->rect;
	TEST_CHECK(new_rect.x == old_rect.x +3);

	keys.left = true;	
	old_rect = state_info(state)->jet->rect;
	state_update(state, &keys);
	new_rect = state_info(state)->jet->rect;
	TEST_CHECK(new_rect.x == old_rect.x -3);

	
	

	keys.space = true;
 	state_update(state,&keys);
 	TEST_CHECK(state_info(state)->missile!=NULL);


	Rectangle oldmissile = state_info(state)->missile->rect;
	state_update(state,&keys);
	Rectangle newmissile  = state_info(state)->missile->rect;

	TEST_ASSERT(oldmissile.y - 10 == newmissile.y);
 	

}

void test_set_utils()
{
	
	Set set = set_create(compare_int, NULL);
	for (int i = 0; i < set_size(set); i++)
	{
		
		set_insert(set,create_int(rand()));
		
	}
	
	Pointer value = create_int(rand());
	TEST_CHECK(set_find_eq_or_greater(set, value) != NULL);
	TEST_CHECK(set_find_eq_or_smaller(set, value) != NULL);
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "test_state_create", test_state_create },
	{ "test_state_update", test_state_update },
	{ "test_set_utils", test_set_utils },
	{ NULL, NULL} // τερματίζουμε τη λίστα με NULL
};