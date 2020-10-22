
def Cheaking(A):
    if A==1 : 
        A='A'
    elif A==2:
        A='B'
    elif A==3:
        A='C'
    elif A==4:
        A='D'
    elif A==5:
        A='E'
    elif A==6:
        A='F'
    elif A==7:
        A='G'
    elif A==8:
        A='H'
    elif A==9:
        A='I'
    elif A==10:
        A='J'
    elif A==11:
        A='K'
    elif A==12:
        A='L'
    elif A==13:
        A='M'
    elif A==14:
        A='N'
    elif A==15:
        A='O'
    elif A==16:
        A='P'
    elif A==17:
        A='Q'
    elif A==18:
        A='R'
    elif A==19:
        A='S'
    elif A==20:
        A='T'
    elif A==21:
        A='U'
    elif A==22:
        A='V'
    elif A==23:
        A='W'
    elif A==24:
        A='X'
    elif A==25:
        A='Y'
    elif A==26:
        A='Z'
    elif A==27:
        A='a'
    elif A==28:
        A='b'
    elif A==29:
        A='c'
    elif A==30:
        A='d'
    elif A==31:
        A='e'
    elif A==32:
        A='f'
    elif A==33:
        A='g'
    elif A==34:
        A='h'
    elif A==35:
        A='i'
    elif A==36:
        A='j'
    elif A==37:
        A='k'
    elif A==38:
        A='l'
    elif A==39:
        A='m'
    elif A==40:
        A='n'
    elif A==41:
        A='o'
    elif A==42:
        A='p'
    elif A==43:
        A='q'
    elif A==44:
        A='r'
    elif A==45:
        A='s'
    elif A==46:
        A='t'
    elif A==47:
        A='u'
    elif A==48:
        A='v'
    elif A==49:
        A='w'
    elif A==50:
        A='x'
    elif A==51:
        A='y'
    elif A==52:
        A='z'
    elif A==53:
        A='!'
    elif A==54:
        A='@'
    elif A==55:
        A='#'
    elif A==56:
        A='$'
    elif A==57:
        A='%'
    elif A==58:
        A='&'
    elif A==59:
        A='+'
    elif A==60:
        A='-'
    elif A==61:
        A='*'
    elif A==62:
        A='('
    elif A==63:
        A=')'
    elif A==64:
        A='^'
    else :
        A='Error'
    return A;
A=list(input('Enter the number =>'))
D=0
for T in A:
    PO=0
    try:
        T=int(T)
    except:
        PO=1
        # T=str(T)
    if PO==0:
        A[D]=Cheaking(T)
        D=D+1
    else:
        A[D]=T
        D=D+1
AA=''.join(A)    
print(AA)
