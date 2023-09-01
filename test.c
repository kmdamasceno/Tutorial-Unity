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

void areaCirculoTeste() {
    TEST_ASSERT_EQUAL(areaCirculo(2), 12.56);
}

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