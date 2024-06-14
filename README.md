# Trabalho-2-INO
# =====================================
# Documentação do Código Arduino
## versão: 1.0
## de: Alan M. Cornely
## Data: 13/06/2024
# =====================================

## Descrição
### Este código Arduino realiza a soma de dois números de 4 bits e exibe o resultado em pinos de saída digitais. O programa lê dois números de 4 bits a partir dos pinos de entrada digitais, realiza a soma bit a bit considerando o bit de transporte (carry bit) e, em seguida, escreve o resultado e o bit de transporte resultante nos pinos de saída.

### Variáveis Globais:
-- **int soma = 13;** 

É o Pino de entrada utilizado para ativar a operação de soma.

-- **int carryBit = 0;**

É o Bit de transporte inicializado como 0.

-- **int nib1a, nib1b, nib1c, nib1d = 0;**

É os Bits do primeiro número de 4 bits..

-- **int nib2a, nib2b, nib2c, nib2d = 0;**

É os Bits do segundo número de 4 bits..

-- **int res1a, res1b, res1c, res1d = 0;**

É o Bit do resultado da soma.

### Função setup()
Configura os pinos digitais como entrada ou saída. Sedo respectivamente input a entrada e output a saida.
```cpp
void setup(){
    pinMode(0, INPUT);
    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, INPUT);
}
```
### Função 'somaBit'
Realiza a soma de três bits, retornando o bit de resultado.

```cpp
Copiar código
int somaBit(int b1a, int b2a, int cBit){
    int bitResult = 0;
    if ((b1a ^ b2a) ^ cBit){
        bitResult = 1;
    } else {
        bitResult = 0;
    }
    return bitResult;
}
```
**Parâmetros:**

--int b1a - Primeiro bit de entrada.

--int b2a - Segundo bit de entrada.

--int cBit - Bit de transporte (carry bit).

**Retorno:**

--int - Bit de resultado da soma.

### Função 'somaCarryBit'

Calcula o novo bit de transporte após a soma de três bits.

```cpp
Copiar código
int somaCarryBit(int b1a, int b2a, int cBit){
    if ((b1a && b2a) || (b1a && cBit) || (b2a && cBit)){
        cBit = 1;
    } else {
        cBit = 0;
    }
    return cBit;
}
```
**Parâmetros:**
--int b1a - Primeiro bit de entrada.

--int b2a - Segundo bit de entrada.

--int cBit - Bit de transporte (carry bit).

**Retorno:**

--int - Novo bit de transporte.

###Função loop()

Lê os bits de entrada, realiza a soma se o pino de controle estiver ativado e escreve o resultado nos pinos de saída.

```cpp
Copiar código
void loop(){
    soma = digitalRead(13);
    nib1a = digitalRead(0);
    nib1b = digitalRead(1);
    nib1c = digitalRead(2);
    nib1d = digitalRead(3);
    nib2a = digitalRead(4);
    nib2b = digitalRead(5);
    nib2c = digitalRead(6);
    nib2d = digitalRead(7);

    if (soma == 1){
        carryBit = 0;
        res1a = somaBit(nib1a, nib2a, carryBit);
        carryBit = somaCarryBit(nib1a, nib2a, carryBit);
        res1b = somaBit(nib1b, nib2b, carryBit);
        carryBit = somaCarryBit(nib1b, nib2b, carryBit);
        res1c = somaBit(nib1c, nib2c, carryBit);
        carryBit = somaCarryBit(nib1c, nib2c, carryBit);
        res1d = somaBit(nib1d, nib2d, carryBit);
        carryBit = somaCarryBit(nib1d, nib2d, carryBit);
    }
    digitalWrite(8, res1a);
    digitalWrite(9, res1b);
    digitalWrite(10, res1c);
    digitalWrite(11, res1d);
    digitalWrite(12, carryBit);
}
```
**Operações:**

--Lê o estado do pino de controle (soma).

--Lê os bits dos dois números de 4 bits (nib1a a nib1d e nib2a a nib2d).

--Se o pino de controle estiver ativado (soma == 1), realiza a soma bit a bit, atualizando o bit de transporte.

--Escreve o resultado da soma nos pinos de saída (res1a a res1d e carryBit).
