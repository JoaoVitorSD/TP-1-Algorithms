
# Definição do problema

Steven Jodds sofre de um transtorno peculiar: ele tem fobia a números ı́mpares. Felizmente, esse
problema não o impediu de se tornar um empresário de sucesso e viajar pelo paı́s inteiro para realizar reuniões com clientes. Infelizmente, Steve também tem medo de viajar de avião e precisa fazer todas as viagens de carro. Steve deseja criar um algoritmo para planejar melhor suas viagens. No entanto, devido à sua aversão a números ı́mpares, ele nunca conseguiu aprender a programar. Por isso, ele pediu a ajuda de um exı́mio programador – você – para ajudá-lo nessa tarefa. Steve quer criar um algoritmo que determine o menor caminho entre duas cidades, dado um grafo que representa a rede de cidades e estradas que interconectam a região. No entanto, seu algoritmo deve levar em consideração as peculiaridades de Steve:

1. Steve só viaja entre duas cidades adjacentes se a estrada que conecta as duas cidades tiver
comprimento par;
2. **O caminho traçado pelo algoritmo deve passar por um número par de estradas**.


# Formato da entrada esperada

O seu programa deverá processar um caso de teste em cada execução. A primeira linha de um
cenário de teste é composta de dois número inteiros N e A, representando respectivamente o número
de cidades (2 ≤ N ≤ 10000) e o número de estradas conectando pares de cidades (1 ≤ A ≤ 100000).
Cada uma das próximas A linhas descreve uma estrada entre duas cidades, representadas pelo
identificador de uma cidade de origem, um identificador de uma cidade de destino e o comprimento da
estrada que liga diretamente as respectivas cidades. Os dois identificadores e o comprimento da estrada
são representados por inteiros positivos, a saber X1 , X2 e D, os quais devem satisfazer as seguintes
condições: 1 ≤ X1 , X2 ≤ N , X1 ̸= X2 e 0 < D ≤ 10000. Pode-se assumir que: (1) todas as estradas
são de mão dupla; (2) a cidade de origem sempre recebe o identificador 1; e (3) a cidade de destino
sempre recebe o identificador N.

# Formato da saı́da esperada
Para cada caso de teste seu programa deve imprimir uma linha com o tamanho do caminho mı́nimo
satisfazendo as especificações do problema. Quando não existir tal caminho, o programa deve imprimir
−1.


