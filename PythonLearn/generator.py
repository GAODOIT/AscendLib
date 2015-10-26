def fab0(max): 
    n, a, b = 0, 0, 1 
    while n < max: 
        print b 
        a, b = b, a + b 
        n = n + 1

fab0(5)

def fab1(max):
    n, a, b = 0, 0, 1 
    L = [] 
    while n < max: 
        L.append(b) 
        a, b = b, a + b 
        n = n + 1 
    return L
print("-------------------fab1")
f = fab1(5)
print f

#for n in fab1(5):
#    print n


def fab2(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b,"111"
        a, b = b, a + b 
        n = n + 1
print("-------------------fab2")
for n in fab2(5):
    print n

