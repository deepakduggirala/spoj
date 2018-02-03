
def color(i):
    if i==1:
        return 0
    if i%2 != 0: #right child
        return color(i/2)
    return not color(i/2)

Y=int(raw_input())
P=int(raw_input())
i = (2**Y)-1+P
c = color(i)
if c:
    print 'blue'
else:
    print 'red'