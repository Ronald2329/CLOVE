#include "clove.h"

int main() 
Begin
    int result = showOptionDialog("Hello, this is a dialog!");

    if (result == 1) 
        showMessageDialog("You pressed OK!");
     else if (result == 2) 
        showMessageDialog("You pressed Cancel!");
	
    return 0;
end
