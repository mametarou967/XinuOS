# 方針

* uartの資料調査について
* uartとttyの違いについて
* Startupコードについて
* Makefileについて
* コンパイルオプションについて

## UARTに関するレジスタについて調べよう

ARM Cortex-A8のメモリマップ(Table 2-1. L3 Memory Map)を調べると以下のような記述がある。

![](images/UartRegister1.png)

ARM Cortex-A8ではメモリアドレス`0x44E09000`から開始4KBの領域がUART0のレジスタに割り当てられている。

UART Registerの詳細は以下の通り。

