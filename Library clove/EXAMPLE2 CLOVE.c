#include <clove.h>

int Init()
Begin
	int age = 25;
    float weight = 70.5;
    double height = 175.8;
    String name1 = "John Doe";
    String name2 = "Ronald";
    
    int a = 10;
    float b = 3.14;
    double c = 2.71828;
    String d= "Hello";
    
    PRINT("a is %s\n", Var(a));
    PRINT("b is %s\n", Var(b));
    PRINT("c is %s\n", Var(c));
    PRINT("d is %s\n", Var(d));
    
    PRINT("My name is:");
    OUTPUT(name2);

    PRINT("\nThe name of my friend is:");
    OUTPUT(name1);
    PRINT("\n");
    OUTPUT(age);
    PRINT("\n");
    OUTPUT(weight);
    PRINT("\n");
    OUTPUT(height);
    PRINT("\n");
end