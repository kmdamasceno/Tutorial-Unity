### Tutorial UNITY - Ferramenta de testes unitários para C:

## Ferramentas necessárias:

- C/++ toolchain (VSCode)
- gcc (idealmente a versão mais atualizada)

## Passo a passo detalhado:

-Passo 1: Crie uma pasta nova. 

-Passo 2: Instale o Unity nessa pasta, usando o download no site ou o commando: git clone https://github.com/ThrowTheSwitch/Unity.git

-Passo 3: Copie a pasta "src", que é a única que iremos utilizar, e a coloque na sua pasta de escolha. Seu caminho deverá ficar: "../(pasta)/src"

-Passo 4: Já no seu código, escreva sua Main.h, que deverá ter as funções a serem testadas. Veja um exemplo:

```
int soma(int x, int y) { 
    return(x + y);
}

int areaQuadrado(int x, int y) 
{
    return (x*y);
}

int areaTriangulo(int x, int y) 
{
    return(x*y/2);
}

int areaTrapezio(int x, int y, int z)
{
    return((x+y)*z/2);
}

float areaCirculo(float x)
{
    return(3.14*x*x);
}
```

-Passo 5: Escreve agora seus testes. Idealmente seu arquivo deve-se chamar test.c. A documentação do Unity é muito boa, e o arquivo "Main.c" deste repositório mostra como deve ser feito. No nosso exemplo, utilizaremos apenas o TEST_ASSERT_EQUAL(), mas outras funções podem ser encontradas na documentação. Antes dos seus testes, não se esqueça do 

```
void setUp() {};
```

 e 
 
```
 void tearDown() {};
```

 assim como no arquivo exemplo neste repositório. Exemplo:
 
#include "src/unity.h"
#include "Main.h"

void setUp() {};
void tearDown() {};

void somaTest1() {
    TEST_ASSERT_EQUAL(soma(10, 15), 25);
}

void somaTest2() {
    TEST_ASSERT_EQUAL(soma(10, -15), -5);
}

void areaQuadradoTest() {
    TEST_ASSERT_EQUAL(areaQuadrado(2, 2), 4);
}

void areaTrianguloTest() {
    TEST_ASSERT_EQUAL(areaTriangulo(2, 2), 2);
}

void areaTrapezioTest() {
    TEST_ASSERT_EQUAL(areaTrapezio(2, 2, 2), 4);
}
```

Veja que tenho src/Unity.h como um header da minha função de testes. Logo, na mesma pasta que está sendo salvo meu arquivo test.c, precisa existir a pasta que copiamos do repositório do Unity. Atente-se a isso.

Após escrever suas funções de testes, crie o Main() da sua função de testes. Exemplo:

```
int main(void) {
   UNITY_BEGIN();
   RUN_TEST(somaTest1);
   RUN_TEST(somaTest2);
   RUN_TEST(areaQuadradoTest);
   RUN_TEST(areaTrianguloTest);
   RUN_TEST(areaTrapezioTest);
   RUN_TEST(areaCirculoTeste);
   UNITY_END();
}
```

Veja que todas são funções do unity.h. Se você não estiver com os caminhos bem sinalizados, o GCC não irá compilar este arquivo, trazendo dores de cabeça desnecessárias.

-Passo 6:

Após ter escrito o Main.h e o test.c, conferido todos os erros de sintaxe, e instalado o gcc, rode o comando:

```
gcc test.c src/unity.c -o test.exe
```

Isso fará com que o gcc compile o teste utlizando o Unity, criando um arquivo .exe que fará os testes. Erros comuns aqui envolvem suas variáveis de ambiente, e erros de versão do seu gcc. Tome cuidado com isso.

-Passo 7:

Após isso, basta apenas rodar o test.exe que foi gerado pelo gcc. O comando é:

```
./test.exe
```

Caso tudo tenha dado certo, seu terminal deverá imprimir um relatório parecido com este:

```
test.c:33:somaTest1:PASS
test.c:34:somaTest2:PASS
test.c:35:areaQuadradoTest:PASS
test.c:36:areaTrianguloTest:PASS
test.c:37:areaTrapezioTest:PASS
test.c:38:areaCirculoTeste:PASS

-----------------------
6 Tests 0 Failures 0 Ignored
OK
```

Mostrando quais testes passaram e quais falharam.

Sinta-se à vontade para se comunicar comigo para tirar dúvidas.
