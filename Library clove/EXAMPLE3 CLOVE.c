#include <clove.h>

boolean sizeOfNumbers(int number1, int number2)
Begin
    if (number1 > number2)
        return False;
    else if (number1 == number2)
        return True;
    else
        return False; // Aqui você pode retornar False diretamente, pois já tratamos o caso de número1 == number2 acima.
end

int Init()
Begin
    int number1, number2;
    String size_true = "They are equals!";
    String size_false = "They are not equals!";
	
    echo("Choice the number one:\n");
    INPUT(number1);
	
    echo("\nNow, Choice the number two:\n");
    INPUT(number2);
	
    if (sizeOfNumbers(number1, number2) == True)
        echo(size_true);
    else
        echo(size_false);

end
