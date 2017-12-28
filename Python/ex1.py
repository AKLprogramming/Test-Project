var1 = int(raw_input("Key in first digit: "))
var2 = int(raw_input("Key in second digit: "))
var3 = int(raw_input("Key in third digit: "))

var1odd = (var1%2 != 0) 
var2odd = (var2%2 != 0)
var3odd = (var3%2 != 0)

if(var1odd and var2odd and var3odd):
    if(var1 > var2 > var3):
        print(str(var1) + ' is greater than ' + str(var2) + ' and ' + str(var3))
    elif(var1 > var3 > var2):
        print(str(var1) + ' is greater than ' + str(var3) + ' and ' + str(var2))
    elif(var2 > var1 > var3):
        print(str(var2) + ' is greater than ' + str(var1) + ' and ' + str(var3))
    elif(var2 > var3 > var1):
        print(str(var2) + ' is greater than ' + str(var3) + ' and ' + str(var1))
    elif(var3 > var1 > var2):
        print(str(var3) + ' is greater than ' + str(var1) + ' and ' + str(var2))
    elif(var3 > var2 > var1):
        print(str(var3) + ' is greater than ' + str(var2) + ' and ' + str(var1))
    elif(var1 == var2 == var3):
        print('All three number are the same ' + str(var1))
    elif (var1 == var2):
        if(var2 > var3):
            print(str(var2) + ' is equal to Var1: ' + str(var1) + ' is greater than ' + str(var3))
        else:
            print(str(var2) + ' is equal to Var1: ' + str(var1) + ' is smaller than ' + str(var3))    
    elif(var2 == var3):
        if(var3 > var1):
            print(str(var3) + ' is equal to Var2: ' + str(var2) + ' is greater than Var1: ' + str(var1))
        else:
            print(str(var3) + ' is equal to Var2: ' + str(var2) + ' is smaller than Var1: ' + str(var1))    
        print('Var2: ' +str(var2) + ' is equal to Var3: ' + str(var3) + ' greater than Var1: ' + str(var1))
    elif(var3==var1):
        if(var3 > var2):
            print(str(var3) + ' is equal to Var1: ' + str(var1) + ' is greater than Var2: ' + str(var2))            
        else:
            print(str(var3) + ' is equal to Var1: ' + str(var1) + ' is smaller than Var2: ' + str(var2))
    