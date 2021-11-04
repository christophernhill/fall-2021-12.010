# Julia native arrays are ones based
x = [1,2,3];
println( "x[1] = ", x[1] );

# Can use 2n and skip "*" in some cases
a=7;
println( "2a = ", 2a );

# Can use unicode, including for some operators
b=4
println( "√b = ",√b);

# Not every unicode as operator works
# in second println cᵈ is seen as a variable
c=2
d=2
println( "cᵈ = ",c^d);
#E println( "cᵈ = ",cᵈ);

# Dot used for element wise operations 
# Otherwise interpreted as whole object function
println( "x.^3 = ",x.^3);
#E println( "x^3 = ",x^3);

#### ERROR: LoadError: MethodError:  .....
#    is a very common message from Julia runtime error

# Assignment copies values for scalars, pointers for arrays
a1=3
a2=a1
a1=4
println("a1, a2 = ",a1,", ", a2);
a1=[3]
a2=a1
a1[1]=4
println("a1, a2 = ",a1,", ", a2);

# Dot is used to "broadcast" arrays in assingment (which copies values)
a1=[3]
a2.=a1
a1[1]=4
println("a1, a2 = ",a1,", ", a2);


