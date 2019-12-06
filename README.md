![Portaria_Inteligente](https://user-images.githubusercontent.com/56705850/70350809-41446480-1846-11ea-9ec0-62768f8ce882.png)


# Access Control
O objetivo do projeto é usar um teclado matricial de membrana para realizar o acesso de pessoas em um condomínio. No sistema existem quatro usuários, cada qual com suas respectivas senhas. Para realizar a entrada, primeiramente é necessária a digitação da senha. Se estiver correta, a passagem é liberada e uma mensagem é enviada ao porteiro através de dispositivo bluetooth, informando o titular e apartamento do usuário. Também é possível fazer a redefinição de senhas (com informação ao porteiro por bluetooth), sendo exigida uma senha mestre para verificação de autenticidade. No caso em que houver sucessivas falhas na tentativa de entrada, o sistema será travado, sendo necessária  a presença do porteiro para inserção da senha-mestre, gerando o destravamento do sistema.
Em cada etapa os LEDs acedem de forma única, informando o funcionamento do programa com base na mensagem apresentada ao usuário.
Por exemplo, quando a senha é verificada como correta, o LED azul acende, indicando que a passagem foi liberada; caso a passagem seja negada, o LED vermelho acende; se ocorrerem 3 erros consecutivos da senha, o sistema trava e os dois LEDs ficam acesos.


## Aplicações:
Uso geral para controle de entrada de pessoas em diferentes tipos de ambientes, tais como: empresas, escolas, condomínios, residências. Isso moatra a versatilidade do sistema, sendo necessário fazer apenas poucas alterações para que ele funcione perfeitamente nesses locais.


## Materiais utilizados:
-2x STM32F030F4P6 (GREENPILL)
<br />-Gravador ST-LINK V2
<br />-Display oLED
<br />-Teclado matricial 4x4
<br />-Módulo Bluetooth HC-05
<br />-2x LEDs
<br />-Protoboard e jumpers


## Dispositivos do microcontrolador utilizados:
-GPIO
<br />-USART
<br />-SPI


## Pinagem
![Slide2](https://user-images.githubusercontent.com/56704375/70345776-8911be80-183b-11ea-8b6c-712039b9c05b.PNG)
![Slide1](https://user-images.githubusercontent.com/56704375/70345649-494ad700-183b-11ea-9e68-0fd60f4563db.PNG)


## Fluxograma de entrada
![Fluxograma](https://user-images.githubusercontent.com/56705850/70352146-3a6b2100-1849-11ea-8d6c-a3dcadfaabbf.jpeg)


## Fluxograma de alteração de senha
![Fluxograma2](https://user-images.githubusercontent.com/56705850/70353252-c4b48480-184b-11ea-9fd9-35a1a86d6695.jpeg)


## Possíveis melhorias:
-Na comunicação Bluetooth-Monitor, poderia ser adicionada também a hora de chegada.
<br />-A implementação de 3 erros para a senha-mestre.
<br />-Utilização de um banco de dados para armazenagem mais segura dos dados.
<br />-Implementar a opção de destravar o sistema a partir do bluetooth.


## Problemas Encontrados:
-Não foi possível adicionar mais funcionalidades, pois o sistema utiliza apenas 4Bits para envio de dados entre as duas GreenPills.
<br />-A implementação da hora de chegada não foi possível, pois a função utilizada não funciona na GreenPill porque ela excede o espaço da memória flash.
<br />-Um dos principais problemas foi a comunicação entre as duas GreenPills, onde para contornar esse empecilho tivemos que enviar bits a partir de 4Portas da "Placa1" para a "Placa2", e assim ser possível fazer essa transmissão de dados.


## Membros:
[📧](https://github.com/LeirbagGabriel)Gabriel Castro Marinho                    405229
<br />[📧](https://github.com/Kazimierz-dev)Gabriela Casimiro de Lima           370065
<br />[📧](https://github.com/LeirbagGabriel)Rodrigo Maciel Braz                 385618
<br />[📧](https://github.com/thierryos)Francisco Thierry Oliveira Sousa    427340
