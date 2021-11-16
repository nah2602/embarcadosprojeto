# Esquematização do sistema de PH e do de Amonia 

Os sistemas são isolados, entretanto resolvi apresenta-los juntos para poder exibir o codigo de nivel com a troca parcial da água.

## PH

É importante manter um PH aceitável para vida dos peixes que seria entre 5.5 e 8.5  que é a faixa que a maioria de peixes de aquário vive. O sistema montado visa manter o PH estável através do sistema de trocas parciais de água, assim restringindo o acionamento do alarme quando há necessidade de intervenção humana. Para tal feito, o sistema de troca d'água é ativado quando o PH está maior que 8 e menor ou igual a 9.0 ou menor que 6 e maior ou igual a  5.5 (há um cuidado maior em manter o áquario menos ácido pois peixes que preferem aguas acidas vivem em aguas semineutras, mas os de aguas basicas não sobrevivem em aguas acidas), mas quando o PH ultrapassa 8 e 5.5 o sistem é desativado e o alarme emergencial toca. Isso porque se o sistema não foi eficaz emajustar o PH, ou tem algum problema com a "nova agua"(agua colocada no aquario) ou algum elemnto do aquário está mudando o PH muito rápido e é necessario um olhar humano para entender a situação. 


## Amônia

O sistema da amônia segue o mesmo pensamento do de PH, intervenção humana apenas quando necessário. O ideal é que haja 0 ppm de amonia , mas niveis de até 0,02ppm são aceitaveis, quando ultrapassam disso mas ficando abaixo de 0.04, a luz será ligada indicando que há algo errado. No entanto, o sistema de troca será apenas acionado quando a amonia estiver igual ou acima de 0.04ppm e menor que 0.06(mais doque isso pode ser alarmante para algumas especies) e caso passe de 0.06ppm o sistema é desligado e o alarme acionado já que há necessidade de um olhar humano. 

### Alteração no sistema de troca 

Houve a implantação de um "motor" para retirada da água. Porem, esse motor só funcionara para troca parcial caso o nivel do tanque esteja entre 900 e 950, pois não faz sentido trocar água de um tanque que não está totalmente cheio(se recebendo mais água ele pode se normalizar) ou de um tanque que está alem do limite(pois a retirada da agua, que deve ser feita com a mangueira no "chão" do tanque, pode retirar alguns detritos e normalizar), nesse caso, será primeiro ligado o sistema de retirada e depois o da bomba d'água .Retirada também será ligada caso o tanque esteja acima de 950.


Link do novo código:

[Código](https://github.com/nah2602/embarcadosprojeto/blob/main/sistema-phamonia/codigophamonia.c)


Link da monategem:

[Monatagem](https://github.com/nah2602/embarcadosprojeto/blob/main/sistema-phamonia/montagemphamonia.md)
