
n=int(input("Enter an integer:"))
tab = []
for i in range(1,int(n / 2)+1):
    if(n%i==0):
        tab.append(i)
tab.append(n)
if tab[0]==1 and tab[1]==n:
    print("The number is prime!")
else:
    print("The divisors of the number are:")
    print(tab)