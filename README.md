# 21a-emb-aps1

Embarcados - APS 1 - Musical!

Para maiores informações acesse:

https://insper.github.io/ComputacaoEmbarcada/APS-1-Musical/

Issues serão abertos neste repositório para guiar o desenvolvimento
da dupla. **Vocês não devem fechar os issues, apenas a equipe de professores!**, porém devem referenciar nos commits quando um issue 
foi concluído! Isso gerará um PR no classroom que será avaliado pela equipe.

## Documentação

TODO: Aualizar pinos

| Função  | PINO (ex: PA11) |
|---------|-----------------|
| BUZZER  |       PA4       |
| PAUSE   |  EXT4 --> PA19  |
| SELEÇÃO |  EXT9 --> PD28  |

O software foi estruturado usando o music.h como referencia onde 2 structs foram criados, o primeiro sendo a nota e o segundo sendo a musica, dentro da musica existe um ponteiro de ponteiros onde as notas estão salvas, a duracao total da musica, a  quantidade de notas e seu nome. 
Alem disso dentro do music.h se encontra as funções para criar e ultilizar os structs musicais. Para tocar a musica foi criado o buzzer.h que configura e contrla o buzzer para realizar a musica e para controlar e configurar os botões para mudar de musica e pausar a que está tocando foi criado buttons.h onde contem os callbacks para os botões e os getters para suas flags estão contidos. O led.h para cuidar do LED que pisca na frequencia da musica que é ultilizado pelo buzzer.h

### Imagem da montagem

![WhatsApp Image 2023-09-12 at 23 57 52](https://github.com/insper-classroom/23b-emb-aps-1-corsinarok/assets/53411412/c6e4ed80-fa1b-401b-8f34-56cdb775449e)

### Vídeo do projeto

https://youtu.be/U3MjCyRN1Ww

### Músicas e Direitos autorais

- [Super Mario Bros theme by Koji Kondo](https://musescore.com/user/2123/scores/2145)
- [Hedwig's theme fromn the Harry Potter Movies](https://musescore.com/user/3811306/scores/4906610)
- [Dart Vader theme (Imperial March) - Star wars](https://musescore.com/user/202909/scores/1141521)
