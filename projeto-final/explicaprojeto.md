
# Explicação do Projeto 

&nbsp;&nbsp;&nbsp;&nbsp;O projeto consiste em um sistema de gerenciamento de aquário que procura resolver suas alterações sem a necessidade de intervenção humana, restringido seu uso apenas em situações extremas. Conta com um sistema de controle de temperatura, controle de nível d’água, sensores de PH e Amônia, além de um alarme e LCD para indicar os valores e alterações. A representação do sistema é apresentada a seguir:

![](https://github.com/nah2602/embarcadosprojeto/blob/main/projeto-final/fotos/Foto%20FInal.png)

## Explicação dos Sistemas

### Sistema de Nível 

&nbsp;&nbsp;&nbsp;&nbsp;Para criação dessa parte do circuito, foram usados 2 motores que correspondem a um instrumento de retirar água e outro para bombear água. A intenção é que a água seja principalmente retirada do fundo do aquário onde há maiores concentrações de sedimentos, e a água colocada esteja em condições ideais tanto de temperatura quanto de PH e Amônia. Foi considerado um aquário de 1023L, que possui sua estabilidade entre 900L e 950L. Enquanto o nível da água estiver abaixo de 900L a bomba estará ligada e outros recursos como o alarme não irão funcionar, partindo do pressuposto que se a água que está sendo colocada no aquário tem valores ideais para os peixes, o aquário pode se estabilizar a medida que é enchido.

   &nbsp;&nbsp;&nbsp;&nbsp;Assim que o aquário chega a estabilização de nível os recursos que não funcionavam voltam normalmente e há a possibilidade de acontecer a troca parcial da água (troca de 15% a 20% da agua do aquário para redução do nível de amônia e estabilização do PH) caso necessário. Se houver necessidade de troca parcial, o motor de retirada será ativado e alguns segundo depois desligado, em seguida o motor de bomba será ativado também apenas por alguns segundos. Como trata-se uma simulação o tempo é bem curto, para um sistema real deve ser feita um calculo estimado do quanto seria a porcentagem necessária para aquele espaço. 
   
&nbsp;&nbsp;&nbsp;&nbsp;Ademais, caso o aquário fique cheio, a maquina de retirada de água é ativada, assim como o alarme e o LCD indicam que há muita água no tanque. 

### Sistema PH e Amônia

&nbsp;&nbsp; &nbsp;&nbsp; Em tese, é composto apenas pelos sensores de PH e de Amônia, entretanto está relacionado ao sistema de nível d’água através da troca parcial. 
&nbsp;&nbsp; &nbsp;&nbsp; Para manutenção dos peixes foi estabelecido um valor de PH ideal entre 8 e 6. Dentro desses valores o aquário estará com PH estável, se os valores forem alterados na faixa de 9 a 5.5, mesmo não sendo o PH ideal o alarme não será ativado pois a troca parcial da água acontecerá (se houver no min 900L no tanque e no max 950L). Caso mesmo depois da troca parcial o valor continue alterando, seja aumentando ou abaixando, e passe da faixa limite o alarme será ativado e o LCD mostrará qual o problema, PH ALTO ou PH BAIXO. 

&nbsp;&nbsp; &nbsp;&nbsp; Com a amônia é semelhante. A quantidade ideal é 0, no entanto é aceitável que possua entre 0,02 e 0,04. Ao chegar em 0,04 e ficando abaixo de 0,06 começa a ocorrer a troca parcial da água que deve estabilizar os níveis de amônia já que a água colocada deve ser livre de amônia. Mas se mesmo com a troca o valor alterar mais, o alarme será ativado e o LCD indicará a alta da amônia. 


### Sistema de Controle de Temperatura

&nbsp;&nbsp; &nbsp;&nbsp; É composto por 2 instrumentos um para esquentar e outro para resfriar, além de um sensor de temperatura. A temperatura ideal para o aquário deve ser entre 25°C e 21°C, entretanto há uma faixa de tolerância de 19°C a 27 °C e quando o valor entra nessa faixa os motores respectivos ao problema são ligados, o de esfriar quando estiver muito quente e de aquecer quando muito frio. Se o valor ultrapassar a faixa de tolerância, o alarme será ativado e aparecerá no LCD “  Temperatura não ideal” com o respectivo valor de temperatura. Nesse sistema durante a faixa de tolerância de 19°C a 27 °C os motores não ficarão ativos de a troca parcial estiver ativa, no entanto se ultrapassar essa faixa, mesmo estando em troca parcial, o motor será ativado. Ocorre uma vez que mesmo que suponha-se que a água é uma água ideal para o aquário, em algumas regiões pode ser difícil ter o controle sobre a temperatura da agua. Ademais, o sistema nesse caso continuara funcionando após o toque do alarme, uma vez que é diferente da troca parcial que pode causar choque osmóticos nos peixes se feita em grande porcentagem, ou correr o risco de estar usando uma água inapropriada. 

### Sistema de Informação

&nbsp;&nbsp; &nbsp;&nbsp; Há um LCD no sistema que quando o aquário está estável apresenta os valores obtidos pelos sensores, mas quando há alguma alteração ele deixa de exibir todos valores e foca no problema a ser corrigido. Já o alarme, é ativado apenas quando não há mais jeito de corrigir o problema de forma automática e há necessidade de intervenção no sistema. 


### ***[Codigo Final do Projeto](https://github.com/nah2602/embarcadosprojeto/blob/main/projeto-final/codigofinal.c)***
