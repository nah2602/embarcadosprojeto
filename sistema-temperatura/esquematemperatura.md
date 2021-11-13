# Esquema de Manutenção da Temperatura

O sistema é bem simples, consiste na utilização de um medidor de temperatura que verifique a temperatura a cada "ciclo do loop " do arduino e a partir do recebimento desta informação haverá o acionamento de um sistema de resfriamento ou aquecimento. 

Como cada peixe possui uma necessidade especifica eu deixarei primeiramente uma temperatura média para o aquário de 21°C a 25°C, porque embora hajam especies que gostem de temperaturas mais quentes ou frias, essa é a temperatura média para um aquario comunitário. No entanto, para evitar transtornos do alarme ficar ligando e desligando assim que a temperatura média for atingida, darei um espaçamento de 2°C para que o alarme inicie, a intenção é que os mecanismos sejam ativados assim que as temperaturas MAX e MIN sejam alcançadas e haja um limite de tempo para a normalização da temperatura antes do alarme(caso tudo se normalize sem atingir mais  ou menos 2°C, o alarme não será ligado).

A intenção é otimizar o sistema para evitar alarmes desnecessários, por exemplo, chegou a 26 graus e o resfriamento é ativado, em alguns minutos a temperatura volta ao estado normal e não há necessidade de uma intervenção humana. Entretanto, caso a temperatura ultrapasse as medidas 19°C a 27°C, o alarme será ativado e só desligará quando a temperatura voltar a medir entre 21°C a 25°C. 

Link do código em C responsável pela temperatura:

[Link Código](https://github.com/nah2602/embarcadosprojeto/blob/main/sistema-temperatura/tempcod.c)

Link de instrumentos que poderiam ser usados no circuito:

[Link Instrumentos](https://github.com/nah2602/embarcadosprojeto/blob/main/sistema-temperatura/instrumentos.md)

Link sobre a montagem do circuito:

[Link Montagem](https://github.com/nah2602/embarcadosprojeto/blob/main/sistema-temperatura/montagemcircuito.md)
