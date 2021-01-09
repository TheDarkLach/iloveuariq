#include "dlist.h"


int main()
{
    dlist object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    object.removefl(object.head, false);

    object.display();
    
    return 0;
}
