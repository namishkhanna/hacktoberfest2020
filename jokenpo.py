from random import randint
from time import sleep

opcoes = ["Pedra", "Papel", "Tesoura"]

[0] Pedra
[1] Papel
[2] Tesoura

jogador = int(input("Escolha uma opção: "))
pc = randint(0,2)

print("JO\n")
sleep(1)
print("KEN\n")
sleep(1)
print("PO!!!\n")

print("-" * 30)
print(f"O computador escolheu: {opcoes[pc]}")
print(f"O jogador escolheu: {opcoes[jogador]}")
print("-" * 30)

if pc == 0:
    if jogador == 0:
        print("Empate '-'")
    elif jogador == 1:
        print("Você venceu :(")
    elif perguntar == 2:
        print("Eu venci!")
    else:
        print("Essa opção é inválida.")

elif pc == 1:
    if jogador == 0:
        print("Eu venci!")
    elif jogador == 1:
        print("Empate '-'")
    elif jogador == 2:
        print("Você venceu :(")
    else:
        print("Operacao invalida")

elif pc == 2:
    if jogador == 0:
        print("Você venceu :(")
    elif jogador == 1:
        print("Eu venci!")
    elif jogador == 2:
        print("Empate '-'")
    else:
        print("Essa opção é inválida.")
else:
    print("Essa opção é inválida.")
    
