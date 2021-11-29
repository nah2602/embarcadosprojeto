
# Explicação do Projeto 

O projeto consiste em um sistema de gerenciamento de aquário que procura resolver suas alterações sem a necessidade de intervenção humana, restringido seu uso apenas em situações extremas. Conta com um sistema de controle de temperatura, controle de nível d’água, sensores de PH e Amônia, além de um alarme e LCD para indicar os valores e alterações. A representação do sistema é apresentada a seguir:

![](https://github.com/nah2602/embarcadosprojeto/blob/main/projeto-final/fotos/Foto%20FInal.png)

## Explicação dos Sistemas

### Sistema de Nível 

Para criação dessa parte do circuito, foram usados 2 motores que correspondem a um instrumento de retirar água e outro para bombear água. A intenção é que a água seja principalmente retirada do fundo do aquário onde há maiores concentrações de sedimentos, e a água colocada esteja em condições ideais tanto de temperatura quanto de PH e Amônia. Foi considerado um aquário de 1023L, que possui sua estabilidade entre 900L e 950L. Enquanto o nível da água estiver abaixo de 900L a bomba estará ligada e outros recursos como o alarme não irão funcionar, partindo do pressuposto que se a água que está sendo colocada no aquário tem valores ideais para os peixes, o aquário pode se estabilizar a medida que é enchido.

   Assim que o aquário chega a estabilização de nível os recursos que não funcionavam voltam normalmente e há a possibilidade de acontecer a troca parcial da água (troca de 15% a 20% da agua do aquário para redução do nível de amônia e estabilização do PH) caso necessário. Se houver necessidade de troca parcial, o motor de retirada será ativado e alguns segundo depois desligado, em seguida o motor de bomba será ativado também apenas por alguns segundos. Como trata-se uma simulação o tempo é bem curto, para um sistema real deve ser feita um calculo estimado do quanto seria a porcentagem necessária para aquele espaço. 
   
Ademais, caso o aquário fique cheio, a maquina de retirada de água é ativada, assim como o alarme e o LCD indicam que há muita água no tanque. 

