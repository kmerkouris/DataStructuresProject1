#include <common_types.h>
#include <raylib.h>
#include <state.h>
#include <ADTSet.h>
#include <acutest.h>
#include <a.out.h>


// Επιστρέφει την μοναδική τιμή του set που είναι ισοδύναμη με value,
// ή αν δεν υπάρχει, την μικρότερη τιμή του set που είναι μεγαλύτερη
// από value. Αν δεν υπάρχει καμία τότε επιστρέφει NULL.

Pointer set_find_eq_or_greater(Set set, Pointer value);

// Επιστρέφει την μοναδική τιμή του set που είναι ισοδύναμη με value,
// ή αν δεν υπάρχει, την μεγαλύτερη τιμή του set που είναι μικρότερη
// από value. Αν δεν υπάρχει καμία τότε επιστρέφει NULL.

Pointer set_find_eq_or_smaller(Set set, Pointer value);


//συναρτηση που συγκρινει την εφτιαξα για το σετ
int compare_int(Pointer a , Pointer b);

//συναρτηση για δημιουργια ενος ακεραιου value
int* create_int(int value);
